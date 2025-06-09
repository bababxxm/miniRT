/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:32:42 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/09 21:47:53 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	which_identifer(char *idtf)
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

int	parse_int(int *ptr, char *str, int min, int max)
{
	int		nbr;
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
	nbr = ft_atoi(start);
	if (nbr < min || nbr > max)
		return (false);
	*ptr = nbr;
	return (true);
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

int	parse_float(float *ptr, char *str, float min, float max)
{
	float	nbr;
	char	*tmp;
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

int	parse_rgb(t_rgb *color, char *palette)
{
	char	**args;

	args = ft_split(palette, ',');
	if (!args || count_args(args) != 3)
	{
		ft_free_2d((void **)args);
		return (false);
	}
	if (!parse_uint(&color->r, args[0], 0, 100))
		return (false);
	if (!parse_uint(&color->g, args[1], 0, 100))
		return (false);
	if (!parse_uint(&color->b, args[2], 0, 100))
		return (false);
	ft_free_2d((void **)args);
	return (true);
}

t_vector	parse_vec3()
{
	
}

