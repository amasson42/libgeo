/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_matrix_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:47:44 by amasson           #+#    #+#             */
/*   Updated: 2017/11/13 10:48:20 by amasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

t_matrix4x4	geo_matrix_rotx(float alpha)
{
	float c;
	float s;

	c = cos(alpha);
	s = sin(alpha);
	return ((t_matrix4x4) {
		{1, 0, 0, 0,
		0, c, -s, 0,
		0, s, c, 0,
		0, 0, 0, 1}
	});
}

t_matrix4x4	geo_matrix_roty(float alpha)
{
	float c;
	float s;

	c = cos(alpha);
	s = sin(alpha);
	return ((t_matrix4x4) {
		{c, 0, -s, 0,
		0, 1, 0, 0,
		s, 0, c, 0,
		0, 0, 0, 1}
	});
}

t_matrix4x4	geo_matrix_rotz(float alpha)
{
	float c;
	float s;

	c = cos(alpha);
	s = sin(alpha);
	return ((t_matrix4x4) {
		{c, s, 0, 0,
		-s, c, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1}
	});
}

t_matrix4x4	geo_matrix_rotaxe(t_vector v, float alpha)
{
	float c;
	float s;
	float l;

	v = geo_vector_multiply(v, 1.0 / geo_vector_norme(v));
	c = cos(alpha);
	s = sin(alpha);
	l = 1.0 - c;
	return ((t_matrix4x4) {
		{v.x * v.x * l + c, v.x * v.y * l + v.z * s, v.x * v.z * l - v.y * s, 0,
		v.x * v.y * l - v.z * s, v.y * v.y * l + c, v.y * v.z * l + v.x * s, 0,
		v.x * v.z * l + v.y * s, v.y * v.z * l - v.x * s, v.z * v.z * l + c, 0,
		0, 0, 0, 1}
	});
}
