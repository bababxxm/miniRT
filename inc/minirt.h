/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:28:39 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/04 03:00:27 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "config.h"
# include "element.h"
# include "object.h"
# include "render.h"
# include "error.h"

# define WINX 2048
# define WINY 1024

# define EPSILON 1e-4

typedef enum e_type
{
	UNKNOWN,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_scene
{
	mlx_t		*window;
	mlx_image_t	*image;
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_object	*object;
}	t_scene;

void	display_info(t_scene *scene);
void	ray_tracing(void *context);
void	keybinds(mlx_key_data_t key, void *context);

#endif