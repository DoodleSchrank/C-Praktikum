#include <stdio.h>
#include <stdlib.h>

#define INVALID_INDEX	-1

// Koordinaten-Struct, keine Änderungen notwendig
typedef struct
{
	//Koordinaten
	int x, y;
} myCoordinate;

typedef struct node
{
	myCoordinate *koordinaten;
	struct node *next;
} node_t;

//Methode kann verwendet werden, um die Ausgabe in den print-Methoden zu realisieren
void printStruct(myCoordinate *input)
{
	printf("%d\t%d\n", input->x, input->y);
}

//##############################################################################
//##############################################################################
//##############################################################################

// Eine neue Struct-Speicher-Datenstruktur wird angelegt und ist nach Rückgabe
// betriebsbereit
node_t *createStructStorage()
{
	// wir erstellen erst eine Struktur sobald wir etwas speichern
	return NULL;
}

node_t *createNode(myCoordinate *item)
{
	node_t *node = malloc(sizeof(node_t));
	node->koordinaten = item;
	node->next = NULL;
	return node;
}

void freeNode(node_t *node)
{
	// breche ab, wenn node leer
	if (node == NULL) return;

	// freigeben der Koordinaten, falls vorhanden
	if (node->koordinaten) free(node->koordinaten);

	// freigeben des nodes
	free(node);
}

// Der Speicher der Struct-Speicher-Datenstruktur sowie aller noch gespeicherten
// Koordinaten-Structs wird freigegeben
void freeStructStorage(node_t *head)
{
	// breche ab, wenn head leer
	if (head == NULL) return;

	if (head->next)
	{
		// rekursives freigeben der heade
		freeStructStorage(head->next);
	}

	freeNode(head);
}

node_t *getNode(node_t *head, size_t pos)
{
	node_t *node = head;
	while (node && pos != 0)
	{
		node = node->next;
		pos--;
	}

	// if pos is not 0 then there is no item at given pos
	if (pos != 0)
	{
		return NULL;
	}

	return node;
}

myCoordinate *getItem(node_t *head, size_t pos)
{
	node_t *node = getNode(head, pos);
	if (node == NULL) return NULL;

	return node->koordinaten;
}

//##############################################################################

// Füge ein neues Element am Ende des Struct-Speichers ein
void insert(node_t **head, myCoordinate *item)
{
	// erstelle neues element
	node_t *new = createNode(item);

	// wenn Liste leer: neues Element ist Anfang
	if (*head == NULL)
	{
		*head = new;
		return;
	}

	// finde letztes Element
	node_t *curr = *head;
	while (curr->next)
	{
		curr = curr->next;
	}
	// füge neues Element ans Ende an
	curr->next = new;
}

// Füge ein neues Element an Position pos ein
int insertAt(node_t **head, size_t pos, myCoordinate *item)
{
	// erstelle neues element
	node_t *new = createNode(item);

	// wenn Anfang: neues Element ist Anfang
	if (pos == 0)
	{
		new->next = *head;
		*head = new;
		return 0;
	}

	// finde Element vor pos
	node_t *start = getNode(*head, pos-1);
	if (start == NULL)
	{
		printf("Invalid index %ld.\n", pos);
		return INVALID_INDEX;
	}

	// [pos-1] => [new] => [pos]

	// [new] => [pos]
	new->next = start->next;
	// [pos-1] => [new]
	start->next = new;

	return 0;
}

//##############################################################################

// Gib die Koordinaten des Elements an Position pos aus
void printAt(node_t *head, size_t pos)
{
	myCoordinate *item = getItem(head, pos);
	if (item)
	{
		printStruct(item);
	}
	else
	{
		printf("Invalid index %ld.\n", pos);
	}
}

// Gib die Koordinaten der Elemente zwischen den Positionen pos1 und pos2 aus
void printRange(node_t *head, size_t pos1, size_t pos2)
{
	// pos1 muss kleinergleich pos2 sein
	if (pos1 > pos2) return;

	size_t i = 0;
	node_t *curr = head;
	while (curr && i <= pos2)
	{
		if (i >= pos1) printStruct(curr->koordinaten);
		curr = curr->next;
		i++;
	}
}

// Gib die Koordinaten aller Elemente aus
void printAll(node_t *head)
{
	node_t *curr = head;
	while (curr)
	{
		printStruct(curr->koordinaten);
		curr = curr->next;
	}
}

//##############################################################################

