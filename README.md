# 🌌 miniRT — A Simple Ray Tracer

This project is a minimal ray tracer that renders 3D scenes described in a `.rt` file.
It is built step by step, introducing key concepts in computer graphics such as vectors, rays, intersections, lighting, and shading.

---

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

---

### 🖥️ MLX42 Pixel Space → Normalized Device Coordinates (NDC)

MLX screen starts at (0, 0) in the top-left. For ray tracing, we remap this to center-based space:

```c
px = (2.0f * ((x + 0.5f) / WINX) - 1.0f) * aspect_ratio;
py = 1.0f - 2.0f * ((y + 0.5f) / WINY);
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

## 📸 Camera and Rays

The **camera** defines the viewpoint in the 3D scene.
It has:

* A position
* A direction vector (where it looks)
* A field of view (FOV)

### 🔭 FOV (Field of View)

FOV controls how wide the camera sees:

#### Wide FOV (90°)

Rays spread out more:

```
     ↖   ↑   ↗
      \  |  /
       \ | /
        \|/
        [•] → +Z (camera looks forward)
```

#### Narrow FOV (30°)

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

### Ray Generation

For each pixel, we generate a ray:

```
ray.origin = camera.position
ray.direction = normalize(pixel_position - camera.position)
```

The ray direction depends on the pixel's location on the image plane.

---

## 🧮 Vector Math Essentials

Ray tracing is built on vector operations:

* **Addition/Subtraction**: move points in space
* **Dot product**: measure angles, projection
* **Cross product**: build orthogonal axes
* **Normalization**: convert vector to unit length

These allow us to express geometry and lighting mathematically.

---

## 🎯 Ray-Object Intersection

We check if a ray hits an object in the scene.
If yes, we record:

* Intersection point
* Surface normal
* Object color
* Distance `t` along the ray

This is stored in a **hit record**.

---

### 🟠 Sphere Intersection

A sphere is defined by its **center** `C` and **radius** `r`.

#### 🟢 Equation

The ray equation is:

```
P(t) = O + tD
```

Where:

* `O` = ray origin
* `D` = ray direction (normalized)
* `t` = distance along the ray

Sphere equation:

```
‖P - C‖² = r²
```

Substitute ray:

```
‖O + tD - C‖² = r²
```

Expand to a quadratic in `t`:

```
a = D·D
b = 2 * D·(O - C)
c = (O - C)·(O - C) - r²
```

Solve the quadratic:

```
discriminant = b² - 4ac
```

#### 🟢 Handling Solutions

* If `discriminant < 0` → no intersection.
* If `discriminant ≥ 0` → compute roots:

```
t1 = (-b - sqrt(discriminant)) / (2a)
t2 = (-b + sqrt(discriminant)) / (2a)
```

* Choose **smallest positive `t`** → closest intersection in front of camera.

#### 🟢 Surface Normal

Once intersection `P = O + tD` is found:

```
N = normalize(P - C)
```

* `N` points outward from the sphere.
* Used for lighting calculations (Lambertian, Phong, reflections).

---

### 🟢 Plane Intersection

Plane equation:

```
dot(P - P₀, N) = 0
```

Where:

* `P₀` → point on plane
* `N` → normal
* `P = O + tD` → ray

Solving for `t`:

```
t = dot(P₀ - O, N) / dot(D, N)
```

⚠️ If denominator ≈ 0 → ray is parallel, no hit.
Use `EPSILON` to avoid instability.

---

### 🔵 Cylinder Intersection

A finite cylinder has two parts:

1. **Curved side** – the infinite cylindrical surface, clipped by height.
2. **Caps** – flat circular disks at the top and bottom.

#### 🟢 Curved Surface

Equation of an infinite cylinder with axis vector **v**, radius **r**, and center point **C**:

```
(P - C)² - ((P - C)·v)² = r²
```

Where **P = O + tD** is the ray point (origin O, direction D).

Expanding this gives a **quadratic equation** in `t`:

```
a·t² + b·t + c = 0
```

with coefficients:

```
a = D·D - (D·v)²
b = 2[(O - C)·D - ((O - C)·v)(D·v)]
c = (O - C)·(O - C) - ((O - C)·v)² - r²
```

Solve using the quadratic formula.
Check if intersection lies **between cylinder caps** (clamp along v-axis).

#### 🟢 Caps

Each cap is a **circle on a plane**.

1. Intersect ray with cap’s plane.
2. Check if intersection point lies within radius `r`.

#### 🟢 Choosing Intersection

* If side and caps both intersect → pick the **closest positive `t`**.
* If no valid intersection → ray misses the cylinder.

---

### 🪞 Surface Normals

Normals are unit vectors used in shading:

* **Sphere**:

  ```
  N = normalize(P - center)
  ```

* **Plane**:
  Constant `N` (normalized at parse time).

* **Cylinder**:

  * **Side**: subtract projection onto axis:

    ```
    N = normalize((P - C) - ((P - C)·v) v)
    ```
  * **Cap**: normal is just `±v` depending on which cap.

---

## 💡 Lighting Model (Lambertian)

We use **Lambert’s cosine law** for diffuse reflection.

```c
light_dir = normalize(light.position - hit.point);
diff = max(dot(hit.normalized, light_dir), 0.0);
```

Final color:

```
color = ambient + (diffuse_intensity * object_color * light_color)
```

* Ambient → constant scene brightness
* Diffuse → depends on angle between light and surface

---

## 👤 Shadow Rays

To compute shadows:

1. From the hit point, cast a ray toward the light
2. If it hits another object before the light → shadow

```c
shadow_ray.origin = hit.point + hit.normal * BIAS;
shadow_ray.direction = normalize(light.position - hit.point);
```

* `BIAS` prevents **shadow acne** (self-shadowing)
* If blocked, ignore diffuse contribution

---

## 📏 EPSILON — What is it?

`EPSILON` is a tiny constant (e.g. `1e-6`).

Used to:

* Avoid division by near-zero values
* Offset ray origin slightly
* Compare floats safely

Example:

```c
if (fabs(value) < EPSILON)
    value = 0.0;
```

---
