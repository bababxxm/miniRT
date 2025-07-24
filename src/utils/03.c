/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:45:24 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/15 20:18:22 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	vec3_dot(t_vector u, t_vector v)
{
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

t_vector	vec3_add(t_vector u, t_vector v)
{
	t_vector	vec3;

	vec3.x = u.x + v.x;
	vec3.y = u.y + v.y;
	vec3.z = u.z + v.z;
	return (vec3);
}

t_vector	vec3_sub(t_vector u, t_vector v)
{
	t_vector	vec3;

	vec3.x = u.x - v.x;
	vec3.y = u.y - v.y;
	vec3.z = u.z - v.z;
	return (vec3);
}

t_vector	vec3_mul(t_vector u, float f)
{
	t_vector	vec3;

	vec3.x = u.x * f;
	vec3.y = u.y * f;
	vec3.z = u.z * f;
	return (vec3);
}

t_vector	vec3_normalize(t_vector v)
{
	float	f;

	f = sqrtf(vec3_dot(v, v));
	v.x = v.x / f;
	v.y = v.y / f;
	v.z = v.z / f;
	return (v);
}
