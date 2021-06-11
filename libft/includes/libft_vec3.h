/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vec3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:41:48 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/19 14:34:01 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VEC3_H
# define LIBFT_VEC3_H

# include "libft_structures.h"

t_vec3	vec3_plus(t_vec3 u, t_vec3 v);
t_vec3	vec3_minus(t_vec3 u, t_vec3 v);
t_vec3	vec3_mult(t_vec3 u, t_vec3 v);
t_vec3	vec3_div(t_vec3 u, t_vec3 v);
t_vec3	vec3_mult_val(t_vec3 u, double t);
t_vec3	vec3_div_val(t_vec3 u, double t);
double	vec3_dot(t_vec3 u, t_vec3 v);
t_vec3	vec3_cross(t_vec3 u, t_vec3 v);
double	vec3_length2(t_vec3 v);
double	vec3_length(t_vec3 v);
t_vec3	vec3_unit(t_vec3 v);
t_vec3	vec3_at(t_vec3 origin, t_vec3 dir, double t);
t_vec3	vec3_set(double x, double y, double z);
t_point	point_set(double x, double y, double z);
t_color	color_set(double x, double y, double z);
t_vec3	vec3_clamp(t_vec3 v, double max, double min);
double	vec3_cosval(t_vec3 u, t_vec3 v);

#endif
