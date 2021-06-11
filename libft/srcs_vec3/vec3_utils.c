/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:45:45 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/11 03:08:14 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_vec3	vec3_set(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point	point_set(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_color	color_set(double x, double y, double z)
{
	t_color	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}

t_vec3	vec3_clamp(t_vec3 v, double max, double min)
{
	t_vec3	result;

	result.x = ft_clamp(v.x, max, min);
	result.y = ft_clamp(v.y, max, min);
	result.z = ft_clamp(v.z, max, min);
	return (result);
}

double	vec3_cosval(t_vec3 u, t_vec3 v)
{
	double	numerator;
	double	denoinator;

	numerator = vec3_dot(u, v);
	denoinator = vec3_length(u) * vec3_length(v);
	if (denoinator == 0)
		return (INFINITY);
	return (numerator / denoinator);
}
