/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:32:42 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/10 01:02:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	before_dot(char **str);
int	after_dot(char **str);

int	parse_int(int *ptr, char *str, int min, int max)
{
	long	nbr;
	char	*start;

	if (!str || !ptr)
		return (false);
	str = ft_strskip(str, WHITESPACE, true);
	start = str;
	str = ft_strskip(str, "+-", true);
	str = ft_strskip(str, "0123456789", true);
	if (str == start)
		return (false);
	str = ft_strskip(str, WHITESPACE, true);
	if (*str != '\0')
		return (false);
	nbr = atol(start);
	if (nbr < min || nbr > max)
		return (false);
	*ptr = (int)nbr;
	return (true);
}

uint32_t	parse_uint(uint32_t *ptr, char *str, uint32_t min, uint32_t max)
{
	long	nbr;
	char	*start;

	if (!str || !ptr)
		return (false);
	str = ft_strskip(str, WHITESPACE, true);
	start = str;
	str = ft_strskip(str, "+", true);
	str = ft_strskip(str, "0123456789", true);
	if (str == start)
		return (false);
	str = ft_strskip(str, WHITESPACE, true);
	if (*str != '\0')
		return (false);
	nbr = atol(start);
	if (nbr < min || nbr > max)
		return (false);
	*ptr = (uint32_t)nbr;
	return (true);
}

int	parse_float(float *ptr, char *str, float min, float max)
{
	float	nbr;
	char	*start;

	if (!str || !ptr)
		return (false);
	str = ft_strskip(str, WHITESPACE, true);
	start = str;
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

int	parse_rgb(t_rgb *color, char *str)
{
	char	**args;

	args = ft_split(str, ',');
	if (!args || count_args(args) != 3)
		return (false);
	if (!parse_int((int *)&color->r, args[0], 0, 255))
		return (false);
	if (!parse_int((int *)&color->g, args[1], 0, 255))
		return (false);
	if (!parse_int((int *)&color->b, args[2], 0, 255))
		return (false);
	return (true);
}

int	parse_vec3(t_vector *vec, char *str)
{
	char	**args;

	args = ft_split(str, ',');
	if (!args || count_args(args) != 3)
		return (false);
	if (!parse_float(&vec->x, args[0], -1000.0, 1000.0))
		return (false);
	if (!parse_float(&vec->y, args[1], -1000.0, 1000.0))
		return (false);
	if (!parse_float(&vec->z, args[2], -1000.0, 1000.0))
		return (false);
	return (true);
}
