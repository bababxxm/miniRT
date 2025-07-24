/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:42:20 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/15 23:07:29 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(void **head, void *node)
{
	t_list	*new;
	t_list	**lst;

	new = node;
	lst = (t_list **)head;
	if (!*lst && new)
		*lst = new;
	else if (*lst && new)
		ft_lstlast(*lst)->next = new;
}
