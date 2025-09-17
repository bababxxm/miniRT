/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:46:44 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/10 14:29:51 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	rgb(int r, int g, int b)
{
	t_rgb	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_rgb	add_color(t_rgb a, t_rgb b)
{
	t_rgb	color;

	color.r = a.r + b.r;
	color.g = a.g + b.g;
	color.b = a.b + b.b;
	return (color);
}

t_rgb	scale_color(t_rgb color, float scale)
{
	t_rgb	res;

	res.r = color.r * scale;
	res.g = color.g * scale;
	res.b = color.b * scale;
	return (res);
}

t_rgb	modulate_color(t_rgb a, t_rgb b)
{
	t_rgb	res;

	res.r = a.r * b.r / 255.0f;
	res.g = a.g * b.g / 255.0f;
	res.b = a.b * b.b / 255.0f;
	return (res);
}

t_rgb	clamp(t_rgb color)
{
	color.r = fminf(fmaxf(color.r, 0.0f), 255.0f);
	color.g = fminf(fmaxf(color.g, 0.0f), 255.0f);
	color.b = fminf(fmaxf(color.b, 0.0f), 255.0f);
	return (color);
}
