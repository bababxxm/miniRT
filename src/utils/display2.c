/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:09:53 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/27 23:12:06 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	display_float(char *text, float f)
{
	printf("%s: %.2f\n", text, f);
}

void	display_color(char *text, t_rgb color)
{
	printf("%s: %u, %u, %u\n", text, color.r, color.g, color.b);
}

void	display_vector(char *text, t_vector v)
{
	printf("%s: %.2f, %.2f, %.2f\n", text, v.x, v.y, v.z);
}
