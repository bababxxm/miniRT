/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gct_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:58:47 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/11 20:59:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gct_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (gct_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s += start;
	res = (char *)gct_malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s, len + 1);
	return (res);
}
