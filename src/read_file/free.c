/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 11:16:00 by moel-mal          #+#    #+#             */
/*   Updated: 2020/10/20 17:26:29 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

void free_2d(char **tab)
{
    int i;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}