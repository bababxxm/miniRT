/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:34:44 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/04 11:21:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_scene(t_scene *scene)
{
	scene->window = NULL;
	scene->object = NULL;
	scene->light = NULL;
	scene->image = NULL;
	scene->ambient = NULL;
	scene->camera = NULL;
}

static bool	read_scene(char *name, t_scene *scene)
{
	t_file	*file;

	file = open_file(name, ".rt", O_RDONLY);
	if (!file)
		return (broadcast(ERR_FILE, NULL));
	if (!read_file(file))
		return (close_file(file), false);
	if (!parse_scene(file, scene))
		return (close_file(file), false);
	close_file(file);
	return (true);
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
		clear_scene(ERR_FILE, FAILURE);
	init_scene(scene);
	if (!read_scene(argv[1], scene))
		clear_scene(NULL, FAILURE);
	display_info(scene);
	render_scene(scene);
	close_scene(scene, SUCCESS);
}
