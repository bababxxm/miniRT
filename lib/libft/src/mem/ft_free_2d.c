/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:28:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/15 23:07:49 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d(void **matrix)
{
	int	idx;

	if (!matrix)
		return ;
	idx = 0;
	while (matrix[idx])
		ft_free(matrix[idx]);
	ft_free(matrix);
}
