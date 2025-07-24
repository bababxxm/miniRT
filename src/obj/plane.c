/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:09:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/24 20:32:43 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_plane(t_ray ray, t_plane *plane, t_hit *hit)
{
	float		t;
	float		denom;
	t_vector	p0l0;
	t_vector	normalized;

	normalized = vec3_normalize(plane->normal);
	denom = vec3_dot(normalized, ray.direction);
	if (fabs(denom) < EPSILON)
		return (false);
	p0l0 = vec3_sub(plane->position, ray.origin);
	t = vec3_dot(p0l0, normalized) / denom;
	if (t < 0 || t > hit->t)
		return (false);
	hit->t = t;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	hit->normalized = normalized;
	hit->color = plane->color;
	hit->found = true;
	return (true);
}
