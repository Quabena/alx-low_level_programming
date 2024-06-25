#include "main.h"

/**
* jack_bauer - Prints every minutes of day from 00:00 to 23:59
*
* Description: uses nested loops to iterate through each hour
* and minute of the day. The printed time is in HH:MM format
*/
void jack_bauer(void)
{
int hour, minute;

for (hour = 0; hour < 24; hour++)
{
for (minute = 0; minute < 60; minute++)
{
_putchar((hour / 10) + '0');
_putchar((hour % 10) + '0');
_putchar(':');
_putchar((minute / 10) + '0');
_putchar((minute % 10) + '0');
_putchar('\n');
}
}
}
