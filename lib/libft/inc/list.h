/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:32:58 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/01 22:33:18 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}	t_list;

t_list	*ft_lstnew(void *content);
int		ft_lstsize(void *ptr);
t_list	*ft_lstlast(void *ptr);
void	ft_lstadd_front(void **head, void *node);
void	ft_lstadd_back(void **head, void *node);
void	ft_lstiter(void *ptr, void (*f)(void *));
void	ft_lstdelone(void *ptr, void (*del)(void*));
void	ft_lstclear(void **ptr, void (*del)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif