/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:12:21 by njordaan          #+#    #+#             */
/*   Updated: 2018/08/06 14:49:31 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../n.h"

t_scene		init_scene(t_mlx *w, t_camera *camera)
{
	t_scene	scene;

	scene.window = w;
	scene.camera = camera;
	return (scene);
}

