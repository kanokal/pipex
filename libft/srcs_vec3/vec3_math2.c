/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_math2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:41:15 by jpyo              #+#    #+#             */
/*   Updated: 2021/04/27 19:51:52 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_vec3	vec3_mult_val(t_vec3 u, double t)
{
	t_vec3	result;

	result.x = u.x * t;
	result.y = u.y * t;
	result.z = u.z * t;
	return (result);
}

t_vec3	vec3_div_val(t_vec3 u, double t)
{
	t_vec3	result;

	result.x = u.x / t;
	result.y = u.y / t;
	result.z = u.z / t;
	return (result);
}

double	vec3_dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	vec3_cross(t_vec3 u, t_vec3 v)
{
	t_vec3	result;

	result.x = u.y * v.z - u.z * v.y;
	result.y = u.z * v.x - u.x * v.z;
	result.z = u.x * v.y - u.y * v.x;
	return (result);
}
