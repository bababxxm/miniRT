/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gct_split_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:57:46 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/11 21:01:24 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *str, char *set)
{
	int	i;
	int	cnt;
	int	in_word;

	i = 0;
	cnt = 0;
	in_word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

char	**gct_split_set(char *str, char *set)
{
	int		i[2];
	int		len;
	int		start;
	char	**split;

	len = count_word(str, set);
	if (len < 1)
		return (NULL);
	split = gct_malloc(sizeof(char *) * (len + 1));
	if (!split)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (str[i[0]])
	{
		while (str[i[0]] && ft_strchr(set, str[i[0]]))
			i[0]++;
		start = i[0];
		while (str[i[0]] && !ft_strchr(set, str[i[0]]))
			i[0]++;
		if (i[0] > start)
			split[i[1]++] = gct_strndup(str + start, i[0] - start);
	}
	split[i[1]] = NULL;
	return (split);
}
