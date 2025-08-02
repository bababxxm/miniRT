/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:06:26 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/02 21:27:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_file(t_file *file)
{
	int		fd;
	char	*line;
	t_list	*content;

	if (!file || file->descriptor < 0)
		return (0);
	fd = file->descriptor;
	content = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back((void **)&content, ft_lstnew(line));
	}
	file->content = content;
	return (1);
}
