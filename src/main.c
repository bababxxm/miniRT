/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:07:09 by sklaokli          #+#    #+#             */
/*   Updated: 2025/06/06 20:08:18 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_perror(char *msg)
{
	if (msg)
	{
		while (*msg)
			write(2, msg++, 1);
		write(2, "\n", 1);
	}
	exit(1);
}

int	parse_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[i])
	{
		if (*argv[i] == '\0')
			return (0);
		i++;
	}
	i = 0;
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (ft_strcmp(&argv[1][i], ".rt"))
		ft_perror("Error: illegal file extension");
	return (1);
}

// void    init(t_rt *minirt, t_file *file)
// {
    
// }

t_list	*read_file(int fd)
{
	char	*line;
	t_list	*list;

	list = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '#')
		{
			free(line);
			continue ;
		}
		ft_lstadd_back((void **)&list,
			(void *)ft_lstnew(line));
	}
	return (list);
}

int	parse_file(t_file *file, char *name)
{
	file->fd = open(name, O_RDONLY);
	if (file->fd == -1)
		return (0);
	file->read = read_file(file->fd);
	return (1);
}

void    parser(t_rt *minirt, int argc, char **argv)
{
	if (!parse_arguments(argc, argv))
		ft_perror("Error: parsing arguments");
	if (!parse_file(&minirt->file, argv[1]))
		ft_perror("Error: parsing file");
}

int	main(int argc, char **argv)
{
	t_rt	minirt;

	parser(&minirt, argc, argv);
	// init(&minirt, &minirt.file);
	return (0);
}