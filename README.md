# miniRT – Ray Tracer

## 📐 Coordinate System

```
 +Y (Up)
   ↑
   |
   |
   •------→ +X (Right)
  /
 /
+Z (Into the Screen)
```

+X → Right
+Y → Up
+Z → Forward (away from the viewer)

---

## 🧮 Vector Utility Functions

| Function         | Description                       | Use in Ray Tracing                         |
| ---------------- | --------------------------------- | ------------------------------------------ |
| `add`            | Adds two vectors                  | Move/translate points or directions        |
| `sub`            | Subtracts one vector from another | Compute directions or displacement vectors |
| `mul`            | Multiply vector by scalar         | Scale rays, move points                    |
| `div`            | Divide vector by scalar           | Normalize, shrink vector                   |
| `dot`            | Dot product                       | Lighting, angle checks, facing direction   |
| `cross`          | Cross product                     | Create orthogonal basis (camera setup)     |
| `length`         | Vector magnitude                  | Distance, normalization                    |
| `normalize`      | Convert to unit vector            | All ray directions, lighting calculations  |

---

## ✳️ Why Normalize Vectors?

Normalizing a vector means converting it to a unit vector—a vector that points in the same direction but has a length (magnitude) of exactly 1.

| Without Normalization        | With Normalization         |
| ---------------------------- | -------------------------- |
| Lighting looks wrong         | Lighting behaves correctly |
| Ray distances are distorted  | `t` is actual distance     |
| Geometry tests fail randomly | Geometry is accurate       |
| Different resolution         | Consistent rendering       |

We normalize direction vectors to remove scale and ensure consistent, accurate, and physically correct rendering across the entire ray tracing pipeline.

---

## 🎥 Camera Setup

The camera orientation is defined using three perpendicular vectors:

```
             up (0, 1, 0)
               ↑
               |
               |
               |
 right (1, 0, 0) ----->  camera
              /
             /
   direction (0, 0, -1)
```

```c
// Global up vector (Z axis)
up = vector(0, 0, 1);

// Initial guess for right (Y axis flipped)
right = vector(0, -1, 0);

// Ensure camera direction is unit length
camera->direction = normalize(camera->direction);

// Calculate right vector using cross product
// Ex. cross((0, 0, 1), (0, -1, 0)) = (1, 0, 0)
right = cross(camera->direction, right);

// If guess was parallel to camera direction, use global up instead
if (length(right) < 1e-6)
	right = cross(camera->direction, up);

// Normalize the final right vector
camera->right = normalize(right);

// Calculate true up vector from right × direction
up = cross(camera->right, camera->direction);
// Ex. cross((1, 0, 0), (0, 0, 1)) = (0, 1, 0)

// Normalize the final up vector
camera->up = normalize(up);
```

* `direction`: where the camera is looking
* `right`: local horizontal axis (left-right)
* `up`: local vertical axis (up-down)

---

## 🖥️ MLX42 Pixel Space → Normalized Device Coordinates (NDC)

MLX screen starts at (0, 0) in the top-left. For ray tracing, we remap this to center-based space:

```c
// Convert screen (x, y) to NDC [-1, 1]
float px = (2.0f * ((x + 0.5f) / WINX) - 1.0f) * aspect_ratio;
float py = 1.0f - 2.0f * ((y + 0.5f) / WINY);
```

| Variable       | Meaning                          |
| -------------- | -------------------------------- |
| `+0.5`         | Centers the ray within the pixel |
| `WINX`, `WINY` | Screen resolution                |
| `aspect_ratio` | `WINX / WINY`                    |

---

### 🖥️ Screen Space (800x600)

```
 (0,0)                     (400,0)                      (799,0)
  top-left               top-center                 top-right
    +------------------------+-------------------------+
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    +------------------------+-------------------------+
 (0,599)                 (400,599)                   (799,599)
 bottom-left            bottom-center              bottom-right
```

### 🔄 Mapped to NDC Space

```
 (-aspect,+1)             (0,+1)                   (+aspect,+1)
    top-left            top-center                 top-right
    +------------------------+-------------------------+
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    |                        |                         |
    +------------------------+-------------------------+
 (-aspect,-1)              (0,-1)                 (+aspect,-1)
  bottom-left         bottom-center              bottom-right
```

---

## 🔭 FOV (Field of View)

FOV controls how wide the camera sees:

### Wide FOV (90°)

Rays spread out more:

```
     ↖   ↑   ↗
      \  |  /
       \ | /
        \|/
        [•] → +Z (camera looks forward)
```

### Narrow FOV (30°)

Rays are more straight:

