/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:07:57 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/10 15:11:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	compute_sphere(t_ray ray, t_sphere *sphere, t_hit *hit)
{
	float		t;
	t_vector	oc;

	oc = sub(ray.origin, sphere->point);
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
	hit->normal = normalize(sub(hit->point, sphere->point));
	hit->color = sphere->color;
	hit->found = true;
	return (true);
}
