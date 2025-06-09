/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:24:19 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/09 01:56:33 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	parse_object(t_rt *minirt, char *line)
{
	int		idtf;
	char	**args;
	
	args = ft_split(line, ' ');
	if (!args)
		ft_perror("Error: ft_split");
	idtf = which_identifer(args[0]);
	if (idtf == UNRECOGNIZED)
		return (false);
	else if (idtf == AMBIENT)
		return (parse_ambient(minirt, args));
	else if(idtf == CAMERA)
		return (parse_camera(minirt, args));
	else if (idtf == LIGHT)
		return (parse_light(minirt, args));
	// else if (idtf == SPHERE)
	// 	return (parse_sphere(minirt, args));
	// else if (idtf == PLANE)
	// 	return (parse_plane(minirt, args));
	// else if (idtf == CYLINDER)
	// 	return (parse_cylinder(minirt, args));
	return (true);
}

static void	read_file(t_rt *minirt, int fd)
{
	char	*line;
	t_list	*read;

	read = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '#')
		{
			free(line);
			continue ;
		}
		if (!parse_object(minirt, line))
			ft_perror("Error: invalid format.");
		ft_lstadd_back((void **)&read,
			ft_lstnew((void *)ft_strdup(line)));
		free(line);
	}
}

void	parse_file(t_rt *minirt, char *title)
{
	int	fd;

	fd = open(title, O_RDONLY);

	while (*title && *title != '.')
		title++;
	if (ft_strcmp(title, ".rt") != 0)
		ft_perror("Error: illegal file extension.");

	ft_putendl_fd("[OK] file name is valid.", 1);

	if (fd == -1)
		ft_perror("Error: unable to open given file.");

	ft_putendl_fd("[OK] file is opened.", 1);

	read_file(minirt, fd);

	ft_putendl_fd("[OK] file is read.", 1);

	close(fd);
}