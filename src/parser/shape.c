/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 00:12:35 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/09 01:55:09 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_args(char **args)
{
	int	cnt;

	cnt = 0;
	while (args[cnt])
		cnt++;
	return (cnt);
}

bool	parse_ambient(t_rt *minirt, char **args)
{
	static int	occur = 0;

	occur++;
	if (occur > 1 || count_args(args) != 3)
		return (false);

	minirt->ambient.idtf = which_identifer(args[0]);
	minirt->ambient.ratio = parse_float(args[1]);
	if (minirt->ambient.ratio < 0.0 || minirt->ambient.ratio > 1.0)
		return (false);
	minirt->ambient.color = parse_rgb(args[2]);

	return (true);
}

bool	parse_camera(t_rt *minirt, char **args)
{
	static int	occur = 0;

	occur++;
	if (occur > 1 || count_args(args) != 3)
		return (false);

	minirt->camera.idtf = which_identifer(args[0]);
	minirt->camera.pos = parse_vec3(args[1]);
	minirt->camera.dir = parse_vec3(args[2]);
	minirt->camera.fov = parse_int(args[3]);
	if (minirt->camera.fov < 0 || minirt->camera.fov > 180)
		return (false);

	return (true);
}

bool	parse_light(t_rt *minirt, char **args)
{
	static int	occur = 0;

	occur++;
	if (occur > 1 || count_args(args) > 3)
		return (false);

	minirt->light.idtf = which_identifer(args[0]);
	minirt->light.pos = parse_vec3(args[1]);
	minirt->light.brightness = parse_float(args[2]);
	if (minirt->light.brightness < 0.0 || minirt->light.brightness > 1.0)
		return (false);
	minirt->light.color = parse_rgb(args[3]);

	return (true);
}