#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_all - prints anything
* @fmt: list of types of arguments passed to the function
*/

void print_all(const char * const fmt, ...)
{
int index = 0;
char *str_arg, *delimiter = "";

va_list args;

va_start(args, fmt);

if (fmt)
{
while (fmt[index])
{
switch (fmt[index])
{
case 'c':
printf("%s%c", delimiter, va_arg(args, int));
break;
case 'i':
printf("%s%d", delimiter, va_arg(args, int));
break;
case 'f':
printf("%s%f", delimiter, va_arg(args, double));
break;
case 's':
str_arg = va_arg(args, char *);
if (!str_arg)
str_arg = "(nil)";
printf("%s%s", delimiter, str_arg);
break;
default:
index++;
continue;
}
delimiter = ", ";
index++;
}
}

printf("\n");
va_end(args);
}
