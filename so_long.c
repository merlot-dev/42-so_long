/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:02:36 by josegar2          #+#    #+#             */
/*   Updated: 2024/02/27 18:20:23 by josegar2         ###   ########.fr       */
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
	t_img	im;
	int		i;

	if (argc != 2 || check_file_name(argv[1]))
		return (usage(argv));
	if (sl_load_map(argv[1], &g.m))
		return (1);
	g.x.mlx = mlx_init();
	g.x.win = mlx_new_window(g.x.mlx, WINDOWX, WINDOWY, "Hello world!");
	im.img = mlx_new_image(g.x.mlx, WINDOWX, WINDOWY);
	im.addr = mlx_get_data_addr(im.img, &im.bpp, &im.ll, &im.endian);
	i = -1;
	while (++i < WINDOWY)
		my_mlx_pixel_put(&im, i, i, 0x00FF0000);
	mlx_put_image_to_window(g.x.mlx, g.x.win, im.img, 0, 0);
	mlx_destroy_image(g.x.mlx, im.img);
	im.img = mlx_xpm_file_to_image(g.x.mlx, "sprites/pacman-dw.xpm", &im.w, &im.h);
	mlx_put_image_to_window(g.x.mlx, g.x.win, im.img, 0, 0);
	im.img = mlx_xpm_file_to_image(g.x.mlx, "sprites/pacman20-dw.xpm", &im.w, &im.h);
	mlx_put_image_to_window(g.x.mlx, g.x.win, im.img, 0, 40);
	im.img = mlx_xpm_file_to_image(g.x.mlx, "sprites/ghost20-red-dw.xpm", &im.w, &im.h);
	mlx_put_image_to_window(g.x.mlx, g.x.win, im.img, 0, 60);
	im.img = mlx_xpm_file_to_image(g.x.mlx, "sprites/ghost-red-dw.xpm", &im.w, &im.h);
	mlx_put_image_to_window(g.x.mlx, g.x.win, im.img, 0, 80);
	mlx_hook(g.x.win, 2, 0, hook_handler, &g.x);
	mlx_hook(g.x.win, 17, 0, exit_game, &g.x);
	mlx_loop(g.x.mlx);
}
