/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:13:34 by moel-mal          #+#    #+#             */
/*   Updated: 2021/01/06 18:16:56 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int ft_get_texture(int x, int y)
{
    if (g_wall.down == 1)
        return (0xFFFFFF);
    if (g_wall.down == 0)
        return (0xC0C0C0);
    if (g_wall.right == 0)
        return (0x800080);
    if (g_wall.right == 1)
        return (0x000080);
}