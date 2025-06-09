/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:34:44 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/09 00:18:54 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parser(t_rt *minirt, int argc, char **argv)
{
	parse_argument(argc, argv);
	parse_file(minirt, argv[1]);
}

int	main(int argc, char **argv)
{
	t_rt	minirt;

	parser(&minirt, argc, argv);
	return (0);
}
