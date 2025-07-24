/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:40:18 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/17 02:02:15 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	open_fd(char *path, char *extension, int o_flags)
{
	int	fd;

	fd = open(path, o_flags);
	if (fd == -1)
		return (-1);
	while (*path && *path != '.')
		path++;
	if (ft_strcmp(path, extension))
		return (-1);
	return (fd);
}

t_content	*new_content(char *line)
{
	t_content	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->line = ft_strdup(line);
	new->next = NULL;
	return (new);
}

void	add_content(t_content **content, t_content *new)
{
	ft_lstadd_back((void **)content, (void *)new);
}

t_content	*read_fd(int fd)
{
	char		*line;
	t_content	*file;

	file = NULL;
	line = get_next_line(fd);
	while (line)
	{
		add_content(&file, new_content(line));
		free(line);
		line = get_next_line(fd);
	}
	return (file);
}

void	clear_content(t_content *content)
{
	t_content	*tmp;

	while (content)
	{
		tmp = content;
		content = content->next;
		free(tmp->line);
		free(tmp);
	}
}
