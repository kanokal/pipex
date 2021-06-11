/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 01:31:56 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/19 14:30:34 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_next_line_return(char **line, char **str)
{
	char	*tmp;

	tmp = ft_strchr(*str, '\n');
	if (tmp != 0)
	{
		*tmp = 0;
		*line = ft_strdup(*str);
		tmp = ft_strdup(tmp + 1);
		ft_free_int(str);
		*str = tmp;
		return (1);
	}
	else if (*str != 0)
	{
		*line = ft_strdup(*str);
		ft_free_int(str);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		*buf;
	char		*tmp;
	int			idx;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	if ((buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (ft_free_int(&buf));
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	idx = 0;
	while (((ft_strchr(str[fd], '\n')) == 0)
				&& ((idx = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[idx] = 0;
		tmp = ft_strjoin(str[fd], buf);
		ft_free_int(&str[fd]);
		str[fd] = tmp;
	}
	ft_free_int(&buf);
	if (idx < 0)
		return (ft_free_int(&str[fd]));
	return (get_next_line_return(line, &str[fd]));
}
