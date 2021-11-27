#include <stdio.h>
#include "split_test.c"
//#include "src/count_words.c"

int	main(void)
{
	char	**result;
	char	*str;
	char	*sap;
	int	i;

	str = "Future is loading!";
	sap = "is";
	i = 0;
	printf("str: %s\n", str);
	printf("words: %d\n", count_words(str, sap));
	while (str[i])
	{
		if (is_saperator(str[i], sap))
			printf("saperator = %c\n", str[i]);
		i++;
	}
	result = ft_split(str, sap);
	i = 0;
	while (result[i])
		printf("str[%d] = %s\n",i ,result[i]), i++;
	return (0);
}
