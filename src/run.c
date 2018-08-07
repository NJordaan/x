/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:13:13 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 15:55:04 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../n.h"
#include <math.h>

t_scene		g_scene;
t_camera	g_camera;
t_mesh		g_mesh;
t_object	g_object;
t_color		g_background_color;

t_mesh		_get_cube_mesh(float size)
{
	 t_vector *v;
	 int *l;

	 v = (t_vector *)ft_memalloc(sizeof(t_vector) * 8);
	 l = (int *)ft_memalloc(sizeof(int) * 24);
	 v[0] = new_vector(-size, -size, -size);
	 v[1] = new_vector(size, -size, -size);
	 v[2] = new_vector(size, size, -size);
	 v[3] = new_vector(-size, size, -size);
	 v[4] = new_vector(-size, -size, size);
	 v[5] = new_vector(size, -size, size);
	 v[6] = new_vector(size, size, size);
	 v[7] = new_vector(-size, size, size);
	 l[0] = 0;
	 l[1] = 1;
	 l[2] = 1;
	 l[3] = 2;
	 l[4] = 2;
	 l[5] = 3;
	 l[6] = 3;
	 l[7] = 0;
	 l[8] = 4;
	 l[9] = 5;
	 l[10] = 5;
	 l[11] = 6;
	 l[12] = 6;
	 l[13] = 7;
	 l[14] = 7;
	 l[15] = 4;
	 l[16] = 0;
	 l[17] = 4;
	 l[18] = 1;
	 l[19] = 5;
	 l[20] = 2;
	 l[21] = 6;
	 l[22] = 3;
	 l[23] = 7;
	 return (new_mesh(v, l, 8, 24));
}

t_mesh		_get_pyramid_mesh(float size)
{
	t_vector *v;
	int *l;

	v = (t_vector *)ft_memalloc(sizeof(t_vector) * 5);
	l = (int *)ft_memalloc(sizeof(int) * 16);
	v[0] = new_vector(-size, 0, -size);
	v[1] = new_vector(size, 0, -size);
	v[2] = new_vector(size, 0, size);
	v[3] = new_vector(-size, 0, size);
	v[4] = new_vector(0, size * 2, 0);
	l[0] = 0;
	l[1] = 1;
	l[2] = 1;
	l[3] = 2;
	l[4] = 2;
	l[5] = 3;
	l[6] = 3;
	l[7] = 0;
	l[8] = 4;
	l[9] = 0;
	l[10] = 4;
	l[11] = 1;
	l[12] = 4;
	l[13] = 2;
	l[14] = 4;
	l[15] = 3;
	return (new_mesh(v, l, 5, 16));
}

void		start(t_mlx *w)
{
	(void)w;
	g_scene = init_scene(w, &g_camera);
	g_camera.display_clip = 1;
	g_camera.rotation = new_vector(0, 45, 0);
	g_camera.position = new_vector(-8, 2, -8);
	g_background_color = new_color(0, 0, 255);
	g_mesh = _get_pyramid_mesh(1);
	g_object = new_object("CUBE", new_vector(4, 3, -4), new_vector(0, 0, 0),
			_get_cube_mesh(2));
}

void		run(t_mlx *w, int input)
{
	(void)w;
	(void)input;
	draw_full_color(w, g_background_color);
	//draw_object(g_scene, g_object, new_color(50, 50, 50));
	draw_grid(g_scene, 8);
	draw_mesh(g_scene, g_mesh, new_color(255, 50, 50));
	//g_mesh = mesh_rotate(g_mesh, new_vector(0, 90 * w->delta_time, 0));
}
