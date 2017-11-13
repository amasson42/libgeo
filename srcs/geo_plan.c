/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:43:59 by amasson           #+#    #+#             */
/*   Updated: 2017/11/12 14:53:17 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

t_plan geo_plan(float a, float b, float c, float d)
{
	return ((t_plan) {a, b, c, d});
}

t_plan geo_plan_point_normal(t_point o, t_vector n)
{
	return (geo_plan(n.x, n.y, n.z, -n.x * o.x - n.y * o.y - n.z * o.z));
}

t_plan geo_plan_point_vectors(t_point p, t_vector u, t_vector v)
{
	return (geo_plan_point_normal(p, geo_vector_vectorial(u, v)));
}

t_plan geo_plan_points(t_point a, t_point b, t_point c)
{
	return (geo_plan_point_vectors(a,
		geo_vector_points(a, b),
		geo_vector_points(a, c)));
}
