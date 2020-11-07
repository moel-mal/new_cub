/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:05:21 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/02 18:41:09 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int ft_game()
{
    g_cub.mlx = mlx_init();
    g_cub.win = mlx_new_window(g_cub.mlx, g_cub.resolution.x, g_cub.resolution.y, "cub3d");
    ft_put_map();
    ft_put_player();
   //mlx_key_hook (g_cub.win, deal_key,g_cub.mlx);
    mlx_hook(g_cub.win, 2, 0, on_keypress, NULL);
    mlx_hook(g_cub.win, 3, 0, on_keyup, NULL);
    mlx_loop_hook(g_cub.mlx, deal_key, NULL);
    mlx_loop(g_cub.mlx);
    return (0);
}