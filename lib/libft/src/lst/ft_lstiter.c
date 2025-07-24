/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:42:59 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/15 23:07:44 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(void *ptr, void (*f)(void *))
{
	t_list	*lst;

	lst = ptr;
	while (f && lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
