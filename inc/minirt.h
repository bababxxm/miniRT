/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:45:36 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/09 01:34:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>

# include "libft.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

# include "object.h"

typedef struct s_rt
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_object	*object;
}	t_rt;

void	parse_argument(int argc, char **argv);
void	parse_file(t_rt *minirt, char *title);
bool	parse_ambient(t_rt *minirt, char **args);
bool	parse_camera(t_rt *minirt, char **args);
bool	parse_light(t_rt *minirt, char **args);

void	ft_perror(char *msg);
float	ft_atof(char *str);
int		which_identifer(char *idtf);

#endif