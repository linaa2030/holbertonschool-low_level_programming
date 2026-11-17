#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts space-separated words
 * @str: input string
 *
 * Return: number of words
 */
static size_t count_words(char *str)
{
	size_t count = 0;

	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str)
			count++;
		while (*str && *str != ' ')
			str++;
	}
	return (count);
}

/**
 * copy_word - copies one word and advances the input pointer
 * @str: address of the current input pointer
 *
 * Return: allocated word, or NULL on failure
 */
static char *copy_word(char **str)
{
	char *word;
	size_t len = 0, i;

	while (**str == ' ')
		(*str)++;
	while ((*str)[len] && (*str)[len] != ' ')
		len++;
	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		word[i] = (*str)[i];
	word[len] = '\0';
	*str += len;
	return (word);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: array of words, or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	size_t count, i;

	if (str == NULL || *str == '\0')
		return (NULL);
	count = count_words(str);
	if (count == 0 || count >= (size_t)-1 / sizeof(char *))
		return (NULL);
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
	{
		words[i] = copy_word(&str);
		if (words[i] == NULL)
		{
			while (i > 0)
				free(words[--i]);
			free(words);
			return (NULL);
		}
	}
	words[i] = NULL;
	return (words);
}
