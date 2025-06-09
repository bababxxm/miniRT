/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:32:42 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/09 02:34:57 by sklaokli         ###   ########.fr       */
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

int	parse_int()
{

}

float	parse_float()
{
	
}

t_rgb	parse_rgb(char *palette)
{
	t_rgb	rgb;
	char	**args;

	rgb = (t_rgb){0, 0, 0};
	args = ft_split(palette, ',');
	if (!args || count_args(args) != 3)
	{
		ft_free_2d(args);
		return (rgb);
	}
	rgb.r = ft_atoi(args[0]);
	rgb.g = ft_atoi(args[1]);
	rgb.b = ft_atoi(args[2]);
	ft_free_2d(args);
	return (rgb);
}

t_vector	parse_vec3()
{
	
}

