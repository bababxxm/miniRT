/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:41:48 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/15 23:07:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(void **head, void *node)
{
	t_list	*new;
	t_list	**lst;

	new = node;
	lst = (t_list **)head;
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}
