/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_plan_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:57:13 by arthur            #+#    #+#             */
/*   Updated: 2017/11/12 15:09:37 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

float	geo_plan_outdistance(t_plan pl, t_point p)
{
	if (p.exist && pl.a && pl.b && pl.c && pl.d)
		return (fabs(pl.a * p.x + pl.b * p.y + pl.c * p.z + pl.d)
		/ sqrt(pl.a * pl.a + pl.b * pl.b + pl.c * pl.c));
	else
		return (0);
}
