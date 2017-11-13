/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_vector_arithmetic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:19:25 by amasson           #+#    #+#             */
/*   Updated: 2017/11/12 14:48:31 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

t_vector	geo_vector_addition(t_vector u, t_vector v)
{
	return (geo_vector(u.x + v.x, u.y + v.y, u.z + v.z));
}

t_vector	geo_vector_multiply(t_vector u, float k)
{
	return (geo_vector(u.x * k, u.y * k, u.z * k));
}
