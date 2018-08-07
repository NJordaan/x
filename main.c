/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:30:23 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 16:05:36 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"n.h"
#include	<time.h>
#include	<stdio.h>

t_mlx		g_window;
int			g_check;
int			g_input;
////	DEBUG
clock_t		t1;
clock_t		t2;
long		elapsed;
long		t;
int			fps;
int			fps_counter;
char		s;
////

void		set_pixel(int x, int y, t_color c)
{
	if (x < 0 || y < 0 || x >= g_window.win_width || y >= g_window.win_height)
		return ;
	image_set_pixel(&g_window, x, y,
			(c.r * 0x010000 + c.g * 0x000100 + c.b * 0x000001));
}

int	loop(t_mlx *w)
{
////	Debug
	t1 = clock();
////
	new_window_image(w);
	g_check > 0 ? run(w, g_input) : start(w);
	g_check = 1;
	g_input = -1;
	mlx_clear_window(w->mlx, w->win);
//	anti_alias(w);
	mlx_put_image_to_window(w->mlx, w->win, w->image, 0, 0);
	free_window_image(w);
////	DEBUG
	t2 = clock();
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
	w->delta_time = (float)elapsed / 1000;
	if (t < 1000)
	{
		t+=elapsed;
		fps_counter++;
	}
	else
	{
		fps = fps_counter;
		fps_counter = 0;
		t = 0;
	}
	if (s == '+')
		s = '-';
	else
		s = '+';
	system("clear");
    printf("%s\ntime:\t%ld ms\nframe:\t%d fps\n%c%c%c%c%c\n",
			w->name, elapsed, fps, s, s, s, s, s);
	if (fps > 0)
		mlx_string_put(w->mlx, w->win, 5, 5, 0x00ff00, ft_itoa(fps));
////
	return (0);
}

static	int	key(int key, t_mlx *w)
{
	(void)w;
	if (key == 53)
		exit(0);
	g_input = key;
	return (0);
}

static	int	button(int button, t_mlx *m)
{
	(void)button;
	(void)m;
	exit(0);
	return (0);
}

int			main(int ac, char **av)
{
////	DEBUG
	(void)ac;
	(void)av;
	t = 0;
	fps = -1;
////
	g_check = 0;
	g_window.name = av[0];
	g_window.win_width = 1280;
	g_window.win_height = 720;
	g_window.mlx = mlx_init();
	g_window.win = mlx_new_window(
			g_window.mlx,
			g_window.win_width,
			g_window.win_height,
			"MyWindow");
	mlx_do_key_autorepeaton(g_window.mlx);
	mlx_hook(g_window.win, 2, 0, key, &g_window);
	mlx_hook(g_window.win, 17, 0, button, &g_window);
	mlx_loop_hook(g_window.mlx, loop, &g_window);
	mlx_loop(g_window.mlx);
	return (0);
}
