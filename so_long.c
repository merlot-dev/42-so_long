/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:02:36 by josegar2          #+#    #+#             */
/*   Updated: 2024/02/26 23:43:46 by josegar2         ###   ########.fr       */
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

int hook_handler(int keycode, t_mlx *mx)
{
	ft_printf("Hook. keycode: %d      %d\n", keycode, mx->col);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	x;
	t_map	m;
	t_img	im;
	int		i;

	if (argc != 2 || check_file_name(argv[1]))
		return (usage(argv));
	if (sl_load_map(argv[1], &m))
		return (1);
	x.mlx = mlx_init();
	x.win = mlx_new_window(x.mlx, WINDOWX, WINDOWY, "Hello world!");
	im.img = mlx_new_image(x.mlx, WINDOWX, WINDOWY);
	im.addr = mlx_get_data_addr(im.img, &im.bpp, &im.ll, &im.endian);
	i = -1;
	while (++i < WINDOWY)
		my_mlx_pixel_put(&im, i, i, 0x00FF0000);
	mlx_put_image_to_window(x.mlx, x.win, im.img, 0, 0);
	mlx_hook(x.win, 2, 0, hook_handler, &x);
	mlx_hook(x.win, 17, 0, hook_handler, &x);
	mlx_loop(x.mlx);
	free(x.mlx);
}
