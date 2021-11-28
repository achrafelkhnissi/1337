#include <stdio.h>
#include <stdlib.h>

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
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
	word[len + 1] = '\0';
	(*index)++;
	return (word);
}

int	main(void)
{
	char	*str;
	char	*word;
	char	*word2;
	char	*word3;
	int	i;

	i = 0;
	str = "Future is loading!";
	word = ft_strdup_w(str, &i);
	printf("word = %s\n", word);
	printf("i = %d\n", i);

	while (ft_iswhitespace(str[i]))
		i++;
	word2 = ft_strdup_w(str, &i);
	printf("word2 = %s\n", word2);
	printf("i = %d\n", i);

	while (ft_iswhitespace(str[i]))
		i++;
	word3 = ft_strdup_w(str, &i);
	printf("word3 = %s\n", word3);
	printf("i = %d\n", i);
	
	return (0);
}
