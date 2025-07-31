/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:07:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/31 21:55:50 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	compute_shadow(t_ray shadow, float max_t, t_object *object)
{
	t_hit	hit;

	while (object)
	{
		hit.t = max_t;
		hit.found = false;
		if (object_hit(shadow, object, &hit))
		{
			if (hit.found && hit.t > EPSILON && hit.t < max_t)
				return (true);
		}
		object = object->next;
	}
	return (false);
}

bool	is_in_shadow(t_vector point, t_light *light, t_scene *scene)
{
	float		t;
	t_ray		shadow;
	t_vector	direction;

	direction = compute_light(light, point);
	t = vec3_length(direction);
	direction = vec3_normalize(direction);
	shadow.origin = vec3_add(point, vec3_mul(direction, 0));
	shadow.direction = direction;
	return (compute_shadow(shadow, t, scene->object));
}
