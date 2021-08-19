/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:54:20 by jpyo              #+#    #+#             */
/*   Updated: 2021/05/01 20:52:13 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	*ft_2d_free(char **s, int row)
{
	while (row >= 0)
	{
		free(s[row]);
		s[row] = NULL;
		row--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static int	ft_put_split(char **temp, char *start, char *end, int row)
{
	size_t	idx;
	size_t	len;

	len = 0;
	while ((start + len) != end)
		len++;
	temp[row] = (char *)malloc(sizeof(char) * (len + 1));
	if (temp[row] == NULL)
	{
		ft_2d_free(temp, row);
		return (-1);
	}
	idx = 0;
	while (idx < len)
	{
		temp[row][idx] = start[idx];
		idx++;
	}
	temp[row][idx] = 0;
	return (row + 1);
}

static char	**ft_start_split(char *start, char c, char **temp, int row)
{
	char	*end;

	end = start;
	while (*end != 0)
	{
		if (*end == c)
		{
			row = ft_put_split(temp, start, end, row);
			if (row == -1)
				return (NULL);
			while (*end != 0 && *end == c)
				end++;
			start = end;
			continue ;
		}
		end++;
	}
	if (*(end - 1) != c)
	{
		row = ft_put_split(temp, start, end, row);
		if (row == -1)
			return (NULL);
	}
	temp[row] = 0;
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	size_t	idx;
	size_t	len;
	char	**temp;
	char	*start;

	idx = 0;
	len = 0;
	while (s[idx] != 0)
	{
		if (s[idx] == c && s[idx - 1] != c)
			len++;
		idx++;
	}
	if (idx != 0 && s[idx - 1] != c)
		len++;
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	if (temp == NULL)
		return (NULL);
	temp[len] = 0;
	start = (char *)s;
	while (*start != 0 && *start == c)
		start++;
	if (*start == 0)
		return (temp);
	return (ft_start_split(start, c, temp, 0));
}
