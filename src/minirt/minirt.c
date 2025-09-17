/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:05:31 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/10 14:26:13 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	put_pixel(t_rgb color)
{
	return (color.r << 24 | color.g << 16 | color.b << 8 | 255);
}

static void	projection(t_scene *scene)
{
	int		x;
	int		y;
	t_ray	ray;
	t_rgb	color;

	y = 0;
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
		{
			ray = generate_ray(x, y, scene->camera);
			color = trace_ray(ray, scene);
			mlx_put_pixel(scene->image, x, y, put_pixel(color));
			x++;
		}
		y++;
	}
}

static void	setup_camera(t_camera *camera)
{
	t_vector	up;
	t_vector	right;

	up = vector(0, 1, 0);
	camera->direction = normalize(camera->direction);
	right = cross(camera->direction, up);
	camera->right = normalize(mul(right, -1));
	up = cross(camera->right, camera->direction);
	camera->up = normalize(up);
}

void	ray_tracing(void *context)
{
	t_scene	*scene;

	scene = (t_scene *)context;
	if (!scene->image)
	{
		scene->image = mlx_new_image(scene->window, WINX, WINY);
		setup_camera(scene->camera);
		projection(scene);
	}
	mlx_image_to_window(scene->window, scene->image, 0, 0);
}
