/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:11:57 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/04 02:13:01 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	compute_ambient(t_rgb hit, t_ambient *ambient)
{
	t_rgb	color;

	color = modulate_color(hit, ambient->color);
	return (scale_color(color, ambient->ratio));
}

t_rgb	compute_diffuse(t_hit *hit, t_light *light)
{
	t_rgb		color;
	float		dotnl;
	float		intensity;
	t_vector	direction;

	direction = normalize(sub(light->positon, hit->point));
	dotnl = fmaxf(dot(hit->normal, direction), 0.0f);
	intensity = light->brightness * dotnl;
	color = modulate_color(hit->color, light->color);
	return (scale_color(color, intensity));
}

t_rgb	compute_lighting(t_hit *hit, t_ambient *amb, t_light *light)
{
	t_rgb	color;
	t_rgb	ambient;
	t_rgb	diffuse;

	ambient = compute_ambient(hit->color, amb);
	diffuse = compute_diffuse(hit, light);
	color.r = ambient.r + diffuse.r;
	color.g = ambient.g + diffuse.g;
	color.b = ambient.b + diffuse.b;
	return (clamp(color));
}
