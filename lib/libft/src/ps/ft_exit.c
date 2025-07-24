/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:44:09 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/16 11:44:46 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(char *str, int exitcode)
{
	int	fd;

	if (exitcode == 0)
		fd = 1;
	else
		fd = 2;
	if (!str)
		exit(exitcode);
	ft_putendl_fd(str, fd);
	exit(exitcode);
}
