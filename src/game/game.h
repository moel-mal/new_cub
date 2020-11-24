/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:02:25 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/24 20:21:15 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAME_H
# define GAME_H

#include "../cub/cub3d.h"

struct          s_wall
{
    int down;
    int right;
    int x;
    int y;
}               g_wall;


int ft_game();
//tools.c
void ft_put_player();
void    ft_select_player(int x, int y, int r);
void    ft_draw_feld_view(void);
double ft_0_to_2pi(double angle);



// draw.c
void    ft_draw_cub(int x, int y, int size);
void    ft_draw_cercle(int x, int y, int size);
void    ft_draw_ray(int x, int y, int size, double angle);
void    ft_draw_rect(int x, int y, int heigh, int width);

//map.c
int     ft_put_map(void);

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


#endif