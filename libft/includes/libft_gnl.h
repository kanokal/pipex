/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_gnl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:12:05 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/11 03:03:31 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GNL_H
# define LIBFT_GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int	get_next_line(int fd, char **line);

#endif
