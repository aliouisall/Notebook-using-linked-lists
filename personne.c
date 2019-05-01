#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure Personne
typedef struct Personne{
    char *nom;
    char *telephone;
    struct Personne *suiv;
    
}personne, *PTR; 

//Structure Carnet
typedef struct Carnet Carnet;
struct Carnet
{
    personne *premier;

};

//creation d'un nouvelle personne 
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

//Procedure qui ajoute une personne a la fin d'un carnet
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

//Fonction qui permet d'afficher une personne donnee
void AfficherPersonne(personne *p)
{
	if (p == NULL)
	{
		exit(EXIT_FAILURE);
	}

	printf("le nom de la personne est %s\n", p->nom);
	printf("Le telephone de la personne est %s\n", p->telephone);
}

// Fonction d'affichage d'un carnet
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

//Procedure de tri et d'affichage des personnes d'un carnet 
void Tri(Carnet *C)
{
// ici on va ranger les elements dans l'ordre croisssant avant de les afficher.
   
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

//Procedure qui permet de saisir et d'ajouter des personnes dans un carnet
void SaisiePersonne()
{
	Carnet *C;
	char *nom;
	char *telephone;

	C = malloc(sizeof(Carnet));
	int nbPersonne, i = 0;

	 printf("donner le nombre de personnes a ajouter\n");
     scanf("%d",&nbPersonne);

    do
    {
    	
        do{
        	nom = (char*)malloc(sizeof(char*));
   			telephone = (char*)malloc(sizeof(char*));
            printf("donner le nom de la personne numero %d\n",i+1);
            scanf("%s",nom);
            printf("Donner son numero de telephone\n");
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

int main(int argc, char const *argv[])
{
	
	SaisiePersonne();
	//AjoutPersonne(C, p);
	//AfficherPersonne(*p);
	//AfficherCarnet(C);

	return 0;
}