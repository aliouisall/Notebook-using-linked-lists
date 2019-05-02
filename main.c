#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Structure Personne
typedef struct Personne{
    char *nom;
    char *telephone;
    struct Personne *suiv;
}personne, *PTR; 

//Structure Carnet
typedef struct Carnet Carnet;
struct Carnet {
    personne *premier;

};

//Fonction renvoyant un pointeur vers une personne
personne *nouveau(char *nom,char *tel, personne *suiv)
{
	personne *personne=malloc(sizeof(personne));
	personne->nom = (char*)malloc(sizeof(nom));
	personne->telephone = (char*)malloc(sizeof(tel));
	strcpy(personne->nom,nom);
	
	strcpy(personne->telephone,tel);
	personne->suiv=suiv;

	return personne;
}

//Fonction permettant d'ajouter une personne à la fin d'un carnet
void ajoute_fin(char *nom, char *tel, Carnet *carnet)
{
	personne *p=carnet->premier;
	
	if(p==NULL)
	{

		p->suiv=nouveau(nom,tel,NULL);
	}

	while(p->suiv != NULL)

  {

		p=p->suiv;
  }
  
  //p=p->suiv;
  p->suiv=nouveau(nom,tel,NULL);
}

//Fonction permettant d'afficher une personne donnée
void AfficherPersonne(personne *p)
{
	if (p == NULL)
	{
		exit(EXIT_FAILURE);
	}

	printf("Le nom de la personne est %s\n", p->nom);
	printf("Le numéro de téléphone de la personne est %s\n", p->telephone);
}

// Fonction permettant d'afficher un carnet
void AfficherCarnet(Carnet *carnet)
{
    
   personne *p=carnet->premier;
	if (p==NULL)
	{
		exit(EXIT_FAILURE);
	}
	do
	{
      AfficherPersonne(p);
      p=p->suiv;

	}while(p!=NULL);

}

//Fonction de tri et d'affichage des personnes d'un carnet 
void Tri(Carnet *C)
{
// ici on va ranger les éléments dans l'ordre croisssant avant de les afficher.
   
   personne *temp, *temp1;
   temp=malloc(sizeof(personne));
   temp1=malloc(sizeof(personne));
   char *v = NULL;
   char *w = NULL;
   personne *min;
   min=malloc(sizeof(personne));

   for(temp = C->premier ; temp != NULL ; temp=temp->suiv)
   {
    	min->nom = (char*)malloc(sizeof(min->nom));
    	min->telephone = (char*)malloc(sizeof(min->telephone));
    	strcpy(min->nom,temp->nom);
    	strcpy(min->telephone,temp->telephone);
     
    	for(temp1=temp->suiv ; temp1!=NULL ; temp1=temp1->suiv)
    	{
    		if(strcmp(min->nom,temp1->nom)>0)
    		{
          w = (char*)malloc(strlen(temp1->nom) + 1);
          strcpy(w,temp1->nom);
          strcpy(temp1->nom, min->nom);
          strcpy(min->nom, w);
        }
     	}
      
      v = (char*)malloc(strlen(temp->nom) + 1);
      strcpy(v, temp->nom);
      temp->nom = (char*)malloc(strlen(min->nom) + 1);
      strcpy(temp->nom,min->nom);
      strcpy(min->nom, v);
     	}

    AfficherCarnet(C);
}

//Fonction qui permet de saisir et d'ajouter des personnes dans un carnet
void SaisiePersonne()
{
	Carnet *C;
	char *nom;
	char *telephone;

	C = malloc(sizeof(Carnet));
	int nbPersonne, i = 0;

	 printf("Donner le nombre de personnes à ajouter\n");
     scanf("%d",&nbPersonne);

    do
    {
    	
        do{
        	nom = (char*)malloc(sizeof(char*));
   			telephone = (char*)malloc(sizeof(char*));
            printf("Donner le nom de la personne à la position %d\n",i+1);
            scanf("%s",nom);
            printf("Donner son numéro de téléphone\n");
            scanf("%s",telephone);

        }while(nom == "" || telephone == "");

        if (i==0)
       	{
       		C->premier=nouveau(nom, telephone, NULL);
        }
        else
        {
            ajoute_fin(nom, telephone, C);
        }
          		
     	i++;
     	nbPersonne--;
    }while(nbPersonne >=1);
    Tri(C);
}

// Fonction qui permet enregistrer des personnes dans un fichier
void record(){

    char occurence[256];
    FILE *file = fopen("personne.txt", "a");

    if (file == NULL)
        exit(1);

    bool tiret = false;
    do
    {
        printf("Saisissez le nom et le numéro en les séparant par un tiret du 6\n");
        fflush(stdin);
        fgets(occurence, 255, stdin);
        int size = sizeof(occurence)/sizeof(occurence[0]);
        for(int i = 0; i < size; i++){
            if(occurence[i] == '-'){
                tiret = true;
            }
        }
    } while (tiret == false);
    fputs(occurence, file);
    
    fclose(file);

}

void readContacts(){
    FILE *file = fopen("personne.txt", "r");
    if (file == NULL)
        exit(1);

    char str[256];
    const char s[2] = "-";
    int compteur = 1;
    while(fgets(str, 255, file)){
        char *token;

        /* get the first token */
        token = strtok(str, s);
        int i = 0;
        while( token != NULL ) {
            if(i == 0){
                printf( "Le nom du contact à la position %d est : %s\n", compteur, token );
            } else {
                printf( "Le numéro de téléphone du contact est : %s\n", token );
            }
            token = strtok(NULL, s);
            i++;
        }
        compteur++;
    }

    fclose(file);
}

int main(int argc, char const *argv[]) {
    
    int choix;

    printf("Carnet d'adresse\n");
    printf("Taper 1 pour ajouter une nouvelle personne\n");
    printf("Taper 2 pour enregistrer des personnes dans un fichier \n");
    printf("Taper 3 pour voir les contacts qui sont dans un fichier \n");
    printf("Taper 4 pour quitter\n");

    printf("Quel est votre choix\n");
    scanf("%d",&choix);

    if(choix == 1){
        SaisiePersonne();
    } else if(choix == 2){
        record();
    } else if(choix == 3){
        readContacts();
    } else if(choix == 4){
        printf("Merci de nous faire confiance !\n");
    } else{
        exit(1);
    }
    return 0;

}
