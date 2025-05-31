/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:17:12 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/31 19:26:01 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "gct.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

typedef enum s_identifier
{
	AMBIENT_LIGHTNING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_identifier;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_color
{
	size_t	r;
	size_t	g;
	size_t	b;
}	t_color;

typedef struct s_rt
{
	t_identifier	idtf;
	t_vector		axis;
}	t_rt;


#endif