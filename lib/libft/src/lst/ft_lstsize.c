/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:42:00 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/15 21:55:05 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(void *ptr)
{
	int		cnt;
	t_list	*lst;

	cnt = 0;
	lst = ptr;
	while (lst)
	{
		cnt++;
		lst = lst -> next;
	}
	return (cnt);
}
