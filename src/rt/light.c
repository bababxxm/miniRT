/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:11:57 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/31 21:48:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	clamp(t_rgb color)
{
	color.r = fminf(fmaxf(color.r, 0.0f), 255.0f);
	color.g = fminf(fmaxf(color.g, 0.0f), 255.0f);
	color.b = fminf(fmaxf(color.b, 0.0f), 255.0f);
	return (color);
}

t_rgb	compute_ambient(t_rgb hit, t_ambient *ambient)
{
	t_rgb	color;

	color.r = hit.r * ambient->color.r / 255.0f * ambient->ratio;
	color.g = hit.g * ambient->color.r / 255.0f * ambient->ratio;
	color.b = hit.b * ambient->color.r / 255.0f * ambient->ratio;
	return (color);
}

t_rgb	compute_diffuse(t_hit *hit, t_light *light)
{
	float		dot;
	t_rgb		color;
	float		intensity;
	t_vector	direction;

	direction = compute_light(light, hit->point);
	dot = vec3_dot(hit->normalized, direction);
	if (dot < 0)
		dot = 0;
	intensity = light->brightness * dot;
	color.r = hit->color.r * light->color.r / 255.0f * intensity;
	color.g = hit->color.g * light->color.g / 255.0f * intensity;
	color.b = hit->color.b * light->color.b / 255.0f * intensity;
	return (color);
}

t_vector	compute_light(t_light *light, t_vector point)
{
	t_vector	direction;

	direction = vec3_sub(light->positon, point);
	return (vec3_normalize(direction));
}
