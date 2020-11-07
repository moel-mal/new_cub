/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:06:46 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/03 12:07:41 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_check_cub(char *tab, char *cub)
{
	// -> libft
	int i;
	int j;

	i = ft_strlen(tab);
	j = 0;
	if ((!tab) || (!cub))
		return (-1);
	while (j < 4)
	{
		if (tab[i + j - 4] != cub[j])
			return (0);
		j++;
	}
	return (1);
}