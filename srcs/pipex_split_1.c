#include "../includes/pipex.h"

static size_t	get_pipex_split_len(char const *s, int idx, int j, int len)
{
	while (s[idx] != 0)
	{
		if (s[idx] == ' ')
		{
			if (s[idx + 1] == '\'')
			{
				j = 1;
				while (s[idx + 1 + j] != '\'' && s[idx + 1 + j] != 0)
					j++;
				if (s[idx + 1 + j] == '\'')
				{
					idx = idx + 1 + j;
					if (s[idx + 1] == ' ')
						idx++;
				}
			}
			len++;
		}
		idx++;
	}
	if (s[idx - 1] != ' ')
		len++;
	return (len);
}

char	**pipex_split(char const *s)
{
	size_t	len;
	char	**temp;
	char	*start;

	if (ft_strlen(s) <= 0)
	{
		temp = (char **)malloc(sizeof(char *));
		temp[0] = 0;
		return (temp);
	}
	len = get_pipex_split_len(s, 0, 0, 0);
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	if (temp == NULL)
		return (NULL);
	temp[len] = 0;
	start = (char *)s;
	return (ft_start_split(start, start + 1, temp, 0));
}
