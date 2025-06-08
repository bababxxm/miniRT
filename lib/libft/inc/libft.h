/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:57:13 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/08 17:13:09 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>

# include "gnl.h"
# include "gct.h"

# define WHITESPACE "\t\n\v\f\r "

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}	t_list;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_abs(int n);
bool	ft_isint(long nbr);

size_t	ft_strlen(const char *s);
size_t	ft_strlen_c(char *str, char c);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strskip(char *s, char *set, bool is_in_set);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strtrim(char const *s, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char *s, char sep);

char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *ptr);

void	*ft_malloc(size_t size);
void	*ft_calloc(size_t n, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_free(void *ptr);
void	ft_free_2d(void **matrix);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);

t_list	*ft_lstnew(void *content);
int		ft_lstsize(void *ptr);
t_list	*ft_lstlast(void *ptr);
void	ft_lstadd_front(void **head, void *node);
void	ft_lstadd_back(void **head, void *node);
void	ft_lstiter(void *ptr, void (*f)(void *));
void	ft_lstdelone(void *ptr, void (*del)(void*));
void	ft_lstclear(void **ptr, void (*del)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_exit(char *str, int exitcode);
int		ft_fork(void);
void	ft_panic(char *str);

#endif