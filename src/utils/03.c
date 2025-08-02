/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:45:49 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/01 00:16:36 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vec3_cross(t_vector u, t_vector v)
{
	t_vector	vec3;

	vec3.x = u.y * v.z - u.z * v.y;
	vec3.y = u.z * v.x - u.x * v.z;
	vec3.z = u.x * v.y - u.y * v.x;
	return (vec3);
}

float	vec3_length(t_vector u)
{
	return (sqrtf((u.x * u.x) + (u.y * u.y) + (u.z * u.z)));
}

bool	broadcast(char *msg1, char *msg2)
{
	if (msg1 && msg2)
	{
		ft_putstr_fd(msg1, 2);
		ft_putstr_fd(" ", 2);
		ft_putendl_fd(msg2, 2);
	}
	else if (msg1)
		ft_putendl_fd(msg1, 2);
	else if (msg2)
		ft_putendl_fd(msg2, 2);
	return (false);
}
