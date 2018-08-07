/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:37:34 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 14:43:50 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../n.h"

void	draw_full_color(t_mlx *w, t_color c)
{
	int	x;
	int	y;

	x = 0;
	while (x < w->win_width)
	{
		y = 0;
		while (y < w->win_height)
			set_pixel(x, y++, c);
		x++;
	}
}

void	draw_sqr(int x, int y, int size, t_color c)
{
	int		a;
	int		b;

	if (size < 1)
		return ;
	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size)
			set_pixel(x + a, y + b++, c);
		a++;
	}
}

void	draw_line_down(t_vector a, size_t len, t_color c)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		set_pixel((int)a.x, (int)a.y + i, c);
		i++;
	}
}

void	draw_line(t_vector a, t_vector b, t_color color)
{
	t_vector temp;
	float m;
	float c;
	float x;
	float y;
	float step;

	if (a.x == b.x)
	{
		if (b.y > a.y)
			draw_line_down(a, (size_t)(b.y - a.y), color);
		else
			draw_line_down(b, (size_t)(a.y - b.y), color);
		return ;
	}
	if (a.x > b.x)
	{
		temp = a;
		a = b;
		b = temp;
	}
	m = b.y - a.y;
	c = b.x - a.x;
	m /= c;
	c = m * a.x;
	c = -c;
	c += a.y;
	x = a.x;
	step = (float)pow(fmax(
				fabs((double)(a.x - b.x)),
				fabs((double)(a.y - b.y))), -1);
	while (x < b.x)
	{
		y = m * x + c;
		y = round_to_int(y);
		set_pixel((int)x, (int)y, color);
		x += step;
	}
}

void	draw_scene_line(t_scene scene, t_vector a, t_vector b, t_color c)
{
	a = vec_to_screen(scene.window, *scene.camera, a);
	b = vec_to_screen(scene.window, *scene.camera, b);
	if ((a.x > 0 && a.x < scene.window->win_width &&
		a.y > 0 && a.y < scene.window->win_height) || //
		(b.x > 0 && b.x < scene.window->win_width &&
		 b.y > 0 && b.y < scene.window->win_height))
		draw_line(a, b, c);
}

void	draw_grid(t_scene scene, int raduis)
{
	t_color	c;
	int		x;
	int		y;

	c = new_color(100, 100, 100);
	x = -raduis;
	while (x <= raduis)
	{
		y = -raduis;
		while (y <= raduis)
		{
			draw_scene_line(
					scene,
					new_vector(x, 0, y),
					new_vector(x + 1, 0, y),
					c
					);
			draw_scene_line(
					scene,
					new_vector(x, 0, y),
					new_vector(x, 0, y + 1),
					c
					);
			y++;
		}
		x++;
	}
}
