/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_matrix_multiply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:52:18 by amasson           #+#    #+#             */
/*   Updated: 2017/11/13 10:52:46 by amasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

t_point			geo_matrix_transform_point(t_matrix4x4 m, t_point p)
{
	return (geo_point(
		m.m[0] * p.x + m.m[4] * p.y + m.m[8] * p.z + m.m[12],
		m.m[1] * p.x + m.m[5] * p.y + m.m[9] * p.z + m.m[13],
		m.m[2] * p.x + m.m[6] * p.y + m.m[10] * p.z + m.m[14],
		p.exist));
}

t_vector		geo_matrix_transform_vector(t_matrix4x4 m, t_vector v)
{
	return (geo_vector(
		m.m[0] * v.x + m.m[4] * v.y + m.m[8] * v.z + m.m[12],
		m.m[1] * v.x + m.m[5] * v.y + m.m[9] * v.z + m.m[13],
		m.m[2] * v.x + m.m[6] * v.y + m.m[10] * v.z + m.m[14]));
}

static float	matrix_product_at(t_matrix4x4 a, t_matrix4x4 b, int l, int c)
{
	int		i;
	float	r;

	r = 0;
	i = 0;
	while (i < 4)
	{
		r += geo_matrix_value_at(a, l, i) * geo_matrix_value_at(b, i, c);
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
