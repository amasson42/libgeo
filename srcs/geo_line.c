/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:55:46 by amasson           #+#    #+#             */
/*   Updated: 2017/11/12 15:03:06 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

t_line	geo_line(t_point p, t_vector v)
{
	return ((t_line) {p, v});
}

t_line	geo_line_points(t_point a, t_point b)
{
	return (geo_line(a, geo_vector_points(a, b)));
}

t_line	geo_line_inter_plans(t_plan a, t_plan b)
{
	if (geo_vector_arecolineaire(geo_vector_normal_pl(a),
		geo_vector_normal_pl(b)))
		return (geo_line(geo_point(0, 0, 0, 0), geo_vector(0, 0, 0)));
	return (geo_line(geo_point(0, 0, 0, 0), geo_vector(0, 0, 0)));
}
