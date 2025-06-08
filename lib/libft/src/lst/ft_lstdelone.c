/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:42:34 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/15 21:57:56 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(void *ptr, void (*del)(void*))
{
	t_list	*lst;

	lst = ptr;
	if (lst && del)
	{
		del(lst -> content);
		free(lst);
	}
}
