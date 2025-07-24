/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:02:25 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/05 18:25:09 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_valid_extension(char *name, char *extension)
{
	while (*name && *name != '.')
		name++;
	if (ft_strcmp(name, extension))
		return (false);
	return (true);
}

t_content	*new_content(char *line)
{
	t_content	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (free(line), NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

static void	add_content(t_content **content, t_content *new)
{
	if (!new)
	{
		clear_content(*content);
		ft_panic("Error: unable to add new content");
	}
	ft_lstadd_back((void **)content, (void *)new);
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

t_content	*get_content_fd(char *name, char *extension, int o_flags)
{
	int			fd;
	char		*line;
	t_content	*new;
	t_content	*content;

	if (!name || !extension)
		return (NULL);
	fd = open(name, o_flags);
	if (fd == -1)
		ft_panic("Error: unable to open given file");
	if (!is_valid_extension(name, extension))
		ft_panic("Error: illegal file extension");
	content = NULL;
	line = get_next_line(fd);
	while (line)
	{
		new = new_content(line);
		add_content(&content, new);
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}
