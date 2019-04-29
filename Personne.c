#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure Personne
typedef struct Personne
	{
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
		p=p->suiv;
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
   
   personne *temp, *temp1, *temp3;
   temp=malloc(sizeof(temp));
   temp1=malloc(sizeof(temp1));
   temp3=malloc(sizeof(temp3));
   personne *min;
   min=malloc(sizeof(min));
   for(temp = C->premier ; temp != NULL ; temp=temp->suiv)
   {
    	temp3 = temp;
    	min->nom = (char*)malloc(sizeof(min->nom));
    	min->telephone = (char*)malloc(sizeof(min->telephone));
    	strcpy(min->nom,temp->nom);
    	strcpy(min->telephone,temp->telephone);
     
    	for(temp1=temp->suiv ; temp1!=NULL ; temp1=temp1->suiv)
    	{
    		if(strcmp(min->nom,temp1->nom)>0)
    		{
    			temp3=temp1; // le 3è tempon est l'adresse de l'élement où se trouve le minimum
           		strcpy(min->nom,temp3->nom);
     	   		strcpy(min->telephone,temp3->telephone);
        	}
     	}
     
    	temp3->nom = (char*)malloc(sizeof(temp3->nom));
    	temp3->telephone = (char*)malloc(sizeof(temp3->telephone));
    	temp->nom = (char*)malloc(sizeof(temp->nom));
    	temp->telephone = (char*)malloc(sizeof(temp->telephone));
    	strcpy(temp3->nom,temp->nom);//echange des 2 elements...
    	strcpy(temp->nom,min->nom);
    	strcpy(temp3->telephone,temp->telephone);//echange des 2 elements..
    	strcpy(temp->telephone,min->telephone);  
    
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


	