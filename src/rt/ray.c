/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:11:03 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/09 19:49:28 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	get_right_offset(float x, float fov_scale, t_camera *camera)
{
	float	u;
	float	px;
	float	aspect_ratio;

	u = (x + 0.5f) / (float)WINX;
	aspect_ratio = (float)WINX / (float)WINY;
	px = (2.0f * u - 1.0f) * aspect_ratio;
	return (mul(camera->right, px * fov_scale));
}

static t_vector	get_up_offset(float y, float fov_scale, t_camera *camera)
{
	float	v;
	float	py;

	v = (y + 0.5f) / (float)WINY;
	py = 1.0f - 2.0f * v;
	return (mul(camera->up, -py * fov_scale));
}

t_ray	generate_ray(int x, int y, t_camera *camera)
{
	t_ray		ray;
	float		fov_scale;
	t_vector	right_offset;
	t_vector	up_offset;
	t_vector	direction;

	ray.origin = camera->position;
	fov_scale = tanf((camera->fov * 0.5f) * (PI / 180.0f));
	right_offset = get_right_offset(x, fov_scale, camera);
	up_offset = get_up_offset(y, fov_scale, camera);
	direction = add(camera->direction, right_offset);
	direction = add(direction, up_offset);
	ray.direction = normalize(direction);
	return (ray);
}
