/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:10:00 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/17 03:47:57 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setup_camera(t_camera *camera)
{
	t_vector	up;
	t_vector	right;

	up = vec3(0, 0, 1);
	right = vec3(0, -1, 0);
	camera->direction = vec3_normalize(camera->direction);
	right = vec3_cross(camera->direction, right);
	if (vec3_length(right) < 1e-6)
		right = vec3_cross(camera->direction, up);
	camera->right = vec3_normalize(right);
	up = vec3_cross(camera->right, camera->direction);
	camera->up = vec3_normalize(up);
}
