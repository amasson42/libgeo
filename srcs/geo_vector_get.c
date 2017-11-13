/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_vector_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:40:05 by arthur            #+#    #+#             */
/*   Updated: 2017/11/12 15:02:26 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgeo.h"

uint8_t		geo_vector_arecolineaire(t_vector u, t_vector v)
{
	return (u.x * v.y == u.y * v.x
		&& u.y * v.z == u.z * v.y
		&& u.z * v.x == u.x * v.z);
}

float		geo_vector_norme(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

float		geo_vector_scalar(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}
