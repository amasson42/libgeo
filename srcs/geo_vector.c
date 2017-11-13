/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:41:04 by amasson           #+#    #+#             */
/*   Updated: 2017/11/12 15:02:38 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

t_vector	geo_vector(float x, float y, float z)
{
	return ((t_vector) {x, y, z});
}

t_vector	geo_vector_point(t_point p)
{
	return (geo_vector(p.x, p.y, p.z));
}

t_vector	geo_vector_points(t_point a, t_point b)
{
	if (a.exist && b.exist)
		return (geo_vector(b.x - a.x, b.y - a.y, b.z - a.z));
	else
		return (geo_vector(0, 0, 0));
}

t_vector	geo_vector_vectorial(t_vector u, t_vector v)
{
	return (geo_vector(
		u.y * v.z - u.z * v.y,
		u.z * v.x - u.x * v.z,
		u.x * v.y - u.y * v.x));
}

t_vector	geo_vector_normal_pl(t_plan pl)
{
	return (geo_vector(pl.a, pl.b, pl.c));
}
