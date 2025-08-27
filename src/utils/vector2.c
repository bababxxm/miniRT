/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:45:49 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/27 23:19:08 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normalize(t_vector v)
{
	float	f;

	f = sqrtf(dot(v, v));
	v.x = v.x / f;
	v.y = v.y / f;
	v.z = v.z / f;
	return (v);
}

t_vector	cross(t_vector u, t_vector v)
{
	t_vector	vector;

	vector.x = u.y * v.z - u.z * v.y;
	vector.y = u.z * v.x - u.x * v.z;
	vector.z = u.x * v.y - u.y * v.x;
	return (vector);
}

float	length(t_vector u)
{
	return (sqrtf((u.x * u.x) + (u.y * u.y) + (u.z * u.z)));
}
