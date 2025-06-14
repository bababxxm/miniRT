/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:45:36 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/10 22:09:58 by sklaokli         ###   ########.fr       */
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

# include "object.h"
# include "window.h"

typedef struct s_scene
{
	mlx_t		*window;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_object	*object;
}	t_scene;

#endif