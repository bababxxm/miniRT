/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:09:01 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/22 00:48:32 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

static t_vector	cylinder_normal(t_vector axis, t_cylinder *cylinder, t_hit *hit)
{
	t_vector	tmp;
	t_vector	projection;
	t_vector	normal;

	tmp = vec3_sub(hit->point, cylinder->center);
	projection = vec3_mul(axis, vec3_dot(tmp, axis));
	normal = vec3_sub(tmp, projection);
	return (vec3_normalize(normal));
}

bool	hit_cylinder(t_ray ray, t_cylinder *cylinder, t_hit *hit)
{
	float		t;
	float		proj;
	t_vector	axis;

	axis = vec3_normalize(cylinder->axis);
	t = compute_cylinder(axis, ray, cylinder, hit);
	if (t < 0)
		return (false);
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	proj = vec3_dot(vec3_sub(hit->point, cylinder->center), axis);
	if (proj < 0 || proj > cylinder->height)
		return (false);
	hit->t = t;
	hit->normalized = cylinder_normal(axis, cylinder, hit);
	hit->color = cylinder->color;
	hit->found = true;
	return (true);
}
