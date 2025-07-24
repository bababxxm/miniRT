/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:41:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/17 05:07:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	display_element(t_scene *scene)
{
	if (scene->ambient)
	{
		display_float("ambient->ratio", scene->ambient->ratio);
		display_color("ambient->color", scene->ambient->color);
	}
	if (scene->camera)
	{
		display_vector("camera->position", scene->camera->position);
		display_vector("camera->direction", scene->camera->direction);
		display_float("camera->fov", scene->camera->fov);
	}
	if (scene->light)
	{
		display_vector("light->positon", scene->light->positon);
		display_float("light->brightness", scene->light->brightness);
		display_color("light->color", scene->light->color);
	}
}

static void	display_sphere(t_sphere *sphere)
{
	display_vector("sphere->center", sphere->center);
	display_float("sphere->radius", sphere->radius);
	display_color("sphere->color", sphere->color);
}

static void	display_plane(t_plane *plane)
{
	display_vector("plane->position", plane->position);
	display_vector("plane->normal", plane->normal);
	display_color("plane->color", plane->color);
}

static void	display_cylinder(t_cylinder *cylinder)
{
	display_vector("cylinder->center", cylinder->center);
	display_vector("cylinder->axis", cylinder->axis);
	display_float("cylinder->radius", cylinder->radius);
	display_float("cylinder->height", cylinder->height);
	display_color("cylinder->color", cylinder->color);
}

void	display_info(t_scene *scene)
{
	t_object	*object;

	display_element(scene);
	object = scene->object;
	while (object)
	{
		if (object->type == SPHERE)
			display_sphere((t_sphere *)object);
		else if (object->type == PLANE)
			display_plane((t_plane *)object);
		else if (object->type == CYLINDER)
			display_cylinder((t_cylinder *)object);
		object = object->next;
	}
}
