/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:54:55 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/16 15:37:38 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strskip(char *s, char *set, bool is_in_set)
{
	if (!s)
		return (NULL);
	if (is_in_set)
	{
		while (*s && ft_strchr(set, *s))
			s++;
		return (s);
	}
	else
	{
		while (*s && !ft_strchr(set, *s))
			s++;
		return (s);
	}
}
