/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:09:01 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/28 19:48:13 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersect_plane(t_ray ray, t_vector point, t_vector normal, float *t)
{
	float	denom;
	float	numer;

	denom = vec3_dot(ray.direction, normal);
	if (fabs(denom) < 1e-6)
		return (false);
	numer = vec3_dot(vec3_sub(point, ray.origin), normal);
	*t = numer / denom;
	return (*t > 0);
}

static t_vector	cylinder_normal(t_vector axis, t_cylinder *cylinder, t_vector point)
{
	t_vector	tmp;
	t_vector	projection;
	t_vector	normal;

	tmp = vec3_sub(point, cylinder->center);
	projection = vec3_mul(axis, vec3_dot(tmp, axis));
	normal = vec3_sub(tmp, projection);
	return (vec3_normalize(normal));
}

static float	compute_cylinder(t_vector axis, t_ray ray,
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

bool	hit_cylinder_caps(t_ray ray, t_cylinder *cylinder, t_hit *hit)
{
	t_vector	axis;
	t_vector	top;
	t_vector	bottom;
	float		t;
	t_vector	p;
	float		dist;

	axis = vec3_normalize(cylinder->axis);
	bottom = cylinder->center;
	top = vec3_add(cylinder->center, vec3_mul(axis, cylinder->height));
	if (intersect_plane(ray, bottom, axis, &t))
	{
		p = vec3_add(ray.origin, vec3_mul(ray.direction, t));
		dist = vec3_length(vec3_sub(p, bottom));
		if (dist <= cylinder->radius && t > 0 && t < hit->t)
		{
			hit->t = t;
			hit->point = p;
			hit->normalized = vec3_mul(axis, -1);
			hit->color = cylinder->color;
			hit->found = true;
		}
	}
	if (intersect_plane(ray, top, axis, &t))
	{
		p = vec3_add(ray.origin, vec3_mul(ray.direction, t));
		dist = vec3_length(vec3_sub(p, top));
		if (dist <= cylinder->radius && t > 0 && t < hit->t)
		{
			hit->t = t;
			hit->point = p;
			hit->normalized = axis;
			hit->color = cylinder->color;
			hit->found = true;
		}
	}
	return (hit->found);
}

bool	hit_cylinder(t_ray ray, t_cylinder *cylinder, t_hit *hit)
{
	t_vector	axis;
	float		t;
	float		proj;
	t_vector	point;

	axis = vec3_normalize(cylinder->axis);
	t = compute_cylinder(axis, ray, cylinder, hit);
	if (t > 0 && t < hit->t)
	{
		point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
		proj = vec3_dot(vec3_sub(point, cylinder->center), axis);
		if (proj >= 0 && proj <= cylinder->height)
		{
			hit->t = t;
			hit->point = point;
			hit->normalized = cylinder_normal(axis, cylinder, point);
			hit->color = cylinder->color;
			hit->found = true;
			return (true);
		}
	}
	return hit_cylinder_caps(ray, cylinder, hit);
}

// static float	compute_cylinder(t_vector axis, t_ray ray,
// 				t_cylinder *cylinder, t_hit *hit)
// {
// 	float		t;
// 	float		d_dot;
// 	float		oc_dot;
// 	t_vector	oc;

// 	oc = vec3_sub(ray.origin, cylinder->center);
// 	d_dot = vec3_dot(ray.direction, axis);
// 	oc_dot = vec3_dot(oc, axis);
// 	t = quadratic_equation(
// 			vec3_dot(ray.direction, ray.direction) - square(d_dot),
// 			2.0f * (vec3_dot(ray.direction, oc) - d_dot * oc_dot),
// 			vec3_dot(oc, oc) - square(oc_dot) - square(cylinder->radius), hit
// 			);
// 	return (t);
// }

// static t_vector	cylinder_normal(t_vector axis, t_cylinder *cylinder, t_hit *hit)
// {
// 	t_vector	tmp;
// 	t_vector	projection;
// 	t_vector	normal;

// 	tmp = vec3_sub(hit->point, cylinder->center);
// 	projection = vec3_mul(axis, vec3_dot(tmp, axis));
// 	normal = vec3_sub(tmp, projection);
// 	return (vec3_normalize(normal));
// }

// bool	hit_cylinder(t_ray ray, t_cylinder *cylinder, t_hit *hit)
// {
// 	float		t;
// 	float		proj;
// 	t_vector	axis;

// 	axis = vec3_normalize(cylinder->axis);
// 	t = compute_cylinder(axis, ray, cylinder, hit);
// 	if (t < 0)
// 		return (false);
// 	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
// 	proj = vec3_dot(vec3_sub(hit->point, cylinder->center), axis);
// 	if (proj < 0 || proj > cylinder->height)
// 		return (false);
// 	hit->t = t;
// 	hit->normalized = cylinder_normal(axis, cylinder, hit);
// 	hit->color = cylinder->color;
// 	hit->found = true;
// 	return (true);
// }
