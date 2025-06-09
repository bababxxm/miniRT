/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:34:44 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/10 02:04:05 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*

	git branch 'sklaokli'

*/

static void	parser(t_scene *scene, int argc, char **argv)
{
	parse_argument(argc, argv);
	parse_file(scene, argv[1]);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	parser(&scene, argc, argv);
	return (0);
}
