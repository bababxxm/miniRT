/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:45:36 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/10 00:38:25 by sklaokli         ###   ########.fr       */
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

void		parse_argument(int argc, char **argv);
void		parse_file(t_rt *minirt, char *title);

int			parse_float(float *ptr, char *str, float min, float max);
int			parse_int(int *ptr, char *str, int min, int max);
uint32_t	parse_uint(uint32_t *ptr, char *str, uint32_t min, uint32_t max);
int			parse_rgb(t_rgb *color, char *str);
int			parse_vec3(t_vector *vec, char *str);

bool		parse_ambient(t_ambient *ambient, char **args);
bool		parse_camera(t_camera *camera, char **args);
bool		parse_light(t_light *light, char **args);

void		ft_perror(char *msg);
float		ft_atof(char *str);
int			which_object(char *idtf);
int			count_args(char **args);

#endif