#include<stdio.h>
#include<stdlib.h>

int affichemenu()
{
int choix;

printf("**************menu************\n");
printf("Taper 1 pour ajouter une nouvelle personne\n");
printf("Taper 2 pour afficher le carnet \n");
printf("Taper 3 pour quitter\n");

printf("Quel est votre choix\n");
scanf("%d",&choix);
return choix;

}
void main()
{
	//creer une personne
      PTR personne = (PTR)malloc(sizeof(personne));
      Carnet*carnet = malloc(sizeof(*carnet));
       //creer une carnet
	int choix;
	char nom[50],numero[50];
	//On appel la fonction restaurer pour restaurer l'ancien carnet
	do
	{
	 	choix=affichemenu();
		if(choix==1)
		{
		//on ajoute la personne 
                   printf("Veuillez entrer le nom de la personne\n");
                   scanf("%s",nom),
                   printf("Veuillez entrer le numero de lq personne\n");
                   scanf("%s",numero);
                    
                   personne = creerpersonne(nom,numero,NULL);
                   carnet = ajoutepersonne(carnet,personne);

                  

		}
		else if(choix==2)
		{
                // on affiche le carnet
                 printf("Afficher carnet");
                 affichecarnet(carnet);

		}
		else
		{
                   printf("Merci\n");
                 

                 }
           return 0;		
	}
	while(choix==1 ||choix==2 || choix==3)


	
  return 0;
}

