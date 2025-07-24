/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:45:36 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/24 20:32:31 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "config.h"
# include "element.h"
# include "object.h"
# include "render.h"

# define WINX 2048
# define WINY 1024

#define EPSILON 1e-6

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

bool	parse_args(int argc, char **argv);

void	ray_tracing(void *context);
void	keybinds(mlx_key_data_t key, void *context);

void	display_info(t_scene *scene);
void	clear_scene(char *msg, int exitcode);
void	close_scene(t_scene *scene, int status);

bool	read_scene(char *path, t_scene *scene);
int		put_pixel(t_rgb color);

#endif