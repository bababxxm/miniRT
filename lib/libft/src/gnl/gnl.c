/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:11:24 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/01 21:41:03 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*new_buffer(char *buf);
void	add_buffer(t_gnl **content, t_gnl *new);
void	clear_buffer(t_gnl *content);

bool	has_newline(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (false);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

void	get_buffer(int fd, t_gnl **content)
{
	int		cnt;
	char	*buf;
	t_gnl	*new;

	buf = malloc(BUFFER_SIZE + 1);
	while (1)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
			break ;
		else if (cnt == 0)
			break ;
		buf[cnt] = '\0';
		new = new_buffer(buf);
		if (!new)
			break ;
		add_buffer(content, new);
		if (has_newline(buf))
			break ;
	}
	free(buf);
}

int	get_line_size(t_gnl *content)
{
	int		i;
	int		cnt;
	char	*buf;

	cnt = 0;
	while (content)
	{
		i = content->idx;
		buf = content->buffer;
		while (i < content->len)
		{
			cnt++;
			if (buf[i++] == '\n')
				return (cnt);
		}
		content = content->next;
	}
	return (cnt);
}

char	*extract_line(t_gnl **content)
{
	int		i;
	int		cnt;
	char	*line;
	t_gnl	*tmp;

	tmp = *content;
	cnt = get_line_size(tmp);
	if (cnt == 0)
		return (clear_buffer(tmp), NULL);
	line = malloc(sizeof(*line) * (cnt + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (*content && i < cnt)
	{
		tmp = *content;
		while (tmp->idx < tmp->len && i < cnt)
			line[i++] = tmp->buffer[tmp->idx++];
		if (i == cnt)
			break ;
		*content = (*content)->next;
		clear_buffer(tmp);
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_gnl	*content[1024];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	get_buffer(fd, &content[fd]);
	if (!content[fd])
		return (NULL);
	line = extract_line(&content[fd]);
	return (line);
}
