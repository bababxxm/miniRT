/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:12:51 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/10 15:11:55 by sklaokli         ###   ########.fr       */
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

	if (fabsf(a) < EPSILON)
		return (-1);
	discriminant = square(b) - 4.0f * a * c;
	if (discriminant < 0)
		return (-1);
	discriminant = sqrtf(discriminant);
	t1 = (-b - discriminant) / (2.0f * a);
	t2 = (-b + discriminant) / (2.0f * a);
	if (t1 > EPSILON && t1 < hit->t)
		return (t1);
	else if (t2 > EPSILON && t2 < hit->t)
		return (t2);
	return (-1);
}

bool	intersect_plane(t_ray ray, t_vector normal, t_vector point, float *t)
{
	float	denom;
	float	numer;

	denom = dot(ray.direction, normal);
	if (fabs(denom) < EPSILON)
		return (false);
	numer = dot(sub(point, ray.origin), normal);
	*t = numer / denom;
	return (*t > 0);
}

t_cap	create_cap(t_cylinder *cylinder, t_vector axis, t_vector center)
{
	t_cap	cap;

	cap.radius = cylinder->radius;
	cap.color = cylinder->color;
	cap.axis = axis;
	cap.point = center;
	cap.hit = false;
	return (cap);
}
