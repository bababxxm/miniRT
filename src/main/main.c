/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:07:09 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/08 17:46:34 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_rt	*rt;

	rt = gct_malloc(sizeof(t_rt));
	printf("%p\n", &rt);
	gct_cleanup();
	printf("dawd");
	return (0);
}