#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "hand.h" 
#include "card.h"

#define BUFFER_SIZE 80

//inspired from  "ECAM-C3BE-2017-Mini-Projet-Example"
//martin commentaire pour toi:
//attention à CARD* et à la fonction CreateCard
//il faut que ce sois dans le bon sens
HAND* loadHand (char *path)
{
	HAND *hand = NULL;
	
	FILE *file = fopen (path, "r");
	if (file != NULL)
	{
		hand = malloc (sizeof (HAND));
		char buffer[BUFFER_SIZE];
		
		// reads the hand
		fgets (buffer, BUFFER_SIZE, file);
		hand->handSize = readInt(file);
		hand->capacity = 10;
		hand->cards = malloc (hand->capacity * sizeof (CARD*));
		
		// creates a card for every cxard in the file
		int i;
		for (i = 0; i < hand->handSize; i++)
		{
			char *name = readString (file);
			char *meca = readString (file);
			hand->cards[i] = newCard (name, meca,readInt (file), 
				readInt (file), readInt (file), readInt (file));
		}
		
		fclose (file);
	}
	
	return hand;
}
/*
int main(int argc, char const *argv[])
{
	char *path = malloc (BUFFER_SIZE * sizeof (char));
	char *quit = malloc (BUFFER_SIZE * sizeof (char));
	printf ("* Votre main: ");
	scanf ("%s", path);
	HAND* hand = loadHand(path);



	int i;
	for (i = 0; i < hand->handSize; ++i)
	{
		printCard(hand->cards[i]);
	}

	scanf ("%s", quit);

	return 0;
}
*/