/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 00:50:00 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/01 23:34:29 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_object
{
	struct s_object		*next;
	int					type;
}	t_object;

typedef struct s_sphere
{
	struct s_sphere		*next;
	int					type;
	t_vector			center;
	float				radius;
	t_rgb				color;
}	t_sphere;

typedef struct s_plane
{
	struct s_plane		*next;
	int					type;
	t_vector			position;
	t_vector			normal;
	t_rgb				color;
}	t_plane;

typedef struct s_cap
{
	float		radius;
	t_rgb		color;
	t_vector	axis;
	t_vector	center;
	bool		hit;
}	t_cap;

typedef struct s_cylinder
{
	struct s_cylinder	*next;
	int					type;
	t_vector			center;
	t_vector			axis;
	float				radius;
	float				height;
	t_rgb				color;
}	t_cylinder;

#endif