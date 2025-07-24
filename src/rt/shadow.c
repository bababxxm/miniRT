/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:07:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/17 02:40:24 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	compute_object(t_ray shadow, float max_t, t_object *object)
{
	t_hit	hit;

	hit.t = max_t;
	hit.found = false;
	if (object->type == SPHERE
		&& hit_sphere(shadow, (t_sphere *)object, &hit)
		&& hit.t > 0.001f && hit.t < max_t)
		return (true);
	if (object->type == CYLINDER
		&& hit_cylinder(shadow, (t_cylinder *)object, &hit)
		&& hit.t > 0.001f && hit.t < max_t)
		return (true);
	if (object->type == PLANE
		&& hit_plane(shadow, (t_plane *)object, &hit)
		&& hit.t > 0.001f && hit.t < max_t)
		return (true);
	return (false);
}

static bool	compute_shadow(t_ray shadow, float max_t, t_object *object)
{
	while (object)
	{
		if (compute_object(shadow, max_t, object))
			return (true);
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
	shadow.origin = vec3_add(point, vec3_mul(direction, 0.001f));
	shadow.direction = direction;
	return (compute_shadow(shadow, t, scene->object));
}
