/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 01:35:22 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/10 01:39:36 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"

int			parse_float(float *ptr, char *str, float min, float max);
int			parse_int(int *ptr, char *str, int min, int max);
uint32_t	parse_uint(uint32_t *ptr, char *str, uint32_t min, uint32_t max);
int			parse_rgb(t_rgb *color, char *str);
int			parse_vec3(t_vector *vec, char *str);

bool		parse_ambient(t_ambient *ambient, char **args);
bool		parse_camera(t_camera *camera, char **args);
bool		parse_light(t_light *light, char **args);

int			before_dot(char **str);
int			after_dot(char **str);
int			which_object(char *idtf);
int			count_args(char **args);

#endif