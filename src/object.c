/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:20:41 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 14:58:38 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../n.h"

t_object	new_object(char *name, t_vector pos, t_vector rot, t_mesh mesh)
{
	t_object	obj;

	obj.name = name;
	obj.position = pos;
	obj.rotation = rot;
	obj.mesh = mesh;
	return (obj);
}

void		draw_object(t_scene scene, t_object obj, t_color c)
{
	t_vector	a;
	t_vector	b;
	int			i;

	i = 0;
	while (i < obj.mesh.lines_index)
	{
		a = add_vector(
					obj.position,
					rotate_vector(
						obj.mesh.verticies[obj.mesh.lines[i]],
						obj.rotation));
		b = add_vector(
					obj.position,
					rotate_vector(
						obj.mesh.verticies[obj.mesh.lines[i + 1]],
						obj.rotation));
		draw_scene_line(scene, a, b, c);
		i += 2;
	}
}
