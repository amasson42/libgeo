/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:19:07 by arthur            #+#    #+#             */
/*   Updated: 2017/11/12 18:59:32 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

t_matrix4x4	geo_matrix_zero(void)
{
	return ((t_matrix4x4) {
		{0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0}
	});
}

t_matrix4x4	geo_matrix_identity(void)
{
	return ((t_matrix4x4) {
		{1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1}
	});
}

t_matrix4x4	geo_matrix_translation(t_vector v)
{
	return ((t_matrix4x4) {
		{1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		v.x, v.y, v.z, 1}
	});
}

t_matrix4x4	geo_matrix_scale(t_vector s)
{
	return ((t_matrix4x4) {
		{s.x, 0, 0, 0,
		0, s.y, 0, 0,
		0, 0, s.z, 0,
		0, 0, 0, 1}
	});
}

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

t_matrix4x4	geo_matrix_projection(float fov, float aspect,
	float near, float far)
{
	float y = 1 / tan(fov * 0.5);
	float x = y / aspect;
	float z = far / (near - far);
	return ((t_matrix4x4) {
		{x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, -1,
		0, 0, z * near, 0}
	});
}

t_point		geo_matrix_transform_point(t_matrix4x4 m, t_point p)
{
	return (geo_point(
		m.m[0] * p.x + m.m[4] * p.y + m.m[8] * p.z + m.m[12],
		m.m[1] * p.x + m.m[5] * p.y + m.m[9] * p.z + m.m[13],
		m.m[2] * p.x + m.m[6] * p.y + m.m[10] * p.z + m.m[14],
		p.exist
	));
}

t_vector		geo_matrix_transform_vector(t_matrix4x4 m, t_vector v)
{
	return (geo_vector(
		m.m[0] * v.x + m.m[4] * v.y + m.m[8] * v.z + m.m[12],
		m.m[1] * v.x + m.m[5] * v.y + m.m[9] * v.z + m.m[13],
		m.m[2] * v.x + m.m[6] * v.y + m.m[10] * v.z + m.m[14]
	));
}

float			matrix_value_at(t_matrix4x4 m, int l, int c)
{
	return (m.m[4 * c + l]);
}

float			matrix_product_at(t_matrix4x4 a, t_matrix4x4 b, int l, int c)
{
	int i;
	float r;

	r = 0;
	i = 0;
	while (i < 4)
	{
		r += matrix_value_at(a, l, i) * matrix_value_at(b, i, c);
		i++;
	}
	return (r);
}

t_matrix4x4		geo_matrix_multiply(t_matrix4x4 a, t_matrix4x4 b)
{
	int			i;
	t_matrix4x4	m;

	i = 0;
	while (i < 16)
	{
		m.m[i] = matrix_product_at(a, b, i % 4, i / 4);
		i++;
	}
	return (m);
}
