/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:55:34 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 15:36:53 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		STRUCT_H
# define	STRUCT_H

typedef	struct			s_mlx
{
	char				*name;
	void				*mlx;
	void				*win;
	void				*image;
	unsigned	char	*data;
	int					bpp;
	int					size_line;
	int					endian;
	int					win_width;
	int					win_height;
	float				delta_time;
}						t_mlx;

typedef	struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef	struct			s_vector
{
	float				x;
	float				y;
	float				z;
}						t_vector;

typedef	struct			s_camera
{
	t_vector			position;
	t_vector			rotation;
	float				display_clip;
}						t_camera;

typedef	struct			s_mesh
{
	t_vector			*verticies;
	int					*lines;
	int					lines_index;
	int					verticies_index;
	float				bound;
}						t_mesh;

typedef	struct			s_object
{
	char				*name;
	t_vector			position;
	t_vector			rotation;
	t_mesh				mesh;
}						t_object;

typedef	struct			s_scene
{
	t_mlx				*window;
	t_camera			*camera;
}						t_scene;

#endif
