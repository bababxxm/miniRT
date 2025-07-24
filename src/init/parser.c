/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:32:42 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/17 02:02:15 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_int(int *ptr, char *str, int min, int max)
{
	long	nbr;
	char	*start;

	if (!str)
		return (false);
	str = ft_strskip(str, WHITESPACE, true);
	start = str;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '+' || *str == '-' || !ft_isdigit(*str))
		return (false);
	str = ft_strskip(str, "0123456789", true);
	str = ft_strskip(str, WHITESPACE, true);
	if (*str != '\0')
		return (false);
	nbr = ft_atol(start);
	if (nbr < min || nbr > max)
		return (false);
	*ptr = (int)nbr;
	return (true);
}

bool	parse_float(float *ptr, char *str, float min, float max)
{
	float	nbr;
	char	*start;

	if (!str)
		return (false);
	str = ft_strskip(str, WHITESPACE, true);
	start = str;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '+' || *str == '-' || !ft_isdigit(*str))
		return (false);
	str = ft_strskip(str, "+-", true);
	if (!before_dot(&str) || !after_dot(&str))
		return (false);
	str = ft_strskip(str, WHITESPACE, true);
	if (*str != '\0')
		return (false);
	nbr = ft_atof(start);
	if (nbr < min || nbr > max)
		return (false);
	*ptr = nbr;
	return (true);
}

bool	parse_rgb(t_rgb *color, char *str)
{
	char	**args;

	args = gct_split(str, ',');
	if (!args || count_args(args) != 3)
		return (false);
	if (!parse_int((int *)&color->r, args[0], 0, 255)
		|| !parse_int((int *)&color->g, args[1], 0, 255)
		|| !parse_int((int *)&color->b, args[2], 0, 255))
		return (false);
	return (true);
}

bool	parse_vec3(t_vector *vec, char *str, float min, float max)
{
	char	**args;

	args = gct_split(str, ',');
	if (!args || count_args(args) != 3)
		return (false);
	if (!parse_float(&vec->x, args[0], min, max)
		|| !parse_float(&vec->y, args[1], min, max)
		|| !parse_float(&vec->z, args[2], min, max))
		return (false);
	return (true);
}
