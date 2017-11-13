/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:19:07 by arthur            #+#    #+#             */
/*   Updated: 2017/11/13 10:52:34 by amasson          ###   ########.fr       */
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
