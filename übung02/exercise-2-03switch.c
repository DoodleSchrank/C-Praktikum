#include <stdio.h>      /* printf */
#include <stdlib.h>     /* atoi */

int main(int argc, char *argv[])
{
  int val = (argc > 1) ? atoi(argv[1]) : 0;

  // Erweitern Sie fuer die Zahlen 0-9, Bsp. für 0
	switch(val)
	{
		case 0: printf("Null\n"); break;
		case 1: printf("Eins\n"); break;
		case 2: printf("Zwei\n"); break;
		case 3: printf("Drei\n"); break;
		case 4: printf("Vier\n"); break;
		case 5: printf("Fünf\n"); break;
		case 6: printf("Sechs\n"); break;
		case 7: printf("Sieben\n"); break;
		case 8: printf("Acht\n"); break;
		case 9: printf("Neun\n"); break;
	}
	return 0;
}
