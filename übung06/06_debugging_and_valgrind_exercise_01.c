#include <stdio.h>

//Keine Ziffern an erster Stelle von Methodennamen oder Variablennamen +  return benötigt erforderlichen returntyp (int)
//Ich habe ehrlich gesagt keine Ahnung, ob ich hier mit dem Charwert multiplizieren soll, oder ob das in Zeile 34-ish einfach weg soll.
int OOO00O(int eingabe)
{
	return eingabe*eingabe;
}

//return char, nicht char *, da nach Funktionsaufruf der "output = 'A'" vom Stack gelöscht wird
char testfunktion00()
{
	char output = 'A';
	printf("Diese Funktion testet auch etwas\n");

	return output;
}

void testfunktion01(char eingabe)
{
	printf("Eingabe war %d\n", eingabe);
}


int main()
{
	int counter = 0;
	//Bindestrich böse! + unused
	//char beliebigeszeichen = 'J';
	char charOut;
	//added and unused :(
	//int someint;

	//Ein ; zu viel
	for(;;)
	{
		counter++;
		//OOO00O erwartet nur einen Integer und gibt wiedere einen aus + unused
		//someint = OOO00O(counter);
		charOut = testfunktion00();
		testfunktion01(charOut);
		//Vergleiche mit ==, Zuweisung mit =
		if(counter%10 == 0)
		{
			break;
		}
	}
	//Die Funktion gibt es gar nicht!
	//testfunktion();

	//Semikolon grrr >:(
	printf("Das Programm konnte erfolgreich kompiliert werden!\n");
	return 0;
}


