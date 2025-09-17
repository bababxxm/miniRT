/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:09:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/10 15:15:51 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_plane(t_ray ray, t_plane *plane, t_hit *hit)
{
	float		t;
	float		denom;
	float		numer;
	t_vector	normal;

	normal = normalize(plane->normal);
	denom = dot(ray.direction, normal);
	if (fabs(denom) < EPSILON)
		return (false);
	numer = dot(sub(plane->point, ray.origin), normal);
	t = numer / denom;
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
