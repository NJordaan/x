/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:05:44 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 15:19:57 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../n.h"

t_mesh		new_mesh(t_vector *verticies, int *lines,
		int verticies_index, int lines_index)
{
	t_mesh	mesh;
	float	distance;
	int		i;

	mesh.lines = lines;
	mesh.verticies = verticies;
	mesh.lines_index = lines_index;
	mesh.verticies_index = verticies_index;
	mesh.bound = 0;
	i = 0;
	while (i < verticies_index)
	{
		distance = magnitude_vector(verticies[i]);
		if (distance > mesh.bound)
			mesh.bound = distance;
		i++;

	}
	return (mesh);
}

void		draw_mesh(t_scene scene, t_mesh mesh, t_color c)
{
	int			i;

	i = 0;
	while (i < mesh.lines_index - 1)
	{
		draw_scene_line(scene,
				mesh.verticies[mesh.lines[i]],
				mesh.verticies[mesh.lines[i + 1]],
				c);
		i += 2;
	}
}

t_mesh		mesh_rotate(t_mesh mesh, t_vector rotation)
{
	int			i;

	i = 0;
	while (i < mesh.verticies_index)
	{
		mesh.verticies[i] = rotate_vector(mesh.verticies[i], rotation);
		i++;
	}
	return (mesh);
}
