/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:12:55 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 16:02:08 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../n.h"

int		image_get_pixel(t_mlx *w, unsigned char *data, int x, int y)
{
	int i;
	int n;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > w->win_width - 1)
		x = w->win_width - 1;
	if (y > w->win_height - 1)
		y = w->win_height - 1;
	i = (y * w->size_line) + (x * (w->bpp));
	n = 0;
	n += data[i] * 0x0000ff;
	n += data[i + 1] * 0x00ff00;
	n += data[i + 2] * 0xff0000;
	return (n);
}

void    image_set_pixel(t_mlx *mlx, int x, int y, int c)
{
	int	i;

	i = (y * mlx->size_line) + (x * (mlx->bpp));
	mlx->data[i] = c & 0x0000ff;
	mlx->data[i + 1] = (c & 0x00ff00) / 0x000100;
	mlx->data[i + 2] = (c & 0xff0000) / 0x010000;
}

void	new_window_image(t_mlx *mlx)
{
	mlx->image = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_height);
	if (!mlx->data)
	{
		mlx->data = (unsigned char *)mlx_get_data_addr(
				mlx->image,
				&mlx->bpp,
				&mlx->size_line,
				&mlx->endian
				);
		mlx->bpp /= 8;
	}
}

void	free_window_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->image);
}

int		get_aa_color(t_mlx *w, unsigned char *data, int x, int y)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (i < 1)
	{
		n += image_get_pixel(w, data, x + i, y);
		n += image_get_pixel(w, data, x, y + i);
		i++;
	}
	return (n / 6);
}

void	anti_alias(t_mlx *mlx)
{
	unsigned char	*data;
	int	x;
	int	y;

	data = mlx->image;
	x = 0;
	while (x < mlx->win_width)
	{
		y = 0;
		while (y < mlx->win_height)
		{
			image_set_pixel(mlx, x, y, get_aa_color(mlx, data, x, y));
			y++;
		}
		x++;
	}
}
