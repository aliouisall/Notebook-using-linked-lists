#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure personne
typedef struct Personne Personne;
struct Personne{
    char *nom;
    char *numTel;
    Personne *suivant;
};

//Structure Carnet
typedef struct Carnet Carnet;
struct Carnet{
    Personne *premier;
};

//Fonction qui creer une personne

// PTR CreerPersonne(char *nom, char *telephone, PTR suiv)
// {
//     PTR n = (PTR)malloc(sizeof(personne));
//     n->nom = (char *)malloc(strlen(nom) + 1);
//     n->telephone = (char*)malloc(strlen(telephone) + 1);
//     n->suiv = suiv;
//     return n;
// }

// Fonction d'initialisation du carnet
Carnet *initialisation()
{
    Carnet *carnet = malloc(sizeof(*carnet));
    Personne *personne = malloc(sizeof(*personne));

    if (carnet == NULL || personne == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(personne->nom, "");
    strcpy(personne->numTel, "");
    personne->suivant = NULL;
    carnet->premier = personne;

    return carnet;
}

// Fonction d'affichage du carnet
void afficherCarnet(Carnet *carnet){
    
    if (carnet == NULL){
        exit(EXIT_FAILURE);
    }

    Personne *actuel = carnet->premier;
    int i = 1;

    while (actuel != NULL){
        printf("Position - %d | Nom : %s et Numéro de téléphone : %s \n", i, actuel->numTel, actuel->nom);
        actuel = actuel->suivant;
    }
    printf("NULL\n");

}

int main(int argc, char const *argv[])
{
    printf("Carnet d'adresse\n");
    return 0;
}
