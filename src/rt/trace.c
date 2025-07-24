/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:11:21 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/24 20:31:06 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	object_hit(t_ray ray, t_object *object, t_hit *hit)
{
	if (object->type == PLANE)
		return (hit_plane(ray, (t_plane *)object, hit));
	else if (object->type == SPHERE)
		return (hit_sphere(ray, (t_sphere *)object, hit));
	else if (object->type == CYLINDER)
		return (hit_cylinder(ray, (t_cylinder *)object, hit));
	return (false);
}

static t_rgb	trace_light(t_hit *hit, t_scene *scene)
{
	t_rgb		color;
	t_rgb		diffuse;
	t_light		*light;
	t_ambient	*ambient;

	light = scene->light;
	ambient = scene->ambient;
	color = compute_ambient(hit->color, ambient);
	while (light)
	{
		if (!is_in_shadow(hit->point, light, scene))
		{
			diffuse = compute_diffuse(hit, light);
			color.r = color.r + diffuse.r;
			color.g = color.g + diffuse.g;
			color.b = color.b + diffuse.b;
		}
		light = light->next;
	}
	return (clamp(color));
}

t_rgb	trace_ray(t_ray ray, t_scene *scene)
{
	t_hit		hit;
	t_hit		closest;
	t_object	*object;
	t_rgb		background;

	hit.t = __FLT_MAX__;
	closest.found = false;
	object = scene->object;
	background = rgb(48, 46, 46);
	while (object)
	{
		if (object_hit(ray, object, &hit))
		{
			if (hit.t < __FLT_MAX__)
				closest = hit;
		}
		object = object->next;
	}
	if (closest.found)
		return (trace_light(&closest, scene));
	return (background);
}
