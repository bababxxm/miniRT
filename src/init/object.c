/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:35:34 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/01 01:00:12 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_new_object(t_object **object, t_object *new)
{
	ft_lstadd_back((void **)object, (void *)new);
}

bool	parse_sphere(t_object **object, char **args)
{
	t_sphere	*sphere;

	if (!args || count_args(args) != 4)
		return (broadcast(ERR_SPHERE_ARGS, NULL));
	sphere = gct_malloc(sizeof(t_sphere));
	sphere->type = identify_object(args[0]);
	sphere->next = NULL;
	if (!parse_vec3(&sphere->center, args[1], -100.0f, 100.0f))
		return (broadcast(ERR_SPHERE_CENTER, ERR_VECTOR_FORMAT));
	if (!parse_float(&sphere->radius, args[2], 0.0f, 1000.0f))
		return (broadcast(ERR_SPHERE_RADIUS, NULL));
	if (!parse_rgb(&sphere->color, args[3]))
		return (broadcast(ERR_SPHERE_COLOR, ERR_RGB_FORMAT));
	add_new_object(object, (t_object *)sphere);
	return (true);
}

bool	parse_plane(t_object **object, char **args)
{
	t_plane	*plane;

	if (!args || count_args(args) != 4)
		return (broadcast(ERR_PLANE_ARGS, NULL));
	plane = gct_malloc(sizeof(t_plane));
	plane->type = identify_object(args[0]);
	plane->next = NULL;
	if (!parse_vec3(&plane->position, args[1], -100.0f, 100.0f))
		return (broadcast(ERR_PLANE_POSITION, NULL));
	if (!parse_vec3(&plane->normal, args[2], -1.0f, 1.0f))
		return (broadcast(ERR_PLANE_NORMAL, NULL));
	if (!parse_rgb(&plane->color, args[3]))
		return (broadcast(ERR_PLANE_COLOR, ERR_RGB_FORMAT));
	add_new_object(object, (t_object *)plane);
	return (true);
}

bool	parse_cylinder(t_object **object, char **args)
{
	t_cylinder	*cylinder;

	if (!args || count_args(args) != 6)
		return (broadcast(ERR_CYLINDER_ARGS, NULL));
	cylinder = gct_malloc(sizeof(t_cylinder));
	cylinder->type = identify_object(args[0]);
	cylinder->next = NULL;
	if (!parse_vec3(&cylinder->center, args[1], -100.0f, 100.0f))
		return (broadcast(ERR_CYLINDER_CENTER, ERR_VECTOR_FORMAT));
	if (!parse_vec3(&cylinder->axis, args[2], -1.0f, 1.0f))
		return (broadcast(ERR_CYLINDER_AXIS, ERR_VECTOR_FORMAT));
	if (!parse_float(&cylinder->radius, args[3], 0.0f, 1000.0f))
		return (broadcast(ERR_CYLINDER_RADIUS, NULL));
	if (!parse_float(&cylinder->height, args[4], 0.0f, 1000.0f))
		return (broadcast(ERR_CYLINDER_HEIGHT, NULL));
	if (!parse_rgb(&cylinder->color, args[5]))
		return (broadcast(ERR_CYLINDER_COLOR, ERR_RGB_FORMAT));
	add_new_object(object, (t_object *)cylinder);
	return (true);
}
