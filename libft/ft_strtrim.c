/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:54:29 by moel-mal          #+#    #+#             */
/*   Updated: 2019/10/24 14:41:53 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char const *str, char se)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == se)
			return (1);
		i++;
	}
	return (0);
}

static int		cal_size(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0')
	{
		if (check(set, s1[i]) == 1)
			i++;
		else
			break ;
	}
	while (j >= 0)
	{
		if (check(set, s1[j]) == 1)
		{
			i++;
			j--;
		}
		else
			break ;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		i;
	int		j;
	int		size;

	if (!s1)
		return (NULL);
	if (cal_size(s1, set) > (int)ft_strlen(s1))
	{
		if (!(tab = malloc(sizeof(char) * (1))))
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	size = ft_strlen(s1) - cal_size(s1, set);
	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (check(set, s1[i]) == 1)
		i++;
	while (j < size)
		tab[j++] = (char)s1[i++];
	tab[j] = '\0';
	return (tab);
}
