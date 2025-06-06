/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:17:12 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/06 15:39:13 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "libft.h"
# include "gct.h"
# include "get_next_line.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

typedef struct s_rgb
{
	size_t	r;
	size_t	g;
	size_t	b;
}	t_rgb;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef enum s_idtf
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_idtf;

typedef struct s_ambient
{
	float	ratio;
	t_rgb	color;
}	t_ambient;

typedef struct s_camera
{
	t_vector	point;
	t_vector	normalized;
	size_t		horizontal;
}	t_camera;

typedef struct s_light
{
	t_vector	point;
	float		ratio;
	t_rgb		color;
}	t_light;

typedef struct s_sphere
{
	t_vector	point;
	float		diameter;
}	t_sphere;

typedef struct s_file
{
	int		fd;
	t_list	*read;
}	t_file;

typedef struct s_rt
{
	t_file		file;
	t_vector	u;
	t_vector	v;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
}	t_rt;

#endif