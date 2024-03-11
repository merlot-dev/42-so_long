/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:05:22 by josegar2          #+#    #+#             */
/*   Updated: 2024/03/11 12:01:17 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	usage(char **argv)
{
	ft_printf("Usage: %s <fichero.ber>\n", argv[0]);
	return (1);
}

int	check_file_name(char *fn)
{
	char	*ext;

	ext = ft_substr(fn, ft_strlen(fn) - 4, 4);
	if (ft_strcmp(ext, ".ber"))
		return ((int)ft_free(ext) + 1);
	return ((int)ft_free(ext));
}

int	exit_game(t_game *g)
{
	destroy_elements(g);
	mlx_destroy_window(g->x.mlx, g->x.win);
	exit(0);
}

// left: 123, right:124, up:126, down:125
// a:0, s:1, w:13, z:6
int	hook_handler(int keycode, t_game *g)
{
	if (keycode == 53)
	{
		exit_game(g);
	}
	if (key_moves(keycode, g))
	{
		exit_game(g);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	if (argc != 2 || check_file_name(argv[1]))
		return (usage(argv));
	if (sl_load_map(argv[1], &g.m))
		return (1);
	if (init_map(&g))
		return (1);
	g.x.mlx = mlx_init();
	g.x.win = mlx_new_window(g.x.mlx, g.x.winx, g.x.winy, "PACMAN revenge");
	if (draw_map(&g))
	{
		destroy_elements(&g);
		return (sl_error_free(&g.m, "Check xpm image files\n"));
	}
	mlx_hook(g.x.win, 2, 0, hook_handler, &g);
	mlx_hook(g.x.win, 17, 0, exit_game, &g);
	mlx_loop_hook(g.x.mlx, sl_anime, &g);
	mlx_loop(g.x.mlx);
}
