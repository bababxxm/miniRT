/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:11:57 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/15 20:49:53 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	compute_ambient(t_hit *hit, t_ambient *ambient)
{
	t_rgb	color;

	color = modulate_color(hit->color, ambient->color);
	return (scale_color(color, ambient->ratio));
}

t_rgb	compute_diffuse(t_hit *hit, t_light *light)
{
	t_rgb		color;
	float		dotnl;
	float		intensity;
	t_vector	direction;

	direction = normalize(sub(light->point, hit->point));
	dotnl = fmaxf(dot(hit->normal, direction), 0.0f);
	intensity = light->brightness * dotnl;
	color = modulate_color(hit->color, light->color);
	return (scale_color(color, intensity));
}

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
	float		t;
	t_vector	u;
	t_ray		shadow;

	u = sub(light->point, hit->point);
	t = length(u);
	shadow.origin = add(hit->point, mul(hit->normal, EPSILON));
	shadow.direction = normalize(u);
	return (compute_shadow(shadow, t, scene->object));
}
