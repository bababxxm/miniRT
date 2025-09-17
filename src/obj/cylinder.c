/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:09:01 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/10 15:11:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	cylinder_normal(t_vector axis,
				t_cylinder *cylinder, t_vector point)
{
	t_vector	tmp;
	t_vector	projection;
	t_vector	normal;

	tmp = sub(point, cylinder->point);
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

	oc = sub(ray.origin, cylinder->point);
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
	proj = dot(sub(point, cylinder->point), axis);
	if (proj < 0 || proj > cylinder->height)
		return (false);
	hit->t = t;
	hit->point = point;
	hit->normal = cylinder_normal(axis, cylinder, point);
	hit->color = cylinder->color;
	hit->found = true;
	return (true);
}

static bool	hit_cylinder_cap(t_ray ray, t_cap cap, t_hit *hit)
{
	float		t;
	float		dist;
	t_vector	point;

	if (!intersect_plane(ray, cap.axis, cap.point, &t))
		return (false);
	point = add(ray.origin, mul(ray.direction, t));
	dist = length(sub(point, cap.point));
	if (dist > cap.radius || t <= 0 || t >= hit->t)
		return (false);
	hit->t = t;
	hit->point = point;
	if (dot(ray.direction, cap.axis) > EPSILON)
		hit->normal = mul(cap.axis, -1);
	else
		hit->normal = cap.axis;
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
	top = create_cap(cylinder, axis, cylinder->point);
	bottom = create_cap(cylinder, axis, add(cylinder->point,
				mul(axis, cylinder->height)));
	top.hit = hit_cylinder_cap(ray, top, hit);
	bottom.hit = hit_cylinder_cap(ray, bottom, hit);
	return (top.hit || bottom.hit);
}
