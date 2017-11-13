/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_point_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:22:33 by amasson           #+#    #+#             */
/*   Updated: 2017/11/12 15:09:21 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

uint8_t	geo_point_isonplan(t_point p, t_plan pl)
{
	return (p.exist && p.x * pl.a + p.y * pl.b + p.z * pl.c + pl.d == 0);
}

uint8_t	geo_point_samesideplan(t_point a, t_point b, t_plan pl)
{
	return (geo_vector_points(geo_point_project_ppl(a, pl), a).x *
		geo_vector_points(geo_point_project_ppl(b, pl), b).x > 0);
}

float	geo_point_outdistance(t_point a, t_point b)
{
	if (a.exist && b.exist)
		return (geo_vector_norme(geo_vector_points(a, b)));
	else
		return (0);
}
