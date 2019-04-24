#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct Personne
	{
		char *nom;
		char *telephone;
		struct Personne *suiv;
		
	}personne, *PTR; 

PTR CreerPersonne(char *nom, char *telephone, PTR suiv)
{
	PTR n = (PTR)malloc(sizeof(personne));
	n->nom = (char *)malloc(strlen(nom) + 1);
	n->telephone = (char*)malloc(strlen(telephone) + 1);
	n->suiv = suiv;
	return n;
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}