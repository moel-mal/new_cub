/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:13:34 by moel-mal          #+#    #+#             */
/*   Updated: 2021/02/20 10:05:14 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int ft_get_texture_1(int x, int y)
{
    if (g_wall.down == 0 && g_wall.v == 0)
            return (0xFFFF00);
    if (g_wall.down == 1 && g_wall.v == 0)
            return (0xFFFFFF);
    if (g_wall.right == 1 && g_wall.v == 1)
        return (0x808080);
    if (g_wall.right == 0 && g_wall.v == 1)
        return (0x808000);
    return (0);
}