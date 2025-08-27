/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:24:06 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/27 23:15:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (false);
	i = -1;
	while (argv[++i])
	{
		if (*argv[i] == '\0')
			return (false);
	}
	return (true);
}

int	count_args(char **args)
{
	int	cnt;

	cnt = 0;
	while (args[cnt])
		cnt++;
	return (cnt);
}

int	identify_object(char *type)
{
	if (!ft_strncmp(type, "A", 1))
		return (AMBIENT);
	else if (!ft_strncmp(type, "C", 1))
		return (CAMERA);
	else if (!ft_strncmp(type, "L", 1))
		return (LIGHT);
	else if (!ft_strncmp(type, "pl", 2))
		return (PLANE);
	else if (!ft_strncmp(type, "sp", 2))
		return (SPHERE);
	else if (!ft_strncmp(type, "cy", 2))
		return (CYLINDER);
	else
		return (UNKNOWN);
}

int	before_dot(char **str)
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

int	after_dot(char **str)
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
