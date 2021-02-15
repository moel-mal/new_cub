/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:05:21 by moel-mal          #+#    #+#             */
/*   Updated: 2021/02/14 19:16:48 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void game_2D(void)
{
    ft_put_map();
    ft_put_player();
}

int ft_game()
{
    g_cub.mlx = mlx_init();
    g_cub.win = mlx_new_window(g_cub.mlx, g_cub.resolution.x, g_cub.resolution.y, "cub3d");
    g_cub.img.img = mlx_new_image(g_cub.mlx, g_cub.resolution.x, g_cub.resolution.y);
    g_cub.img.data = (int *)mlx_get_data_addr(g_cub.img.img, &g_cub.img.bits_per_pixel,
	 		&g_cub.img.line_length, &g_cub.img.endian);
    //game_2D();
    game_3D();
    mlx_put_image_to_window(g_cub.mlx, g_cub.win, g_cub.img.img, 0, 0);
    //mlx_key_hook (g_cub.win, deal_key,g_cub.mlx);
    mlx_hook(g_cub.win, 2, 0, on_keypress, NULL);
    mlx_hook(g_cub.win, 3, 0, on_keyup, NULL);
    mlx_loop_hook(g_cub.mlx, deal_key, NULL);
    mlx_loop(g_cub.mlx);
    return (0);
}
