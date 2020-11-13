/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 11:25:01 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/07 03:37:32 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "read_file.h"


static int		call_size(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
static int ft_module_16(int n)
{
	if (n > 9)
		return (n + 7 + '0');
	else
		return (n + '0');
}

static char *ft_itoa_16(int n)
{
	long	p;
	long	s;
	char	*tab;

	s = (long)n;
	p = call_size(n);
	if (s < 0)
		s = -s;
	tab = malloc(sizeof(char) * p + 1);
	if (!tab)
		return (NULL);
	tab[p] = '\0';
	p--;
	if (s == 0)
		tab[p] = '0';
	while (p + 1 != 0 && s != 0)
	{
		tab[p] = ft_module_16((s % 16));
		s = s / 16;
		p--;
	}
	if (n < 0)
		tab[0] = '-';
	return (tab);
}

char *ft_hexa(char *tab)
{
    int nb;
    // printf("dddddddd\n");
    nb = ft_atoi(tab);
    tab = ft_itoa_16(nb);
	if (ft_strlen(tab) < 2)
		tab = ft_strjoin("0", tab);
	else if (ft_strncmp(tab, "0", 2) == 0)
	{
		tab = ft_strdup("00");
	}
    return (tab);
}