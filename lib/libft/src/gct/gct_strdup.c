/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gct_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:24:43 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/11 20:58:52 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gct_strdup(const char *src)
{
	int		i;
	char	*dst;

	i = -1;
	dst = gct_malloc(ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
