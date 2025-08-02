/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:03:53 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/02 21:04:00 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	open_fd(char *path, char *extension, int o_flags)
{
	int		fd;
	char	*dot;

	fd = open(path, o_flags);
	if (fd == -1)
		return (-1);
	if (extension)
	{
		dot = ft_strrchr(path, '.');
		if (!dot || ft_strcmp(dot, extension) != 0)
		{
			close(fd);
			return (-2);
		}
	}
	return (fd);
}