// Lösche das Element an Position pos
int deleteAt(node_t **head, size_t pos)
{
	if (*head == NULL) return INVALID_INDEX;

	if (pos == 0)
	{
		node_t *next = (*head)->next;
		freeNode(*head);
		*head = next;
		return 0;
	}

	node_t *prev = getNode(*head, pos-1);
	if (prev == NULL || prev->next == NULL)
	{
		printf("Invalid index %ld.\n", pos);
		return INVALID_INDEX;
	}
	
	// [prev] => [delete this] => [next]

	// finde [next]
	node_t *next = prev->next->next;

	// free [delete this]
	freeNode(prev->next);

	// [prev] => [next]
	prev->next = next;

	return 0;
}

// Lösche alle Elemente zwischen den Positionen pos1 und pos2
int deleteRange(node_t **head, size_t pos1, size_t pos2)
{
	// pos1 muss kleinergleich pos2 sein
	if (pos1 > pos2) return INVALID_INDEX;

	if (pos1 == 0)
	{
		node_t *end = getNode(*head, pos2);
		if (end == NULL)
		{
			printf("Invalid index %ld.\n", pos2);
			return INVALID_INDEX;
		}
		node_t *old = *head;
		*head = end->next;
		end->next = NULL;
		freeStructStorage(old);
		return 0;
	}

	node_t *prev = getNode(*head, pos1-1);
	if (prev == NULL)
	{
		printf("Invalid index %ld.\n", pos1);
		return INVALID_INDEX;
	}
	
	deleteRange(&prev->next, 0, pos2 - pos1);
	return 0;
}

// Leere die gesamte Struct-Speicher-Datenstruktur
void deleteAll(node_t **head)
{
	freeStructStorage(*head);
	*head = NULL;
}

//##############################################################################

size_t getSize(node_t *head)
{
	size_t numElements = 0;
	while (head)
	{
		numElements++;
		head = head->next;
	}

	return numElements;
}

// Gib die Anzahl enthaltener Elemente aus
void printSize(node_t *head)
{
	printf("Gesamtzahl Elemente: %ld\n", getSize(head));
}

//##############################################################################
//##############################################################################
//##############################################################################
// Nachfolgend ein paar Testmethoden, die bei der Korrektheitsprüfung helfen
// sollen. An den test-Methoden muss nichts geändert werden, Sie können sie aber
// natürlich bei Bedarf erweitern

// Einfacher Ausgabetest
void test1()
{
	printf("Test1:\n");
	myCoordinate *test = (myCoordinate*)malloc(sizeof(myCoordinate));
	test->x = 1;
	test->y = 10;

	node_t *storage = createStructStorage();
	insert(&storage, test);

	// Die beiden nachfolgenden Methoden sollten die gleiche Ausgabe produzieren
	printAll(storage);
	printStruct(test);

	freeStructStorage(storage);
}

// Hinzufügen und löschen einzelner Elemente
void test2()
{
	printf("Test2:\n");

	myCoordinate **testArray = (myCoordinate **)malloc(3*sizeof(myCoordinate*));
	for (int i = 0; i < 3; ++i)
	{
		testArray[i] = (myCoordinate *)malloc(sizeof(myCoordinate));
		testArray[i]->x = i;
		testArray[i]->y = i*10;
	}

	node_t *storage = createStructStorage();

	insert(&storage, testArray[0]);
	insert(&storage, testArray[1]);
	insertAt(&storage,0,testArray[2]);

	printSize(storage);

	deleteAt(&storage,1);

	printSize(storage);
	printAll(storage);

	freeStructStorage(storage);
	free(testArray);
}

// Hinzufügen und Löschen ganzer Bereiche
void test3()
{
	printf("Test3:\n");

	node_t *storage = createStructStorage();

	myCoordinate **testArray = (myCoordinate **)malloc(10*sizeof(myCoordinate*));
	for (int i = 0; i < 10; ++i)
	{
		testArray[i] = (myCoordinate *)malloc(sizeof(myCoordinate));
		testArray[i]->x = i;
		testArray[i]->y = i*10;

		insert(&storage,testArray[i]);
		printAt(storage,i);
	}
	printSize(storage);

	printRange(storage,0,4);
	deleteRange(&storage,0,2);
	printRange(storage,0,4);

	printSize(storage);

	deleteAll(&storage);

	printSize(storage);

	freeStructStorage(storage);
	free(testArray);
}

//##############################################################################
//##############################################################################
//##############################################################################

int main()
{
	test1();
	printf("\n");
	test2();
	printf("\n");
	test3();
	return 0;
}
