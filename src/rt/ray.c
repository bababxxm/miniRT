/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:11:03 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/04 21:47:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	compute_ray(float px, float py, t_camera *camera)
{
	t_ray		ray;
	t_vector	right_offset;
	t_vector	up_offset;
	t_vector	direction;

	ray.origin = camera->position;
	right_offset = mul(camera->right, px);
	up_offset = mul(camera->up, py);
	direction = add(camera->direction, right_offset);
	direction = add(direction, up_offset);
	ray.direction = normalize(direction);
	return (ray);
}

t_ray	generate_ray(int x, int y, t_camera *camera)
{
	float	px;
	float	py;
	float	aspect_ratio;
	float	fov_adjust;

	aspect_ratio = (float)WINX / (float)WINY;
	px = (2.0f * ((x + 0.5f) / WINX) - 1.0f) * aspect_ratio;
	py = 1.0f - 2.0f * ((y + 0.5f) / WINY);
	fov_adjust = tanf((camera->fov * 0.5f) * (PI / 180.0f));
	return (compute_ray(px * fov_adjust, -py * fov_adjust, camera));
}
