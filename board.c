#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "board.h" 
#include "card.h"

#define BUFFER_SIZE 80

//inspired from  "ECAM-C3BE-2017-Mini-Projet-Example"
//martin commentaire pour toi:
//attention à CARD* et à la fonction CreateCard
//il faut que ce sois dans le bon sens
BOARD* loadboard (char *path)
{
	BOARD *board = NULL;
	
	FILE *file = fopen (path, "r");
	if (file != NULL)
	{
		board = malloc (sizeof (BOARD));
		char buffer[BUFFER_SIZE];
		
		// reads the board
		fgets (buffer, BUFFER_SIZE, file);
		board->hp = readInt(file);
		board->boardSize = readInt(file);
		board->mana = readInt(file);
		board->capacity = 7;
		board->cards = malloc (board->capacity * sizeof (CARD*));
		
		// creates a card for every card in the file
		int i;
		for (i = 0; i < board->boardSize; i++)
		{
			board->cards[i] = newCard (readString (file), readString(file),readInt (file), 
				readInt (file), readInt (file), readInt (file));
		}
		
		fclose (file);
	}
	
	return board;
}