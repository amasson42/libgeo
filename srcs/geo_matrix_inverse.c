/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_matrix_inverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:28:47 by arthur            #+#    #+#             */
/*   Updated: 2017/11/16 12:07:25 by amasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

static t_matrix4x4	hard_inverse(t_matrix4x4 m)
{
	(void)m;
	return (geo_matrix_identity());
}

static uint8_t		inverse_repere(t_matrix4x4 *m, t_vector d[3])
{
	float t;

	t = m->m[0] * (m->m[5] * m->m[10] - m->m[9] * m->m[6])
		- m->m[4] * (m->m[1] * m->m[10] - m->m[9] * m->m[2])
		+ m->m[8] * (m->m[1] * m->m[6] - m->m[5] * m->m[2]);
	if (t == 0)
		return (0);
	d[0].x = (m->m[5] * m->m[10] - m->m[9] * m->m[6]) / t;
	d[0].y = (m->m[8] * m->m[6] - m->m[4] * m->m[10]) / t;
	d[0].z = (m->m[4] * m->m[9] - m->m[8] * m->m[5]) / t;
	d[1].x = (m->m[9] * m->m[2] - m->m[1] * m->m[10]) / t;
	d[1].y = (m->m[0] * m->m[10] - m->m[8] * m->m[2]) / t;
	d[1].z = (m->m[8] * m->m[1] - m->m[0] * m->m[9]) / t;
	d[2].x = (m->m[1] * m->m[6] - m->m[5] * m->m[2]) / t;
	d[2].y = (m->m[4] * m->m[2] - m->m[0] * m->m[6]) / t;
	d[2].z = (m->m[0] * m->m[5] - m->m[4] * m->m[1]) / t;
	return (1);
}

t_matrix4x4			geo_matrix_inverse(t_matrix4x4 m)
{
	t_vector	d[3];
	t_point		o;

	if (m.m[3] == 0 && m.m[7] == 0 && m.m[11] == 0 && m.m[15] == 1)
	{
		if (inverse_repere(&m, d))
		{
			o.x = d[0].x * -m.m[12] + d[0].y * -m.m[13] + d[0].z * -m.m[14];
			o.y = d[1].x * -m.m[12] + d[1].y * -m.m[13] + d[1].z * -m.m[14];
			o.z = d[2].x * -m.m[12] + d[2].y * -m.m[13] + d[2].z * -m.m[14];
			return (geo_matrix_axe_offset(d, o));
		}
		else
			return (geo_matrix_identity());
	}
	else
		return (hard_inverse(m));
}

t_matrix4x4			geo_matrix_transpose(t_matrix4x4 m)
{
	return ((t_matrix4x4) {
		{m.m[0], m.m[4], m.m[8], m.m[12],
		m.m[1], m.m[5], m.m[9], m.m[13],
		m.m[2], m.m[6], m.m[10], m.m[14],
		m.m[3], m.m[7], m.m[11], m.m[15]}
	});
}
