/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgeo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasson <amasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:11:09 by amasson           #+#    #+#             */
/*   Updated: 2017/11/13 10:50:20 by amasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_LIBGEO_H
# define DEF_LIBGEO_H

# include <stdlib.h>
# include <math.h>
# define PI (3.14159265359)

typedef struct	s_point {
	float		x;
	float		y;
	float		z;
	uint8_t		exist;
}				t_point;

typedef struct	s_vector {
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_plan {
	float		a;
	float		b;
	float		c;
	float		d;
}				t_plan;

typedef struct	s_line {
	t_point		o;
	t_vector	v;
}				t_line;

/*
** point
*/

t_point			geo_point(float x, float y, float z, uint8_t exist);
t_point			geo_point_vector(t_vector v);
t_point			geo_point_pv(t_point p, t_vector c, float t);
t_point			geo_point_inter_dp(t_line d, t_plan pl);
t_point			geo_point_project_ppl(t_point p, t_plan pl);

uint8_t			geo_point_isonplan(t_point p, t_plan pl);
uint8_t			geo_point_samesideplan(t_point a, t_point b, t_plan pl);
float			geo_point_outdistance(t_point a, t_point b);

/*
** vector
*/

t_vector		geo_vector(float x, float y, float z);
t_vector		geo_vector_point(t_point p);
t_vector		geo_vector_points(t_point a, t_point b);
t_vector		geo_vector_vectorial(t_vector u, t_vector v);
t_vector		geo_vector_normal_pl(t_plan pl);

float			geo_vector_norme(t_vector v);
float			geo_vector_scalar(t_vector u, t_vector v);
uint8_t			geo_vector_arecolineaire(t_vector u, t_vector v);

t_vector		geo_vector_addition(t_vector u, t_vector v);
t_vector		geo_vector_multiply(t_vector u, float k);

/*
** line
*/

t_line			geo_line(t_point p, t_vector v);
t_line			geo_line_points(t_point a, t_point b);
t_line			geo_line_inter_plans(t_plan a, t_plan b);

/*
** plan
*/

t_plan			geo_plan(float a, float b, float c, float d);
t_plan			geo_plan_point_normal(t_point o, t_vector n);
t_plan			geo_plan_point_vectors(t_point p, t_vector u, t_vector v);
t_plan			geo_plan_points(t_point a, t_point b, t_point c);

float			geo_plan_outdistance(t_plan pl, t_point p);

typedef struct	s_matrix4x4 {
	float		m[16];
}				t_matrix4x4;

float			geo_matrix_value_at(t_matrix4x4 m, int l, int c);

t_matrix4x4		geo_matrix_zero(void);
t_matrix4x4		geo_matrix_identity(void);
t_matrix4x4		geo_matrix_translation(t_vector v);
t_matrix4x4		geo_matrix_scale(t_vector s);
t_matrix4x4		geo_matrix_rotx(float alpha);
t_matrix4x4		geo_matrix_roty(float alpha);
t_matrix4x4		geo_matrix_rotz(float alpha);
t_matrix4x4		geo_matrix_rotaxe(t_vector v, float alpha);
t_matrix4x4		geo_matrix_projection(float fov, float aspect,
										float near, float far);

t_matrix4x4		geo_matrix_inverse(t_matrix4x4 m); // not yet
t_matrix4x4		geo_matrix_transpose(t_matrix4x4 m); // not yet

t_point			geo_matrix_transform_point(t_matrix4x4 m, t_point p);
t_vector		geo_matrix_transform_vector(t_matrix4x4 m, t_vector v);
t_matrix4x4		geo_matrix_multiply(t_matrix4x4 a, t_matrix4x4 b);

#endif
