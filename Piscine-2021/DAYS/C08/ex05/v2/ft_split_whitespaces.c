#include "ft_stock_par.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	word_count(char *str)
{
	int	i;
	int	w_count;
	int	state;

	i = 0;
	w_count = 0;
	state = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i]))
		{
			if (!state)
				w_count++;
			state = 1;
		}
		else
			state = 0;
		i++;
	}
	return (w_count);
}

char	*ft_strdup_w(char *str, int *index)
{
	char	*word;
	int	len;
	int	i;

	i = *index;
	len = 0;
	while (str[i] && !is_whitespace(str[i]))
		len++, i++;;
	word = (char *) malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while(str[*index])
	{
		if (!is_whitespace(str[*index]))
		{
			word[i++] = str[*index];
			(*index)++;
		}
		else
			break;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split_whitespaces(char *str)
{
	char	**arr_str;
	int	i;
	int	words;
	int	w_i;

	i = 0;
	w_i = 0;
	words = word_count(str);
	arr_str = (char **) malloc((words + 1) * 8);
	if (!arr_str)
		return (NULL);
	while (w_i < words)
	{
		while (is_whitespace(str[i]) && str[i])
			if (!str[i++])
				break;
		arr_str[w_i] = ft_strdup_w(str, &i);
		w_i++;
	}
	arr_str[words] = 0;
	return (arr_str);
}