```
        ↑
       ↑↑↑
        |
        |
       [•] → +Z (camera looks forward)
```

Use `fov_adjust` to scale horizontal and vertical ray offsets:

```c
float fov_adjust = tanf((camera->fov * 0.5f) * (PI / 180.0f));
```

---

## 📡 Ray Generation per Pixel

A specific pixel on the image plane from the camera's point of view:

We start with `camera->direction` (center of the screen), then:
➕ Add `right_offset` → shifts ray left/right
➕ Add `up_offset` → shifts ray up/down

```c
// Ray origin is camera position
ray.origin = camera->position;

// Offset from camera direction
t_vector right_offset = mul(camera->right, px * fov_adjust);
t_vector up_offset    = mul(camera->up, -py * fov_adjust); // Y flipped

// Sum all directions
t_vector direction = add(camera->direction, right_offset);
direction = add(direction, up_offset);

// Normalize for consistent direction
ray.direction = normalize(direction);
```

| Component      | Meaning                                     |
| -------------- | ------------------------------------------- |
| `right_offset` | Horizontal shift based on pixel X           |
| `up_offset`    | Vertical shift based on pixel Y (flipped)   |
| `normalize`    | Ensures ray has length = 1 (unit direction) |

---

```c
t_rgb	trace_ray(t_ray ray, t_scene *scene)
{
	t_hit		hit;
	t_hit		closest;
	t_object	*object;
	t_rgb		background;

	hit.t = __FLT_MAX__;
	closest.found = false;
	object = scene->object;
	background = rgb(48, 46, 46);
	while (object)
	{
		if (object_hit(ray, object, &hit))
		{
			if (hit.t < __FLT_MAX__)
				closest = hit;
		}
		object = object->next;
	}
	if (closest.found)
		return (trace_light(&closest, scene));
	return (background);
}
```


```c
bool	hit_plane(t_ray ray, t_plane *plane, t_hit *hit)
{
	float		t;
	float		denom;
	t_vector	p0l0;
	t_vector	normal;

	normal = normalize(plane->normal);
	denom = dot(normal, ray.direction);
	if (fabs(denom) < EPSILON)
		return (false);
	p0l0 = sub(plane->position, ray.origin);
	t = dot(p0l0, normal) / denom;
	if (t < EPSILON || t > hit->t)
		return (false);
	if (denom > 0)
		normal = mul(normal, -1);
	hit->t = t;
	hit->point = add(ray.origin, mul(ray.direction, t));
	hit->normalized = normal;
	hit->color = plane->color;
	hit->found = true;
	return (true);
}
```

```c
static float	compute_sphere(t_ray ray, t_sphere *sphere, t_hit *hit)
{
	float		t;
	t_vector	oc;

	oc = sub(ray.origin, sphere->center);
	t = quadratic_equation(
			dot(ray.direction, ray.direction),
			2.0f * dot(oc, ray.direction),
			dot(oc, oc) - square(sphere->radius), hit
			);
	return (t);
}

bool	hit_sphere(t_ray ray, t_sphere *sphere, t_hit *hit)
{
	float	t;

	t = compute_sphere(ray, sphere, hit);
	if (t < 0)
		return (false);
	hit->t = t;
	hit->point = add(ray.origin, mul(ray.direction, t));
	hit->normalized = normalize(sub(hit->point, sphere->center));
	hit->color = sphere->color;
	hit->found = true;
	return (true);
}
```

