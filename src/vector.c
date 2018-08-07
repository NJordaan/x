/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:21:39 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 14:51:02 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../n.h"

t_vector	new_vector(float x, float y, float z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

int			cmp_vector(t_vector a, t_vector b)
{
	if (a.x != b.x || a.y != b.y || a.z != b.z)
		return (0);
	return (1);
}

t_vector	add_vector(t_vector a, t_vector b)
{
	return (new_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector	sub_vector(t_vector a, t_vector b)
{
	return (new_vector(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vector	mul_vector(t_vector a, t_vector b)
{
	return (new_vector(a.x * b.x, a.y * b.y, a.z * b.z));
}

t_vector	div_vector(t_vector a, t_vector b)
{
	return (new_vector(a.x / b.x, a.y / b.y, a.z / b.z));
}

float		magnitude_vector(t_vector v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

float		angle_vector(t_vector a, t_vector b)
{
	a = normalize_vector(a);
	b = normalize_vector(b);
	return (acos((a.x * b.x + a.y * b.y + a.z * b.z) /
				(magnitude_vector(a) * magnitude_vector(b))) * 180 / M_PI);
}

t_vector	normalize_vector(t_vector a)
{
	t_vector	v;
	float		m;

	m = magnitude_vector(a);
	v.x = a.x / m;
	v.y = a.y / m,
	v.z = a.z / m;
	return (v);
}

t_vector	vec_to_screen(t_mlx *w, t_camera cam, t_vector a)
{
	t_vector	v;
	t_vector	d;

	cam.position.y = -cam.position.y;
	a.y = -a.y;
	d = new_vector(
		   cos(cam.rotation.y) * (sin(cam.rotation.z) * (a.y - cam.position.y)
				+ cos(cam.rotation.z) * (a.x - cam.position.x)) -
				sin(cam.rotation.y) * (a.z - cam.position.z),
			sin(cam.rotation.x) * (cos(cam.rotation.y) * (a.z - cam.position.z)
				+ sin(cam.rotation.y) * (sin(cam.rotation.z) *
					(a.y - cam.position.y) + cos(cam.rotation.z) *
					(a.x - cam.position.x))) + cos(cam.rotation.x) *
					(cos(cam.rotation.z) * (a.y - cam.position.y) -
					sin(cam.rotation.z) * (a.x - cam.position.x)),
			cos(cam.rotation.x) * (cos(cam.rotation.y) * (a.z - cam.position.z)
				+ sin(cam.rotation.y) * (sin(cam.rotation.z) *
					(a.y - cam.position.y) + cos(cam.rotation.z) *
					(a.x - cam.position.x))) - sin(cam.rotation.x) *
					(cos(cam.rotation.z) * (a.y - cam.position.y) -
					sin(cam.rotation.z) * (a.x - cam.position.x)));
	v.x = (((cam.display_clip / d.z) * d.x + w->win_width / 2) -
			w->win_width / 2) * 1000 + w->win_width / 2;
	v.y = (((cam.display_clip / d.z) * d.y + w->win_height / 2) -
			w->win_height / 2) * 1000 + w->win_height / 2;
	return (v);
}

t_vector	rotate_y(t_vector a, float angle)
{
	t_vector	v;

	angle = angle / 180 * M_PI;
	v.x = (a.x * cos(angle)) - (a.z * sin(angle)),
	v.y = a.y;
	v.z = (a.z * cos(angle)) + (a.x * sin(angle));
	return (v);
}

t_vector	rotate_z(t_vector a, float angle)
{
	t_vector	v;

	angle = angle / 180 * M_PI;
	v.x = (a.x * cos(angle)) - (a.y * sin(angle));
	v.y = (a.y * cos(angle)) + (a.x * sin(angle));
	v.z = a.z;
	return (v);
}

t_vector	rotate_x(t_vector a, float angle)
{
	t_vector	v;
	angle = angle / 180 * M_PI;
	v.x = a.x,
	v.y = (a.y * cos(angle)) - (a.z * sin(angle)),
	v.z = (a.z * cos(angle)) + (a.y * sin(angle));
	return (v);
}

t_vector	rotate_vector(t_vector a, t_vector e_angles)
{
	t_vector	v;

	v = rotate_x(a, e_angles.x);
	v = rotate_y(v, e_angles.y);
	v = rotate_z(v, e_angles.z);
	return (v);
}
