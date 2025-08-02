/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:13:44 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/02 21:06:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file	*open_file(char *path, char *extension, int o_flags)
{
	int		fd;
	t_file	*file;

	if (!path)
		return (NULL);
	fd = open_fd(path, extension, o_flags);
	if (fd < 0)
		return (NULL);
	file = malloc(sizeof(t_file));
	if (!file)
	{
		close(fd);
		return (NULL);
	}
	file->descriptor = fd;
	file->path = ft_strdup(path);
	file->o_flags = o_flags;
	file->content = NULL;
	return (file);
}
