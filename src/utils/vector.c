/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:45:24 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/27 23:19:04 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector(float x, float y, float z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

float	dot(t_vector u, t_vector v)
{
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

t_vector	add(t_vector u, t_vector v)
{
	t_vector	vector;

	vector.x = u.x + v.x;
	vector.y = u.y + v.y;
	vector.z = u.z + v.z;
	return (vector);
}

t_vector	sub(t_vector u, t_vector v)
{
	t_vector	vector;

	vector.x = u.x - v.x;
	vector.y = u.y - v.y;
	vector.z = u.z - v.z;
	return (vector);
}

t_vector	mul(t_vector u, float f)
{
	t_vector	vector;

	vector.x = u.x * f;
	vector.y = u.y * f;
	vector.z = u.z * f;
	return (vector);
}
