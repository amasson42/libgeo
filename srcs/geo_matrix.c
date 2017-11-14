/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:19:07 by arthur            #+#    #+#             */
/*   Updated: 2017/11/14 15:55:21 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

float		geo_matrix_value_at(t_matrix4x4 m, int l, int c)
{
	return (m.m[4 * c + l]);
}

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

t_matrix4x4	geo_matrix_axe_offset(t_vector axes[3], t_point offset)
{
	return ((t_matrix4x4) {
		{axes[0].x, axes[1].x, axes[2].x, 0,
		axes[0].y, axes[1].y, axes[2].y, 0,
		axes[0].z, axes[1].z, axes[2].z, 0,
		offset.x, offset.y, offset.z, 1}
	});
}
