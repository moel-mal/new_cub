/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 02:51:21 by moel-mal          #+#    #+#             */
/*   Updated: 2020/10/20 17:11:26 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 128

int				get_next_line(const int fd, char **line);
char			*check_ft(char *save, char **line);
void			help(char *buff, char **line);
int				first_ft(char **save, char *buff, int fd, char **line);

#endif
