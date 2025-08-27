/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:10:26 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/27 23:12:01 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	broadcast(char *msg1, char *msg2)
{
	if (msg1 && msg2)
	{
		ft_putstr_fd(msg1, 2);
		ft_putstr_fd(" ", 2);
		ft_putendl_fd(msg2, 2);
	}
	else if (msg1)
		ft_putendl_fd(msg1, 2);
	else if (msg2)
		ft_putendl_fd(msg2, 2);
	return (false);
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
