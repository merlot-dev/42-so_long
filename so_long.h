/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:11:54 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/01 17:47:51 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>

# define WINDOWX 1280
# define WINDOWY 800
# define SIDEX 999

# define TITLE "sprites/pacman-revenge.xpm"
# define MOVES "sprites/txt-moves.xpm"
# define COLLS "sprites/txt-colls.xpm"
# define GAMEOVER "sprites/txt-gameover.xpm"

# define CELLDIM 44

# define LWALL "sprites/wall-lf.xpm"
# define RWALL "sprites/wall-rg.xpm"
# define UWALL "sprites/wall-up.xpm"
# define DWALL "sprites/wall-dw.xpm"

# define PACMAN "sprites/pacman.xpm"
# define BLINKY "sprites/ghost-red.xpm"
# define INKY "sprites/ghost-blue.xpm"
# define CLYDE "sprites/ghost-orange.xpm"
# define PINKY "sprites/ghost-pink.xpm"
# define PILL "sprites/pill.xpm"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		winx;
	int		winy;
	int		row;
	int		col;
}			t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		ll;
	int		end;
}			t_img;

typedef struct s_map
{
	int		cols;
	int		rows;
	char	**maps;
	int		stx;
	int		sty;
	int		endx;
	int		endy;
	int		coll;
}			t_map;

typedef struct s_game
{
	t_mlx	x;	// all mlx related
	t_img	*mi; // map image
	t_img	*gi;	// game image
	t_map	m;
	int		sc;
	int		dim;
}			t_game;

int		sl_error(const char *info);
int		free_map(t_map *m);
int		sl_error_free(t_map *m, const char *info);
int		sl_load_map(char *fn, t_map *m);
int		check_path(t_map *m);
t_img   get_xpm_img(t_mlx mx, char *fn);
t_img   cut_img(t_mlx mx, t_img im, int st[2], int sz[2]);
int		draw_map(t_game *g);

#endif
