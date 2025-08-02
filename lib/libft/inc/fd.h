/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:31:24 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/02 21:08:13 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_H
# define FD_H

# include "list.h"

typedef struct s_file
{
	int			descriptor;
	char		*path;
	int			o_flags;
	t_list		*content;
}	t_file;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);

int		open_fd(char *path, char *extension, int o_flags);
t_file	*open_file(char *path, char *extension, int o_flags);
int		read_file(t_file *file);
void	close_file(t_file *file);

#endif