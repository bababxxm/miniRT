/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:34:44 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/17 22:04:24 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_scene(t_scene *scene)
{
	scene->window = NULL;
	scene->object = NULL;
	scene->light = NULL;
	scene->image = NULL;
	scene->ambient = gct_malloc(sizeof(t_ambient));
	scene->camera = gct_malloc(sizeof(t_camera));
}

static void	render_scene(t_scene *scene)
{
	scene->window = mlx_init(WINX, WINY, "miniRT", false);
	if (!scene->window)
		close_scene(scene, FAILURE);
	mlx_set_window_pos(scene->window, (3840 - WINX) / 2, (2160 - WINY) / 2);
	mlx_key_hook(scene->window, keybinds, scene);
	mlx_loop_hook(scene->window, ray_tracing, scene);
	mlx_loop(scene->window);
	mlx_terminate(scene->window);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = gct_malloc(sizeof(t_scene));
	if (!parse_args(argc, argv))
		clear_scene("Error: invalid arguments", FAILURE);
	init_scene(scene);
	if (!read_scene(argv[1], scene))
		clear_scene("Error: invalid format", FAILURE);
	display_info(scene);
	render_scene(scene);
	close_scene(scene, SUCCESS);
}
