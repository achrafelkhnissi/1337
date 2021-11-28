#include <stdio.h>
#include <stdlib.h>

char	**ft_split_whitespaces(char *str);
char	*ft_strdup_w(char *str, int *index);
int	word_count(char *str);
int	ft_iswhitespace(char c);

int	main(void)
{
	char	*str = "Future is loading!";
	char	**arr_str;
	int	i;

	i = 0;
	arr_str = ft_split_whitespaces(str);
	while (arr_str[i])
	{
		printf("arr_str[%d] = %s\n", i, arr_str[i]);
		i++;
	}
	return (0);
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
	/* sizeof(*arr_str) == sizeof(char *) == 8 */
	arr_str = (char **) malloc((words + 1) * 8);
	printf("sizeof char *  %lu\n", sizeof(char *));
	if (!arr_str)
		return (NULL);
	while (w_i < words)
	{
		while (ft_iswhitespace(str[i]) && str[i])
			if (!str[i++])
				break;
		arr_str[w_i] = ft_strdup_w(str, &i);
		w_i++;
	}
	arr_str[words] = 0;
	return (arr_str);
}

char	*ft_strdup_w(char *str, int *index)
{
	char	*word;
	int	len;
	int	i;

	i = *index;
	len = 0;
	while (str[i] && !ft_iswhitespace(str[i]))
		len++, i++;;
	word = (char *) malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while(str[*index])
	{
		if (!ft_iswhitespace(str[*index]))
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
		if (!ft_iswhitespace(str[i]))
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

int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
