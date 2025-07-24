/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:00:10 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/11 21:00:56 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCT_H
# define GCT_H

# include "stdio.h"
# include "stdlib.h"

typedef struct s_gct
{
	struct s_gct	*next;
	void			*ptr;
}	t_gct;

void	*gct_malloc(size_t size);
void	gct_cleanup(void);

char	*gct_strdup(const char *src);
char	*gct_strndup(const char *s, size_t n);
char	*gct_strtrim(char const *s, char const *set);
char	*gct_strjoin(char const *s1, char const *s2);
char	*gct_substr(char const *s, unsigned int start, size_t len);
char	**gct_split(char *s, char sep);
char	**gct_split_set(char *str, char *set);

#endif