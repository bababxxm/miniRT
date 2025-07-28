/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:57:45 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/28 20:00:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>

# include "libft.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

# define SUCCESS 0
# define FAILURE 1

typedef struct s_rgb		t_rgb;
typedef struct s_vector		t_vector;
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_cylinder	t_cylinder;
typedef struct s_ray		t_ray;
typedef struct s_hit		t_hit;
typedef struct s_scene		t_scene;

int			open_fd(char *path, char *extension, int o_flags);
t_content	*read_fd(int fd);
void		clear_content(t_content *content);

bool		parse_int(int *ptr, char *str, int min, int max);
bool		parse_float(float *ptr, char *str, float min, float max);
bool		parse_rgb(t_rgb *color, char *str);
bool		parse_vec3(t_vector *vec, char *str, float min, float max);

bool		parse_ambient(t_ambient *ambient, char **args);
bool		parse_camera(t_camera *camera, char **args);
bool		parse_light(t_light **light, char **args);
bool		parse_sphere(t_object **object, char **args);
bool		parse_plane(t_object **object, char **args);
bool		parse_cylinder(t_object **object, char **args);

int			before_dot(char **str);
int			after_dot(char **str);
int			identify_object(char *type);
int			count_args(char **args);

void		display_float(char *text, float f);
void		display_color(char *text, t_rgb color);
void		display_vector(char *text, t_vector v);

bool		broadcast(char *msg);

#endif