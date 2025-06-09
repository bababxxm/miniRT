/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 00:50:00 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/09 01:54:51 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <unistd.h>
# include <stdint.h>

typedef struct s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef enum s_idtf
{
	UNRECOGNIZED,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_idtf;

typedef struct s_ambient
{
	t_idtf		idtf;
	float		ratio;
	t_rgb		color;
}	t_ambient;

typedef struct s_camera
{
	t_idtf		idtf;
	t_vector	pos;
	t_vector	dir;
	size_t		fov;
}	t_camera;

typedef struct s_object
{
	struct s_object		*next;
	t_idtf				idtf;
}	t_object;

typedef struct s_light
{
	struct s_light		*next;
	t_idtf				idtf;
	t_vector			pos;
	float				brightness;
	t_rgb				color;
}	t_light;

typedef struct s_sphere
{
	struct s_sphere		*next;
	t_idtf				idtf;
	t_vector			pos;
	float				diameter;
}	t_sphere;

typedef struct s_plane
{
	struct s_plane		*next;
	t_idtf				idtf;
}	t_plane;

typedef struct s_cylinder
{
	struct s_cylinder	*next;
	t_idtf				idtf;
}	t_cylinder;

#endif