/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_math1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:40:37 by jpyo              #+#    #+#             */
/*   Updated: 2021/04/27 19:51:52 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_vec3	vec3_plus(t_vec3 u, t_vec3 v)
{
	t_vec3	result;

	result.x = u.x + v.x;
	result.y = u.y + v.y;
	result.z = u.z + v.z;
	return (result);
}

t_vec3	vec3_minus(t_vec3 u, t_vec3 v)
{
	t_vec3	result;

	result.x = u.x - v.x;
	result.y = u.y - v.y;
	result.z = u.z - v.z;
	return (result);
}

t_vec3	vec3_mult(t_vec3 u, t_vec3 v)
{
	t_vec3	result;

	result.x = u.x * v.x;
	result.y = u.y * v.y;
	result.z = u.z * v.z;
	return (result);
}

t_vec3	vec3_div(t_vec3 u, t_vec3 v)
{
	t_vec3	result;

	result.x = u.x / v.x;
	result.y = u.y / v.y;
	result.z = u.z / v.z;
	return (result);
}
