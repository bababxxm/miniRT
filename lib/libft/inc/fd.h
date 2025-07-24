/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:31:24 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/02 01:28:42 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_H
# define FD_H

typedef struct s_content
{
	struct s_content	*next;
	char				*line;
}	t_content;

typedef struct s_file
{
	int			fd;
	char		*name;
	t_content	*content;
}	t_file;

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
t_content	*get_content_fd(char *name, char *extension, int o_flags);
void		clear_content(t_content *content);

#endif