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
| `vec3_add`       | Adds two vectors                  | Move/translate points or directions        |
| `vec3_sub`       | Subtracts one vector from another | Compute directions or displacement vectors |
| `vec3_mul`       | Multiply vector by scalar         | Scale rays, move points                    |
| `vec3_div`       | Divide vector by scalar           | Normalize, shrink vector                   |
| `vec3_dot`       | Dot product                       | Lighting, angle checks, facing direction   |
| `vec3_cross`     | Cross product                     | Create orthogonal basis (camera setup)     |
| `vec3_length`    | Vector magnitude                  | Distance, normalization                    |
| `vec3_normalize` | Convert to unit vector            | All ray directions, lighting calculations  |
| `vec3_reflect`   | Reflect a vector about a normal   | Reflections, mirror surfaces               |

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
up = vec3(0, 0, 1);

// Initial guess for right (Y axis flipped)
right = vec3(0, -1, 0);

// Ensure camera direction is unit length
camera->direction = vec3_normalize(camera->direction);

// Calculate right vector using cross product
// Ex. cross((0, 0, 1), (0, -1, 0)) = (1, 0, 0)
right = vec3_cross(camera->direction, right);

// If guess was parallel to camera direction, use global up instead
if (vec3_length(right) < 1e-6)
	right = vec3_cross(camera->direction, up);

// Normalize the final right vector
camera->right = vec3_normalize(right);

// Calculate true up vector from right × direction
up = vec3_cross(camera->right, camera->direction);
// Ex. cross((1, 0, 0), (0, 0, 1)) = (0, 1, 0)

// Normalize the final up vector
camera->up = vec3_normalize(up);
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
t_vector right_offset = vec3_mul(camera->right, px * fov_adjust);
t_vector up_offset    = vec3_mul(camera->up, -py * fov_adjust); // Y flipped

// Sum all directions
t_vector direction = vec3_add(camera->direction, right_offset);
direction = vec3_add(direction, up_offset);

// Normalize for consistent direction
ray.direction = vec3_normalize(direction);
```

| Component      | Meaning                                     |
| -------------- | ------------------------------------------- |
| `right_offset` | Horizontal shift based on pixel X           |
| `up_offset`    | Vertical shift based on pixel Y (flipped)   |
| `normalize`    | Ensures ray has length = 1 (unit direction) |

---
