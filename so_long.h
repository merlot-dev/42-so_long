/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:11:54 by josegar2          #+#    #+#             */
/*   Updated: 2024/02/26 23:42:22 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WINDOWX 1920
# define WINDOWY 1080

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>

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
	int		bpp;
	int		ll;
	int		endian;
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

int		sl_error(const char *info);
int		free_map(t_map *m);
int		sl_error_free(t_map *m, const char *info);
int		sl_load_map(char *fn, t_map *m);
int		check_path(t_map *m);

#endif
