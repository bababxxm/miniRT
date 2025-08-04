/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:57:45 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/04 11:20:08 by sklaokli         ###   ########.fr       */
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

# define SUCCESS EXIT_SUCCESS
# define FAILURE EXIT_FAILURE

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

bool	parse_args(int argc, char **argv);
bool	parse_int(int *ptr, char *str, int min, int max);
bool	parse_float(float *ptr, char *str, float min, float max);
bool	parse_rgb(t_rgb *color, char *str);
bool	parse_vec3(t_vector *vec, char *str, float min, float max);

bool	parse_ambient(t_scene *scene, char **args);
bool	parse_camera(t_scene *scene, char **args);
bool	parse_light(t_scene *scene, char **args);
bool	parse_sphere(t_scene *scene, char **args);
bool	parse_plane(t_scene *scene, char **args);
bool	parse_cylinder(t_scene *scene, char **args);
bool	parse_scene(t_file *file, t_scene *scene);

int		before_dot(char **str);
int		after_dot(char **str);
int		identify_object(char *type);
int		count_args(char **args);
bool	broadcast(char *msg1, char *msg2);

void	display_float(char *text, float f);
void	display_color(char *text, t_rgb color);
void	display_vector(char *text, t_vector v);

int		put_pixel(t_rgb color);
void	clear_scene(char *msg, int exitcode);
void	close_scene(t_scene *scene, int status);

#endif