#include <stdlib.h>

/**
 * string_to_words - Splits a string into words using delimiters.
 *
 * @str: String to be separated into words.
 * @delims: Delimiters used to split the string.
 *
 * Return: 2D array of pointers to each word.
 */
char **string_to_words(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = word_count(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = word_length(str, delims);
		if (is_delimiter(*str, delims))
		{
			str = next_word(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* Set end of string */
		str = next_word(str, delims);
		i++;
	}
	words[i] = NULL; /* Last element is null for iteration */
	return (words);
}

/**
 * is_delimiter - Checks if a character is a delimiter.
 *
 * @ch: Character to be checked.
 * @delims: Pointer to a null-terminated array of delimiters.
 *
 * Return: 1 (success) 0 (failure)
 */
int is_delimiter(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * word_length - Gets the length of the current word in a string.
 *
 * @str: String to get word length from.
 * @delims: Delimiters used to split the words.
 *
 * Return: Word length of the current word.
 */
int word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delimiter(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * word_count - Gets the number of words in a string.
 *
 * @str: String to count words from.
 * @delims: Delimiters used to split the words.
 *
 * Return: The word count of the string.
 */
int word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * next_word - Gets a pointer to the first character of the next word.
 *
 * @str: String to extract the next word from.
 * @delims: Delimiters used to split the words.
 *
 * Return: Pointer to the first character of the next word.
 */
char *next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}

