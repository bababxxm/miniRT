/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:09:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/04 02:38:15 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (denom > EPSILON)
		normal = mul(normal, -1);
	hit->t = t;
	hit->point = add(ray.origin, mul(ray.direction, t));
	hit->normal = normal;
	hit->color = plane->color;
	hit->found = true;
	return (true);
}
