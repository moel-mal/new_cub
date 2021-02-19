/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:02:25 by moel-mal          #+#    #+#             */
/*   Updated: 2021/02/19 19:07:29 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAME_H
# define GAME_H

#include "../cub/cub3d.h"

struct          s_wall
{
    int down;
    int right;
    int v;
}               g_wall;

void game_2D(void);
int ft_game();
//tools.c
void    ft_put_player();
void    ft_select_player(int x, int y, int r);
void    ft_draw_feld_view(void);
double  ft_0_to_2pi(double angle);



// draw.c
void    ft_draw_cub(int x, int y, int size);
void    ft_draw_cercle(int x, int y, int size);
void    ft_draw_ray(int x, int y, int size, double angle);
void    ft_draw_rect(int x, int y, int heigh, int width);

//map.c
int     ft_put_map(void);
int     ft_tile_size();

//keys 
int     deal_key(int key, void *prm);
void    ft_move_player(void);
int		on_keypress(int key);
int		on_keyup(int key);
int     ft_detect_wall_colision(int x, int y);

//raycasting
float ft_horizontale(double angle);
float raycasting(double angle);

//draw_walls
void game_3D(void);

//texture
int ft_get_texture_1(int x, int y);


#endif