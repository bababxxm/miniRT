/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:00:10 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/08 20:04:24 by sklaokli         ###   ########.fr       */
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

#endif