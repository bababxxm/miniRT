/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:06:23 by sklaokli          #+#    #+#             */
/*   Updated: 2025/08/02 21:09:10 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	close_file(t_file *file)
{
	if (!file)
		return ;
	if (file->content)
		ft_lstclear((void **)&file->content, free);
	if (file->descriptor >= 0)
		close(file->descriptor);
	free(file->path);
	free(file);
}
