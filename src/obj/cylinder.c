/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:09:01 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/31 23:04:36 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	cylinder_normal(t_vector axis,
				t_cylinder *cylinder, t_vector point)
{
	t_vector	tmp;
	t_vector	projection;
	t_vector	normal;

	tmp = vec3_sub(point, cylinder->center);
	projection = vec3_mul(axis, vec3_dot(tmp, axis));
	normal = vec3_sub(tmp, projection);
	return (vec3_normalize(normal));
}

static float	compute_cylinder_body(t_ray ray, t_vector axis,
				t_cylinder *cylinder, t_hit *hit)
{
	float		t;
	float		d_dot;
	float		oc_dot;
	t_vector	oc;

	oc = vec3_sub(ray.origin, cylinder->center);
	d_dot = vec3_dot(ray.direction, axis);
	oc_dot = vec3_dot(oc, axis);
	t = quadratic_equation(
			vec3_dot(ray.direction, ray.direction) - square(d_dot),
			2.0f * (vec3_dot(ray.direction, oc) - d_dot * oc_dot),
			vec3_dot(oc, oc) - square(oc_dot) - square(cylinder->radius), hit
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
	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	proj = vec3_dot(vec3_sub(point, cylinder->center), axis);
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
	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	dist = vec3_length(vec3_sub(point, cap.center));
	if (dist > cap.radius || t <= 0 || t >= hit->t)
		return (false);
	hit->t = t;
	hit->point = point;
	if (vec3_dot(ray.direction, cap.axis) > EPSILON)
		hit->normalized = vec3_mul(cap.axis, -1);
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

	axis = vec3_normalize(cylinder->axis);
	if (hit_cylinder_body(ray, axis, cylinder, hit))
		return (true);
	top = create_cap(cylinder, axis, cylinder->center);
	bottom = create_cap(cylinder, axis, vec3_add(cylinder->center,
				vec3_mul(axis, cylinder->height)));
	top.hit = hit_cylinder_cap(ray, top, hit);
	bottom.hit = hit_cylinder_cap(ray, bottom, hit);
	return (top.hit || bottom.hit);
}
