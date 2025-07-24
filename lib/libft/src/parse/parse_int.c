/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:37:09 by sklaokli          #+#    #+#             */
/*   Updated: 2025/07/01 22:37:41 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	parse_int(int *ptr, char *str, int min, int max)
{
	long	nbr;
	char	*start;

	if (!str)
		return (false);
	str = ft_strskip(str, WHITESPACE, true);
	start = str;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '+' || *str == '-' || !ft_isdigit(*str))
		return (false);
	str = ft_strskip(str, "0123456789", true);
	str = ft_strskip(str, WHITESPACE, true);
	if (*str != '\0')
		return (false);
	nbr = ft_atol(start);
	if (nbr < min || nbr > max)
		return (false);
	*ptr = (int)nbr;
	return (true);
}
