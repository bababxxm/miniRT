/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 01:57:14 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/04 01:57:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_camera(t_scene *scene)
{
	if (mlx_is_key_down(scene->window, MLX_KEY_RIGHT))
		scene->camera->position.x += 0.5;
	if (mlx_is_key_down(scene->window, MLX_KEY_LEFT))
		scene->camera->position.x -= 0.5;
	if (mlx_is_key_down(scene->window, MLX_KEY_UP))
		scene->camera->position.y += 0.5;
	if (mlx_is_key_down(scene->window, MLX_KEY_DOWN))
		scene->camera->position.y -= 0.5;
	if (mlx_is_key_down(scene->window, MLX_KEY_Z))
		scene->camera->position.z += 0.5;
	if (mlx_is_key_down(scene->window, MLX_KEY_X))
		scene->camera->position.z -= 0.5;
}

void	adjust_camera_direction(t_scene *scene)
{
	if (mlx_is_key_down(scene->window, MLX_KEY_LEFT_SHIFT))
	{
		if (mlx_is_key_down(scene->window, MLX_KEY_RIGHT))
			scene->camera->direction.x += 0.05;
		if (mlx_is_key_down(scene->window, MLX_KEY_LEFT))
			scene->camera->direction.x -= 0.05;
		if (mlx_is_key_down(scene->window, MLX_KEY_UP))
			scene->camera->direction.y += 0.05;
		if (mlx_is_key_down(scene->window, MLX_KEY_DOWN))
			scene->camera->direction.y -= 0.05;
	}
}

void	keybinds(mlx_key_data_t k, void *context)
{
	t_scene	*scene;

	scene = (t_scene *)context;
	if (k.action == MLX_PRESS)
	{
		mlx_delete_image(scene->window, scene->image);
		scene->image = NULL;
	}
	move_camera(scene);
	adjust_camera_direction(scene);
	if (mlx_is_key_down(scene->window, MLX_KEY_ESCAPE))
		mlx_close_window(scene->window);
	if (mlx_is_key_down(scene->window, MLX_KEY_Q))
		mlx_close_window(scene->window);
}