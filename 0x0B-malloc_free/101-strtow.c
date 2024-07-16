#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/* These are prototypes for helper functions*/
static int count_words(char *str);
static char *copy_word(char *str, int start, int end);

/**
* strtow - splits a string into words.
* @str: input string to split
*
* Return: pointer to an array of strings (words), or NULL if str is NULL or ""
*/

char **strtow(char *str)
{
char **words;
int i, j, len, word_count, start;

if (str == NULL || *str == '\0')
return (NULL);

word_count = count_words(str);
if (word_count == 0)
return (NULL);

words = malloc(sizeof(char *) * (word_count + 1));
if (words == NULL)
return (NULL);

j = 0;
len = 0;
while (str[len] != '\0')
len++;

for (i = 0; i < len && j < word_count; i++)
{
if (str[i] == ' ')
continue;

start = i;
while (str[i] != ' ' && str[i] != '\0')
i++;

words[j] = copy_word(str, start, i);
if (words[j] == NULL)
{
while (j > 0)
free(words[--j]);
free(words);
return (NULL);
}

j++;
}

words[word_count] = NULL;

return (words);
}

/**
* count_words - counts the number of words in a string.
* @str: input string
* Return: number of words
*/

static int count_words(char *str)
{
int count = 0, i = 0;

while (str[i] != '\0')
{
while (str[i] == ' ')
i++;

if (str[i] != '\0')
count++;

while (str[i] != ' ' && str[i] != '\0')
i++;
}

return (count);
}

/**
* copy_word - copies a word from a string.
* @str: input string
* @start: starting index of the word
* @end: ending index of the word
* Return: pointer to the copied word
*/

static char *copy_word(char *str, int start, int end)
{
char *word;
int i;

word = malloc(sizeof(char) * (end - start + 1));
if (word == NULL)
return (NULL);

for (i = start; i < end; i++)
word[i - start] = str[i];

word[i - start] = '\0';

return (word);
}
