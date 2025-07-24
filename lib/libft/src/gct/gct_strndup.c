/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gct_strndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:36:04 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/11 20:55:11 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gct_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	dup = (char *)gct_malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
