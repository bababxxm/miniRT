/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:07:57 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/17 21:40:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	compute_sphere(t_ray ray, t_sphere *sphere, t_hit *hit)
{
	float		t;
	t_vector	oc;

	oc = vec3_sub(ray.origin, sphere->center);
	t = quadratic_equation(
			vec3_dot(ray.direction, ray.direction),
			2.0f * vec3_dot(oc, ray.direction),
			vec3_dot(oc, oc) - square(sphere->radius), hit
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
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	hit->normalized = vec3_normalize(vec3_sub(hit->point, sphere->center));
	hit->color = sphere->color;
	hit->found = true;
	return (true);
}
