/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:28:36 by amasson           #+#    #+#             */
/*   Updated: 2017/11/12 15:01:04 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

t_point	geo_point(float x, float y, float z, uint8_t exist)
{
	return ((t_point) {x, y, z, exist});
}

t_point	geo_point_vector(t_vector v)
{
	return (geo_point(v.x, v.y, v.z, 1));
}

t_point	geo_point_pv(t_point p, t_vector v, float t)
{
	return (geo_point(p.x + v.x * t, p.y + v.y * t, p.z + v.z * t, p.exist));
}

t_point	geo_point_inter_dp(t_line d, t_plan pl)
{
	float t;

	if (pl.a * d.v.x + pl.b * d.v.y + pl.c * d.v.z)
	{
		t = -pl.d - pl.a * d.o.x - pl.b * d.o.y - pl.c * d.o.z;
		t /= pl.a * d.v.x + pl.b * d.v.y + pl.c * d.v.z;
		return (geo_point_pv(d.o, d.v, t));
	}
	else
		return (geo_point(0, 0, 0, 0));
}

t_point	geo_point_project_ppl(t_point p, t_plan pl)
{
	return (geo_point_inter_dp(geo_line(p, geo_vector(pl.a, pl.b, pl.c)), pl));
}
