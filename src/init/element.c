/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 00:12:35 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/10 15:11:53 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_ambient(t_scene *scene, char **args)
{
	t_ambient	*ambient;
	static int	occur = 0;

	occur++;
	if (occur > 1)
		return (broadcast(ERR_ELEMENT_DUPLICATE, NULL));
	if (count_args(args) != 3)
		return (broadcast(ERR_AMBIENT_ARGS, NULL));
	scene->ambient = gct_malloc(sizeof(t_ambient));
	ambient = scene->ambient;
	ambient->type = identify_object(args[0]);
	if (!parse_float(&ambient->ratio, args[1], 0.0f, 1.0f))
		return (broadcast(ERR_AMBIENT_RATIO, NULL));
	if (!parse_rgb(&ambient->color, args[2]))
		return (broadcast(ERR_AMBIENT_COLOR, ERR_RGB_FORMAT));
	return (true);
}

bool	parse_camera(t_scene *scene, char **args)
{
	t_camera	*camera;
	static int	occur = 0;

	occur++;
	if (occur > 1)
		return (broadcast(ERR_ELEMENT_DUPLICATE, NULL));
	if (count_args(args) != 4)
		return (broadcast(ERR_CAMERA_ARGS, NULL));
	scene->camera = gct_malloc(sizeof(t_camera));
	camera = scene->camera;
	camera->type = identify_object(args[0]);
	if (!parse_vector(&camera->point, args[1], -100.0f, 100.0f))
		return (broadcast(ERR_CAMERA_POSITION, NULL));
	if (!parse_vector(&camera->direction, args[2], -1.0f, 1.0f))
		return (broadcast(ERR_CAMERA_DIRECTION, NULL));
	if (!parse_int(&camera->fov, args[3], 0, 360))
		return (broadcast(ERR_CAMERA_FOV, NULL));
	return (true);
}

static void	add_new_light(t_light **light, t_light *new)
{
	ft_lstadd_back((void **)light, (void *)new);
}

bool	parse_light(t_scene *scene, char **args)
{
	t_light	*light;

	if (count_args(args) != 4)
		return (broadcast(ERR_LIGHT_ARGS, NULL));
	light = gct_malloc(sizeof(t_light));
	light->type = identify_object(args[0]);
	light->next = NULL;
	if (!parse_vector(&light->point, args[1], -100.0f, 100.0f))
		return (broadcast(ERR_LIGHT_POSITION, NULL));
	if (!parse_float(&light->brightness, args[2], 0.0f, 1.0f))
		return (broadcast(ERR_LIGHT_BRIGHTNESS, NULL));
	if (!parse_rgb(&light->color, args[3]))
		return (broadcast(ERR_LIGHT_COLOR, ERR_RGB_FORMAT));
	add_new_light(&scene->light, light);
	return (true);
}
