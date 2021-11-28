/*
** We are going to get a string and chop it up into words
** Words in this case are defined as anything that is split by whitespaces
** In: Got Mi-lk and  beef 1903821 /?1-231=       askdjad     ak//sjd?a
** we have, Got, Mi-lk and beef 1903821 /?1-231= askdjad ak//sjd?a
** We want to get each of these words, and store them in an array,
** The last element in this array will be equal to 0 (aka null pointer)
** This will show that we are at the end of the array of words.
** Separators are spaces tabs and line breaks- as it says in the d07/ex04
**
** So the first thing we should do is find the number of words
** Make an array of char pointers.
** allocate the array of char pointers the number of words long, plus one.
** allocate enough memory for the size of the word for each string + 1
**  this is for the '\0' at the end of the string.
** Now we should add the words to the array of char pointers
*/

#define WHITESPACE(x) x == '\t' || x == '\n' || x == ' '

#include <stdlib.h>

int				ft_word_size(char *str);
int				ft_word_count(char *str);

char			**ft_split_whitespaces(char *str)
{
	int		word_count;
	int		words_entered;
	int		i;
	char	**words;
	char	*word;

	i = 0;
	words_entered = 0;
	word_count = ft_word_count(str);
	words = (char**)malloc(sizeof(char*) * (word_count + 1));
	while (words_entered < word_count)
	{
		word = (char*)malloc(sizeof(char) * (ft_word_size(str) + 1));
		while (WHITESPACE(str[0]) && str[0] != '\0')
			str++;
		while (!(WHITESPACE(str[0])) && str[0] != '\0')
			word[i++] = *str++;
		word[i] = '\0';
		words[words_entered++] = word;
		i = 0;
	}
	words[word_count] = 0;
	return (words);
}

/*
** We need to count the words in out str,
** So lets run a loop while we are not at the end of str, str[i] == '\0'
**  so lets skip past all the whitespace we have,
**  //when we hit a word, let's count how long it is
**  when we hit another white space or the end of str
**  we need to check for trailing white space too!
** we should wordcount++ since we did find a word.
** return wordcount
*/

int				ft_word_count(char *str)
{
	int word_count;
	int i;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		while (WHITESPACE(str[i]) && str[i] != '\0')
			i++;
		while (!(WHITESPACE(str[i])) && str[i] != '\0')
			i++;
		while (WHITESPACE(str[i]) && str[i] != '\0')
			i++;
		word_count++;
	}
	return (word_count);
}

int				ft_word_size(char *str)
{
	int i;

	i = 0;
	while (WHITESPACE(str[i]) && str[i] != '\0')
		str++;
	while (!(WHITESPACE(str[i])) && str[i] != '\0')
		i++;
	return (i);
}
