#include "main.h"
#include <stdlib.h>

/**
* argstostr - A function concatenates all the arguments of your program.
* @ac: argument count
* @av: argument vector (array of strings)
* Return: pointer to the concatenated string, or NULL on failure
*/

char *argstostr(int ac, char **av)
{
char *concat_str;
int i, j, total_length = 0;
int k = 0;

if (ac == 0 || av == NULL)
return (NULL);
for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j] != '\0')
{
total_length++;
j++;
}
total_length++;
}
total_length++;
concat_str = malloc(sizeof(char) * total_length);
if (concat_str == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j] != '\0')
{
concat_str[k] = av[i][j];
j++;
k++;
}
concat_str[k] = '\n';
k++;
}

concat_str[k] = '\0';

return (concat_str);
}
