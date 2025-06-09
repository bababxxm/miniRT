/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 00:12:35 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/10 01:01:57 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_ambient(t_ambient *ambient, char **args)
{
	static int	occur = 0;

	occur++;
	if (occur > 1 || count_args(args) != 3)
		return (false);
	ambient->idtf = which_object(args[0]);
	if (!parse_float(&ambient->ratio, args[1], 0.0, 1.0))
		return (false);
	if (!parse_rgb(&ambient->color, args[2]))
		return (false);

	ft_putendl_fd("parsing ambient.. [OK]", 1);
	printf("ambient->ratio = %f\n", ambient->ratio);
	printf("ambient->color = %u, %u, %u\n", 
		ambient->color.r, ambient->color.g, ambient->color.b);

	return (true);
}

bool	parse_camera(t_camera *camera, char **args)
{
	static int	occur = 0;

	occur++;
	if (occur > 1 || count_args(args) != 3)
		return (false);
	camera->idtf = which_object(args[0]);
	if (!parse_vec3(&camera->pos, args[1]))
		return (false);
	if (!parse_vec3(&camera->dir, args[2]))
		return (false);
	if (!parse_uint((uint32_t *)&camera->fov, args[3], 0, UINT32_MAX))
		return (false);

	ft_putendl_fd("parsing camera.. [OK]", 1);

	return (true);
}

bool	parse_light(t_light *light, char **args)
{
	static int	occur = 0;

	occur++;
	if (occur > 1 || count_args(args) != 4)
		return (false);
	light->idtf = which_object(args[0]);
	if (!parse_vec3(&light->pos, args[1]))
		return (false);
	if (!parse_float(&light->brightness, args[2], 0.0, 1.0))
		return (false);
	if (!parse_rgb(&light->color, args[3]))
		return (false);

	ft_putendl_fd("[OK] parsing light", 1);
	
	return (true);
}