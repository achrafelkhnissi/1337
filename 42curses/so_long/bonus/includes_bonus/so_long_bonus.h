/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:55:17 by ael-khni          #+#    #+#             */
/*   Updated: 2022/01/12 09:19:51 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "mlx.h"

/* -------- KEY VALUES -------- */
# define RIGHT_KEY 2
# define LEFT_KEY 0
# define DOWN_KEY 1
# define UP_KEY 13
# define ESC_KEY 53
# define WIN_CLOSE 17

/* -------- MAP -------- */
# define BUFF_SIZE 256
# define WALL '1'
# define EMPTY '0'
# define COL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'X'
# define SQUARE 32

/* -------- ERRORS -------- */
# define MALLOC_ERROR "so_long: Malloc failed to allocate enough memory."
# define DIR_ERROR "Is a directory!." 

/* -------- COLORS -------- */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

/* ----- ENEMY ANIMATION FRAME ---- */
# define FRAME 7

/* -------- STRUCTURES -------- */

// vector with x and y
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

// all info needed for the map
typedef struct s_map
{
	char		**map;
	int			col;
	int			row;
	int			collectibles;
	int			number_of_enemies;
	t_vector	*enemy;
	t_vector	player;
}				t_map;

// all info needed for the whole program
typedef struct s_program
{
	void		*mlx;
	void		*win_ptr;
	void		*img_ptr;
	int			img_size;
	t_map		map;
	int			fd;
	int			can_exit;
	size_t		mv_count;
}				t_program;	

/* -------- SO_LONG FUNCTIONS-------- */
void	display_banner(void);
int		ft_render_images(void *param);
int		ft_render_enemy(void *param);
void	ft_new_window(t_program *game);
int		ft_input(int key, void *program);
void	ft_free(t_program *game, char *msg);
void	free_map(t_program *game);
char	*ft_get_image(char c, int can_exit);
void	reset_struct(t_program *game);
char	*ft_itoa(int n);

/* -------- MOVEMENTS FUNCTIONS-------- */
void	move_up(t_program *game);
void	move_down(t_program *game);
void	move_right(t_program *game);
void	move_left(t_program *game);

/* -------- PARSER FUNCTIONS --------*/
void	get_map(char *file_name, t_program *game);
void	check_map(char *file_name, t_program *game);
void	check_dir(char *file_name);
int		check_characters(t_program game);
int		check_player(t_program game);
int		check_ecp(t_program game);
int		check_extention(const char *haystack, const char *needle);
int		check_rectangular(t_program game);
int		check_walls(t_program *game);
void	get_collectibles(t_program *game);
void	get_player_position(t_program *game);
int		map_len(int fd);
int		ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
void	error(int err);

/* -------- ERROR FUNCTIONS --------*/
void	err_extention(char *file_name);
void	err_rectangular(t_program *game, char *file_name);
void	err_characters(t_program *game, char *file_name);
void	err_walls(t_program *game, char *file_name);
void	err_ecp(t_program *game, char *file_name);
void	err_player(t_program *game, char *file_name);

/* get_next_line functions */
char	*func(char **line, char **tmp, int nl);
char	*get_next_line(int fd);
int		check_newline(char *buff);
size_t	ft_strlen(const char *s);
char	*get_reminder(char **str, int nl);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

/* ---- Test enemy movments ---- */
void	enemy_moves(t_program *game);
void	count_number_of_enemies(t_program *game);
void	get_enemies_positions(t_program *game);
void	ft_swap(char *a, char *b);

#endif
