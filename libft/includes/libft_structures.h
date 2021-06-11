/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:43:33 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/19 14:34:06 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTURES_H
# define LIBFT_STRUCTURES_H

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_bigint
{
	unsigned int	len;
	unsigned int	*bigint;
}					t_bigint;

typedef struct		s_dbl
{
	int				sign;
	t_bigint		*integer;
	t_bigint		*decimal;
}					t_dbl;

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef t_vec3		t_point;
typedef t_vec3		t_color;

#endif
