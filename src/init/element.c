/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 00:12:35 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/17 02:02:15 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_ambient(t_ambient *ambient, char **args)
{
	static int	occur = 0;

	occur++;
	if (occur > 1 || count_args(args) != 3)
		return (false);
	ambient->type = identify_object(args[0]);
	if (!parse_float(&ambient->ratio, args[1], 0.0f, 1.0f)
		|| !parse_rgb(&ambient->color, args[2]))
		return (false);
	return (true);
}

bool	parse_camera(t_camera *camera, char **args)
{
	static int	occur = 0;

	occur++;
	if (occur > 1 || count_args(args) != 4)
		return (false);
	camera->type = identify_object(args[0]);
	if (!parse_vec3(&camera->position, args[1], -100.0f, 100.0f)
		|| !parse_vec3(&camera->direction, args[2], -1.0f, 1.0f)
		|| !parse_int((int *)&camera->fov, args[3], 0, INT_MAX))
		return (false);
	return (true);
}

static void	add_new_light(t_light **light, t_light *new)
{
	ft_lstadd_back((void **)light, (void *)new);
}

bool	parse_light(t_light **light, char **args)
{
	t_light	*new;

	if (count_args(args) != 4)
		return (false);
	new = gct_malloc(sizeof(t_light));
	new->type = identify_object(args[0]);
	new->next = NULL;
	if (!parse_vec3(&new->positon, args[1], -100.0f, 100.0f)
		|| !parse_float(&new->brightness, args[2], 0.0f, 1.0f)
		|| !parse_rgb(&new->color, args[3]))
		return (false);
	add_new_light(light, new);
	return (true);
}
