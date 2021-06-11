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

static char	**ft_alloc_2d(char const *s, char c)
{
	char	**temp;
	size_t	idx;
	size_t	len;

	idx = 0;
	if (s[0] == c)
		idx = 1;
	len = 0;
	while (s[idx])
	{
		if (s[idx] == c && s[idx - 1] != c)
			len++;
		idx++;
	}
	if (s[idx - 1] != c)
		len++;
	if ((temp = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (ft_2d_free(temp, -1));
	temp[len] = 0;
	return (temp);
}

static int	ft_put_split(char **temp, char *start, char *end, int row)
{
	size_t	idx;
	size_t	len;

	len = 0;
	while ((start + len) != end)
		len++;
	if ((temp[row] = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
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
	int		idx;

	end = start;
	idx = 0;
	while (end[idx])
	{
		if (end[idx] == c)
		{
			if ((row = ft_put_split(temp, start, (end + idx), row)) == -1)
				return (NULL);
			start = (end + idx);
			while (*start && *start == c)
				start++;
			end = start;
			idx = -1;
		}
		idx++;
	}
	if (end[idx - 1] != c)
		if ((row = ft_put_split(temp, start, (end + idx), row)) == -1)
			return (NULL);
	temp[row] = 0;
	return (temp);
}

char		**ft_split(char const *s, char c)
{
	char	**temp;
	char	*start;

	if (ft_strlen(s) == 0)
	{
		temp = (char **)malloc(sizeof(char *));
		if (temp == NULL)
			return (NULL);
		*temp = 0;
		return (temp);
	}
	if ((temp = ft_alloc_2d(s, c)) == NULL)
		return (NULL);
	start = (char *)s;
	while (*start && *start == c)
		start++;
	return (ft_start_split(start, c, temp, 0));
}
