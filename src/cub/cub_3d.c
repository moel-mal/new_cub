/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:06:57 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/03 12:08:09 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int    ft_cub3d(char *av)
{
	initiale();
	if (ft_read_file(av) == -1)
		return (-1);
	if (ft_game() == -1)
		return(-1);
   return (0);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7))
		{
			//screenshot
		}
		else
		{
			printf("wrong argument");
			return (-1);
		}
	}
	if (ac == 3 || ac == 2)
	{
		if (ft_check_cub(av[1], ".cub") != 1)
			printf("wrong file");
		 else
			 return (ft_cub3d(av[1]));
		return 0;
	}
	else
		printf("wrong n: arg");
}