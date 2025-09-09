/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:07:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/04 03:00:17 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	compute_shadow(t_ray shadow, float max_t, t_object *object)
{
	t_hit	hit;

	while (object)
	{
		hit.t = max_t;
		hit.found = false;
		if (object_hit(shadow, object, &hit))
		{
			if (hit.t > EPSILON && hit.t < max_t)
				return (true);
		}
		object = object->next;
	}
	return (false);
}

bool	is_in_shadow(t_hit *hit, t_light *light, t_scene *scene)
{
	t_vector	u;
	float		t;
	t_ray		shadow;

	u = sub(light->positon, hit->point);
	t = length(u);
	shadow.origin = add(hit->point, mul(hit->normal, EPSILON));
	shadow.direction = normalize(u);
	return (compute_shadow(shadow, t, scene->object));
}
