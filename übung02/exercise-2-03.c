#include <stdio.h>      /* printf */
#include <stdlib.h>     /* atoi */

int main(int argc, char *argv[])
{
  int val = (argc > 1) ? atoi(argv[1]) : 0;

  // Erweitern Sie fuer die Zahlen 0-9, Bsp. für 0
	if(val == 0)
	{
		printf("Null\n");
	}
	else if(val == 1)
	{
		printf("Eins\n");
	}
	else if(val == 2)
	{
		printf("Zwei\n");
	}
	else if(val == 3)
	{
		printf("Drei\n");
	}
	else if(val == 4)
	{
		printf("Vier\n");
	}
	else if(val == 5)
	{
		printf("Fünf\n");
	}
	else if(val == 6)
	{
		printf("Sechs\n");
	}
	else if(val == 7)
	{
		printf("Sieben\n");
	}
	else if(val == 8)
	{
		printf("Acht\n");
	}
	else if(val == 9)
	{
		printf("Neun\n");
	}
	return 0;
}
