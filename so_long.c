/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josegar2 <josegar2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:02:36 by josegar2          #+#    #+#             */
/*   Updated: 2024/02/23 15:20:28 by josegar2         ###   ########.fr       */
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

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
    void	*win_ptr;

	if (argc != 2 || check_file_name(argv[1]))
		return (usage(argv));
	
	mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	mlx_loop(mlx_ptr);
    free(mlx_ptr);
}
