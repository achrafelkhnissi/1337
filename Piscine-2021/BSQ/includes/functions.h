/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:47:00 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 17:47:02 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "global_vars.h"

t_square	*ft_get_obstacles(void);
void		ft_highlight_biggest_square(void);
char		**ft_split(char *str, char *charset);
int			ft_core(void);
int			ft_obs_count(void);
int			ft_square_valid(t_square square);
int			ft_atoi(char *str, int i);
int			ft_min(int a, int b);
int			ft_strlen(char *str);
int			ft_map_valid(char **map);
int			ft_break(char **map);
int			ft_length(char **map);
void		ft_extract(char *str);
int			ft_onlychar(char **map);
int			ft_char_exists(char c, char *str);
int			ft_charset(char *str);
void		ft_puterr(char *str);
char		**stdin_to_stdout(void);
char		**read_input(char *input);
void		ft_putchar(char c);
void		ft_show_board(void);
void		ft_reset_g_values(void);
void		ft_init_g_values(char **map);
void		ft_bsq(char **map);
void		ft_handle_stdin(void);
void		ft_handle_file(char *file_name);

#endif
