/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:02:36 by josegar2          #+#    #+#             */
/*   Updated: 2024/02/28 22:40:59 by josegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	exit_game(int keycode, t_mlx *mx)
{
	keycode += 0;
// free everything
	mx->col += 0;
	exit(0);
}

// left: 123, right:124, up:126, down:125
// a:0, s:1, w:13, z:6
int hook_handler(int keycode, t_mlx *mx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mx->mlx, mx->win);
		exit_game(keycode, mx);
	}
	ft_printf("Hook. keycode: %d      %d\n", keycode, mx->col);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2 || check_file_name(argv[1]))
		return (usage(argv));
	if (sl_load_map(argv[1], &g.m))
		return (1);
	g.x.mlx = mlx_init();
	g.x.win = mlx_new_window(g.x.mlx, WINDOWX, WINDOWY, "PACMAN revenge");
	draw_map(g.x);
	mlx_hook(g.x.win, 2, 0, hook_handler, &g.x);
	mlx_hook(g.x.win, 17, 0, exit_game, &g.x);
	mlx_loop(g.x.mlx);
}
