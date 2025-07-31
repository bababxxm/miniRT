/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:41:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/01 01:19:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	display_element(t_scene *scene)
{
	if (scene->ambient)
	{
		printf("Ambient Light:\n");
		display_float("    Ratio", scene->ambient->ratio);
		display_color("    Color", scene->ambient->color);
		printf("\n");
	}
	if (scene->camera)
	{
		printf("Camera:\n");
		display_vector("    Position", scene->camera->position);
		display_vector("    Direction", scene->camera->direction);
		display_float("    FOV", scene->camera->fov);
		printf("\n");
	}
	if (scene->light)
	{
		printf("Light:\n");
		display_vector("    Position", scene->light->positon);
		display_float("    Brightness", scene->light->brightness);
		display_color("    Color", scene->light->color);
		printf("\n");
	}
}

static void	display_sphere(t_sphere *sphere, int id)
{
	if (id == 1)
		printf("Sphere(s):\n");
	printf("    [%d]\n", id);
	display_vector("    Center", sphere->center);
	display_float("    Radius", sphere->radius);
	display_color("    Color", sphere->color);
	printf("\n");
}

static void	display_plane(t_plane *plane, int id)
{
	if (id == 1)
		printf("Plane(s):\n");
	printf("    [%d]\n", id);
	display_vector("    Position", plane->position);
	display_vector("    Normal", plane->normal);
	display_color("    Color", plane->color);
	printf("\n");
}

static void	display_cylinder(t_cylinder *cylinder, int id)
{
	if (id == 1)
		printf("Cylinder(s):\n");
	printf("    [%d]\n", id);
	display_vector("    Center", cylinder->center);
	display_vector("    Axis", cylinder->axis);
	display_float("    Radius", cylinder->radius);
	display_float("    Height", cylinder->height);
	display_color("    Color", cylinder->color);
	printf("\n");
}

void	display_info(t_scene *scene)
{
	int			sphere;
	int			plane;
	int			cylinder;
	t_object	*object;

	sphere = 1;
	plane = 1;
	cylinder = 1;
	display_element(scene);
	object = scene->object;
	while (object)
	{
		if (object->type == SPHERE)
			display_sphere((t_sphere *)object, sphere++);
		else if (object->type == PLANE)
			display_plane((t_plane *)object, plane++);
		else if (object->type == CYLINDER)
			display_cylinder((t_cylinder *)object, cylinder++);
		object = object->next;
	}
}
