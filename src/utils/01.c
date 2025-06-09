/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:23:12 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/08 23:35:22 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	ft_atof(char *str)
{
	int		div;
	int		sign;
	float	result;
	float	fraction;

	div = 1;
	sign = 1;
	result = 0.0f;
	fraction = 0.0f;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str && (*str >= '0' && *str <= '9'))
		result = result * 10 + (*str++ - '0');
	if (*str++ == '.')
	{
		while (*str && (*str >= '0' && *str <= '9'))
		{
			fraction = (fraction * 10) + (*str++ - '0');
			div *= 10;
		}
	}
	return (sign * (result + fraction / div));
}