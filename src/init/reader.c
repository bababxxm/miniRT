/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:24:19 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/01 23:26:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	parse_object(char *line, t_scene *scene)
{
	int		type;
	char	**args;

	args = gct_split_set(line, WHITESPACE);
	if (!args)
		return (false);
	type = identify_object(args[0]);
	if (type == UNKNOWN)
		return (broadcast(ERR_ELEMENT_UNKNOWN, NULL));
	else if (type == AMBIENT)
		return (parse_ambient(scene, args));
	else if (type == CAMERA)
		return (parse_camera(scene, args));
	else if (type == LIGHT)
		return (parse_light(scene, args));
	else if (type == SPHERE)
		return (parse_sphere(scene, args));
	else if (type == PLANE)
		return (parse_plane(scene, args));
	else if (type == CYLINDER)
		return (parse_cylinder(scene, args));
	return (true);
}

static bool	skip_line(char *line)
{
	if (*line == '#' || *line == '\n')
		return (true);
	return (false);
}

bool	read_scene(char *path, t_scene *scene)
{
	int			fd;
	void		*ptr;
	t_content	*file;

	fd = open_fd(path, ".rt", O_RDONLY);
	if (fd == -1)
		return (false);
	file = read_fd(fd);
	if (!file)
		return (false);
	close(fd);
	ptr = file;
	while (file)
	{
		if (!skip_line(file->line))
		{
			if (!parse_object(file->line, scene))
				return (clear_content(ptr), false);
		}
		file = file->next;
	}
	clear_content(ptr);
	if (!scene->ambient || !scene->camera || !scene->light)
		return (broadcast(ERR_ELEMENT_MISSING, NULL));
	return (true);
}
