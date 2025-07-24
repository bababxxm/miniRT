/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:42:10 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/15 22:08:08 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(void *ptr)
{
	t_list	*lst;

	lst = (t_list *)ptr;
	while (lst && lst -> next)
		lst = lst -> next;
	return ((void *)lst);
}
