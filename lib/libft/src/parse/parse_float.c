/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:37:48 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/01 22:40:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	before_dot(char **str)
{
	char	*ptr;
	bool	has_digits;

	ptr = *str;
	has_digits = false;
	*str = ft_strskip(*str, "0123456789", true);
	if (*str > ptr)
		has_digits = true;
	return (has_digits);
}

static int	after_dot(char **str)
{
	char	*ptr;
	bool	has_digits;

	has_digits = false;
	if (**str == '.')
	{
		(*str)++;
		ptr = *str;
		*str = ft_strskip(*str, "0123456789", true);
		if (*str > ptr)
			has_digits = true;
	}
	else
	{
		ptr = *str;
		if (*ptr == '\0')
			return (true);
		return (false);
	}
	return (has_digits);
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
