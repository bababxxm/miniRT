/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:12:51 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/17 02:39:38 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	square(float x)
{
	return (x * x);
}

float	quadratic_equation(float a, float b, float c, t_hit *hit)
{
	float	t1;
	float	t2;
	float	discriminant;

	if (fabsf(a) < 1e-6f)
		return (-1);
	discriminant = square(b) - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	discriminant = sqrtf(discriminant);
	t1 = (-b - discriminant) / (2.0f * a);
	t2 = (-b + discriminant) / (2.0f * a);
	if (t1 > 0 && t1 < hit->t)
		return (t1);
	else if (t2 > 0 && t2 < hit->t)
		return (t2);
	return (-1);
}