```c
static t_vector	cylinder_normal(t_vector axis,
				t_cylinder *cylinder, t_vector point)
{
	t_vector	tmp;
	t_vector	projection;
	t_vector	normal;

	tmp = sub(point, cylinder->center);
	projection = mul(axis, dot(tmp, axis));
	normal = sub(tmp, projection);
	return (normalize(normal));
}

static float	compute_cylinder_body(t_ray ray, t_vector axis,
				t_cylinder *cylinder, t_hit *hit)
{
	float		t;
	float		d_dot;
	float		oc_dot;
	t_vector	oc;

	oc = sub(ray.origin, cylinder->center);
	d_dot = dot(ray.direction, axis);
	oc_dot = dot(oc, axis);
	t = quadratic_equation(
			dot(ray.direction, ray.direction) - square(d_dot),
			2.0f * (dot(ray.direction, oc) - d_dot * oc_dot),
			dot(oc, oc) - square(oc_dot) - square(cylinder->radius), hit
			);
	return (t);
}

static bool	hit_cylinder_body(t_ray ray, t_vector axis,
			t_cylinder *cylinder, t_hit *hit)
{
	float		t;
	float		proj;
	t_vector	point;

	t = compute_cylinder_body(ray, axis, cylinder, hit);
	if (t <= 0 || t >= hit->t)
		return (false);
	point = add(ray.origin, mul(ray.direction, t));
	proj = dot(sub(point, cylinder->center), axis);
	if (proj < 0 || proj > cylinder->height)
		return (false);
	hit->t = t;
	hit->point = point;
	hit->normalized = cylinder_normal(axis, cylinder, point);
	hit->color = cylinder->color;
	hit->found = true;
	return (true);
}

static bool	hit_cylinder_cap(t_ray ray, t_cap cap, t_hit *hit)
{
	float		t;
	float		dist;
	t_vector	point;

	if (!intersect_plane(ray, cap.axis, cap.center, &t))
		return (false);
	point = add(ray.origin, mul(ray.direction, t));
	dist = length(sub(point, cap.center));
	if (dist > cap.radius || t <= 0 || t >= hit->t)
		return (false);
	hit->t = t;
	hit->point = point;
	if (dot(ray.direction, cap.axis) > EPSILON)
		hit->normalized = mul(cap.axis, -1);
	else
		hit->normalized = cap.axis;
	hit->color = cap.color;
	hit->found = true;
	return (true);
}

bool	hit_cylinder(t_ray ray, t_cylinder *cylinder, t_hit *hit)
{
	t_cap		top;
	t_cap		bottom;
	t_vector	axis;

	axis = normalize(cylinder->axis);
	if (hit_cylinder_body(ray, axis, cylinder, hit))
		return (true);
	top = create_cap(cylinder, axis, cylinder->center);
	bottom = create_cap(cylinder, axis, add(cylinder->center,
				mul(axis, cylinder->height)));
	top.hit = hit_cylinder_cap(ray, top, hit);
	bottom.hit = hit_cylinder_cap(ray, bottom, hit);
	return (top.hit || bottom.hit);
}
```

```c
static t_rgb	trace_light(t_hit *hit, t_scene *scene)
{
	t_rgb		color;
	t_rgb		diffuse;
	t_light		*light;
	t_ambient	*ambient;

	light = scene->light;
	ambient = scene->ambient;
	color = compute_ambient(hit->color, ambient);
	while (light)
	{
		if (!is_in_shadow(hit->point, light, scene))
		{
			diffuse = compute_diffuse(hit, light);
			color.r = color.r + diffuse.r;
			color.g = color.g + diffuse.g;
			color.b = color.b + diffuse.b;
		}
		light = light->next;
	}
	return (clamp(color));
}
```

```c
t_rgb	clamp(t_rgb color)
{
	color.r = fminf(fmaxf(color.r, 0.0f), 255.0f);
	color.g = fminf(fmaxf(color.g, 0.0f), 255.0f);
	color.b = fminf(fmaxf(color.b, 0.0f), 255.0f);
	return (color);
}

t_rgb	compute_ambient(t_rgb hit, t_ambient *ambient)
{
	t_rgb	color;

	color.r = hit.r * ambient->color.r / 255.0f * ambient->ratio;
	color.g = hit.g * ambient->color.r / 255.0f * ambient->ratio;
	color.b = hit.b * ambient->color.r / 255.0f * ambient->ratio;
	return (color);
}

t_rgb	compute_diffuse(t_hit *hit, t_light *light)
{
	float		point;
	t_rgb		color;
	float		intensity;
	t_vector	direction;

	direction = sub(light->positon, hit->point);
	direction = normalize(direction);
	point = dot(hit->normalized, direction);
	if (point < 0)
		point = 0;
	intensity = light->brightness * point;
	color.r = hit->color.r * light->color.r / 255.0f * intensity;
	color.g = hit->color.g * light->color.g / 255.0f * intensity;
	color.b = hit->color.b * light->color.b / 255.0f * intensity;
	return (color);
}
```

```c
static bool	compute_shadow(t_ray shadow, float max_t, t_object *object)
{
	t_hit	hit;

	while (object)
	{
		hit.t = max_t;
		hit.found = false;
		if (object_hit(shadow, object, &hit))
		{
			if (hit.t > EPSILON && hit.t < max_t)
				return (true);
		}
		object = object->next;
	}
	return (false);
}

bool	is_in_shadow(t_vector point, t_light *light, t_scene *scene)
{
	float		t;
	t_ray		shadow;
	t_vector	direction;

	direction = sub(light->positon, point);
	direction = normalize(direction);
	t = length(direction);
	direction = normalize(direction);
	shadow.origin = add(point, mul(direction, 0));
	shadow.direction = direction;
	return (compute_shadow(shadow, t, scene->object));
}
```

