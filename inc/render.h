/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:35:30 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/04 21:47:37 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define PI 3.141592f

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_hit
{
	float		t;
	t_vector	point;
	t_vector	normalized;
	t_rgb		color;
	bool		found;
}	t_hit;

float		square(float x);

int			put_pixel(t_rgb color);
t_rgb		rgb(int r, int g, int b);

t_vector	vector(float x, float y, float z);
float		dot(t_vector u, t_vector v);
t_vector	add(t_vector u, t_vector v);
t_vector	sub(t_vector u, t_vector v);
t_vector	mul(t_vector u, float f);
t_vector	normalize(t_vector v);
float		length(t_vector u);
t_vector	cross(t_vector u, t_vector v);

t_rgb		clamp(t_rgb color);
t_rgb		compute_ambient(t_rgb hit, t_ambient *ambient);
t_rgb		compute_diffuse(t_hit *hit, t_light *light);
float		quadratic_equation(float a, float b, float c, t_hit *hit);
bool		object_hit(t_ray ray, t_object *object, t_hit *hit);
bool		is_in_shadow(t_vector point, t_light *light, t_scene *scene);

void		setup_camera(t_camera *camera);
t_ray		generate_ray(int x, int y, t_camera *camera);
t_rgb		trace_ray(t_ray ray, t_scene *scene);

bool		hit_plane(t_ray ray, t_plane *plane, t_hit *hit);
bool		hit_sphere(t_ray ray, t_sphere *sphere, t_hit *hit);
bool		hit_cylinder(t_ray ray, t_cylinder *cylinder, t_hit *hit);

t_cap		create_cap(t_cylinder *cylinder, t_vector axis, t_vector center);
bool		intersect_plane(t_ray ray, t_vector normal,
				t_vector point, float *t);

#endif