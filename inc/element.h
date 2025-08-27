/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:44:24 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/27 23:26:22 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_ambient
{
	int			type;
	float		ratio;
	t_rgb		color;
}	t_ambient;

typedef struct s_camera
{
	int			type;
	t_vector	position;
	t_vector	direction;
	t_vector	up;
	t_vector	right;
	int			fov;
}	t_camera;

typedef struct s_light
{
	struct s_light	*next;
	int				type;
	t_vector		positon;
	float			brightness;
	t_rgb			color;
}	t_light;

#endif