/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_matrix_transform.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:49:06 by amasson           #+#    #+#             */
/*   Updated: 2017/11/16 12:06:09 by amasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

t_matrix4x4	geo_matrix_translation(float x, float y, float z)
{
	return ((t_matrix4x4) {
		{1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		x, y, z, 1}
	});
}

t_matrix4x4	geo_matrix_translation_vector(t_vector v)
{
	return ((t_matrix4x4) {
		{1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		v.x, v.y, v.z, 1}
	});
}

t_matrix4x4	geo_matrix_scale(float x, float y, float z)
{
	return ((t_matrix4x4) {
		{x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1}
	});
}

t_matrix4x4	geo_matrix_scale_vector(t_vector s)
{
	return ((t_matrix4x4) {
		{s.x, 0, 0, 0,
		0, s.y, 0, 0,
		0, 0, s.z, 0,
		0, 0, 0, 1}
	});
}

t_matrix4x4	geo_matrix_projection(float fov, float aspect,
	float near, float far)
{
	float x;
	float y;
	float z;

	y = 1 / tan(fov * 0.5);
	x = y / aspect;
	z = far / (near - far);
	return ((t_matrix4x4) {
		{x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, -1,
		0, 0, z * near, 0}
	});
}
