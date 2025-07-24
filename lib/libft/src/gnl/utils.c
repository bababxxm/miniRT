/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:11:38 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/01 21:40:51 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*new_buffer(char *buf)
{
	t_gnl	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->idx = 0;
	new->len = ft_strlen(buf);
	new->buffer = ft_strdup(buf);
	new->next = NULL;
	return (new);
}

void	add_buffer(t_gnl **content, t_gnl *new)
{
	t_gnl	*last;

	if (!*content && new)
		*content = new;
	else if (*content && new)
	{
		last = *content;
		while (last && last->next)
			last = last->next;
		last->next = new;
	}
}

void	clear_buffer(t_gnl *content)
{
	free(content->buffer);
	free(content);
}
