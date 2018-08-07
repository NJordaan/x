/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:56:19 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 15:38:41 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PROTOTYPE_H
# define	PROTOTYPE_H

void					run(t_mlx *w, int input);
void					start(t_mlx *w);

//MATH
int						round_to_int(float x);
int						ceil_to_int(float x);
float					square_root(int x);

//COLOR
t_color					new_color(int r, int g, int b);
t_color					hex_to_color(int n);
int						color_to_hex(t_color c);

//DRAW
void					draw_sqr(int x, int y, int size, t_color c);
void					draw_line(t_vector a, t_vector b, t_color c);
void					draw_scene_line(t_scene s, t_vector a, t_vector b,
										t_color color);
void					draw_full_color(t_mlx *w, t_color color);
void					draw_object(t_scene scene, t_object obj, t_color color);
void					draw_grid(t_scene scene, int raduis);
void					draw_mesh(t_scene scene, t_mesh mesh, t_color c);

//WINDOW
void					image_set_pixel(t_mlx *mlx, int x, int y, int c);
int						image_gett_pixel(t_mlx *mlx, int x, int y);
void					set_pixel(int x, int y, t_color c);
void					new_window_image(t_mlx *mlx);
void					free_window_image(t_mlx *mlx);
void					anti_alias(t_mlx *mlx);

//VECTOR
t_vector				new_vector(float x, float y, float z);
t_vector				add_vector(t_vector a, t_vector b);
t_vector				sub_vector(t_vector a, t_vector b);
t_vector				mul_vector(t_vector a, t_vector b);
t_vector				div_vector(t_vector a, t_vector b);
t_vector				normalize_vector(t_vector a);
t_vector				forward_vector(t_vector rotation);
t_vector				vec_to_screen(t_mlx *w, t_camera cam, t_vector a);
t_vector				rotate_x(t_vector a, float angle);
t_vector				rotate_z(t_vector a, float angle);
t_vector				rotate_y(t_vector a, float angle);
t_vector				rotate_vector(t_vector a, t_vector e_angles);
int						cmp_vector(t_vector a, t_vector b);
float					magnitude_vector(t_vector v);
float					angle_vector(t_vector a, t_vector b);

//MESH
t_mesh					new_mesh(t_vector *verticies, int *line,
								int verticies_index, int lines_index);
t_mesh					mesh_rotate(t_mesh mesh, t_vector rotation);

//OBJECT
t_object				new_object(char *name, t_vector pos, t_vector rot, t_mesh mesh);

//SCENE
t_scene					init_scene(t_mlx *w, t_camera *camera);

#endif
