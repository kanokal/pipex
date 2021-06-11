/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_math3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:10:14 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/19 14:38:24 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	vec3_length2(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vec3_length(t_vec3 v)
{
	return (sqrt(vec3_length2(v)));
}

t_vec3	vec3_unit(t_vec3 v)
{
	double	len;

	len = vec3_length(v);
	if (len == 0)
		return (vec3_set(0.0, 0.0, 1.0));
	return (vec3_div_val(v, len));
}

t_point	vec3_at(t_vec3 origin, t_vec3 dir, double t)
{
	t_point	at;

	at = vec3_plus(origin, vec3_mult_val(dir, t));
	return (at);
}
