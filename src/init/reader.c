/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:24:19 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/02 21:41:56 by sklaokli         ###   ########.fr       */
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

bool	parse_scene(t_file *file, t_scene *scene)
{
	char	*line;
	t_list	*lines;

	lines = file->content;
	while (lines)
	{
		line = (char *)lines->content;
		if (*line != '#' && *line != '\n')
		{
			if (!parse_object(line, scene))
				return (false);
		}
		lines = lines->next;
	}
	if (!scene->ambient || !scene->camera || !scene->light)
		return (broadcast(ERR_ELEMENT_MISSING, NULL));
	return (true);
}
