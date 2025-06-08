/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:42:46 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/15 22:08:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(void **ptr, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*node;
	t_list	**lst;

	if ((!del))
		return ;
	lst = (t_list **)ptr;
	node = *lst;
	while (node)
	{
		tmp = node;
		node = node -> next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
