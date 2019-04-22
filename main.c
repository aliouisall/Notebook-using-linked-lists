#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nom_max 32
#define num_max 16

//Structure personne
typedef struct Personne Personne;
struct Personne{
    char nom[nom_max];
    char numTel[num_max];
    Personne *suivant;
};

//Structure Carnet
typedef struct Carnet Carnet;
struct Carnet{
    Personne *premier;
};

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

int main(int argc, char const *argv[])
{
    printf("Carnet d'adresse\n");
    return 0;
}
