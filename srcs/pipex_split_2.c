#include "../includes/pipex.h"

static void	*pipex_2d_free(char **s, int row)
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

static char	*pipex_set_end(char *end)
{
	int	j;

	if (*(end + 1) == '\'')
	{
		j = 1;
		while (*(end + 1 + j) != '\'' && *(end + 1 + j) != 0)
			j++;
		if (*(end + 1 + j) == '\'')
			end = end + 1 + j;
	}
	return (end);
}

static int	pipex_put_split(char **temp, char *start, char *end, int row)
{
	size_t	idx;
	size_t	len;

	len = 0;
	while ((start + len) != end)
		len++;
	temp[row] = (char *)malloc(sizeof(char) * (len + 1));
	if (temp[row] == NULL)
	{
		pipex_2d_free(temp, row);
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

static char	**pipex_start_split_2(char *start, char *end, char **temp, int row)
{
	if (*(end - 1) != ' ')
	{
		row = pipex_put_split(temp, start, end, row);
		if (row == -1)
			return (NULL);
	}
	temp[row] = 0;
	return (temp);
}

char	**pipex_start_split(char *start, char *end, char **temp, int row)
{
	while (*end != 0)
	{
		if (*end == ' ')
		{
			end = pipex_set_end(end);
			row = pipex_put_split(temp, start, end, row);
			if (row == -1)
				return (NULL);
			if (*end == '\'')
				end++;
			while (*end != 0 && *end == ' ')
				end++;
			start = end;
			continue ;
		}
		end++;
	}
	return (pipex_start_split_2(start, end, temp, row));
}
