/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:09:53 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/31 23:26:36 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	display_float(char *text, float f)
{
	printf("%s: %.2f\n", text, f);
}

void	display_color(char *text, t_rgb color)
{
	printf("%s: %u, %u, %u\n", text, color.r, color.g, color.b);
}

void	display_vector(char *text, t_vector v)
{
	printf("%s: %.2f, %.2f, %.2f\n", text, v.x, v.y, v.z);
}

void	close_scene(t_scene *scene, int status)
{
	if (scene->window && status)
	{
		puts(mlx_strerror(mlx_errno));
		mlx_close_window(scene->window);
	}
	clear_scene("miniRT closed", status);
}

void	clear_scene(char *msg, int exitcode)
{
	gct_cleanup();
	ft_exit(msg, exitcode);
}
