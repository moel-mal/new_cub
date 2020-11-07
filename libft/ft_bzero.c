/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:56:54 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/23 05:04:20 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int					i;
	unsigned	char	*rtn;

	rtn = s;
	i = 0;
	while (i < (int)n)
	{
		rtn[i] = 0;
		i++;
	}
	s = rtn;
}