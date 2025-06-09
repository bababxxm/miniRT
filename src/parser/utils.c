/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:32:35 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/10 01:38:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_argument(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		ft_perror("Error: invalid number of arguments.");
	i = -1;
	while (argv[++i])
	{
		if (*argv[i] == '\0')
			ft_perror("Error: an argument cannot be empty.");
	}
}

int	count_args(char **args)
{
	int	cnt;

	cnt = 0;
	while (args[cnt])
		cnt++;
	return (cnt);
}

int	which_object(char *idtf)
{
	if (!ft_strncmp(idtf, "A", 1))
		return (AMBIENT);
	else if (!ft_strncmp(idtf, "C", 1))
		return (CAMERA);
	else if (!ft_strncmp(idtf, "L", 1))
		return (LIGHT);
	else if (!ft_strncmp(idtf, "pl", 2))
		return (PLANE);
	else if (!ft_strncmp(idtf, "sp", 2))
		return (SPHERE);
	else if (!ft_strncmp(idtf, "cy", 2))
		return (CYLINDER);
	else
		return (UNRECOGNIZED);
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
	return (has_digits);
}
