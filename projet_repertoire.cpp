#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define c '@'
#define x '.'

typedef struct profil profil;

struct profil{
	int id;
	char nom[20];
	char prenom[20];
	int numero;
	char adresse_email[30];
	char ville[20];

};
struct profil pro; 

/*rechercher un contact*/

int rech(int idrech){
	FILE*F;
	F=fopen("profil.txt","r");
	do{
		fscanf(F,"%d  %s  %s  %d  %s  %s\n",&pro.id,&pro.nom,&pro.prenom,&pro.numero,&pro.adresse_email,&pro.ville);
		if(pro.id==idrech){
			fclose(F);
			return 1;
		}
	}while(!feof(F));
	fclose(F);
	return -1;
}
/*ajouter un contact*/
void ajouter_un_contact()
{
	FILE*F;
	char*c1,*c2;
	int pos1,pos2;
	int i,idA;
	bool trouve=false;
	F=fopen("profil.txt","a");
	printf("entrer l'id du nouveau contact:");
	scanf("%d",&idA);
	while(rech(idA)==1){
		printf("\n le contact existe deja");
		printf("\n entrer l'id du nouveau contact:");
		scanf("%d",&idA);
	}
	pro.id=idA;
	printf("\nentrer le nom:");
	scanf("%s",pro.nom);
	printf("\nentrer le prenom:");
	scanf("%s",pro.prenom);
	printf("\nentrer le numero:");
    scanf("%d",&pro.numero);
    fflush(stdin);
    printf("\nentrer votre adresse:");
    scanf("%s",&pro.adresse_email);		
	printf("\nentrer la ville:");
	scanf("%s",&pro.ville);
	fflush(stdin);
	fprintf(F,"%d  %s  %s  %d  %s  %s\n",pro.id,pro.nom,pro.prenom,pro.numero,pro.adresse_email,pro.ville);
	fclose(F);
	
}

/*recherche et affichage */
void recherche_contact()
{
	FILE*F;
	int idR;
	printf("entrer l'id du contact rechercher :");
	scanf("%d",&idR);
	F=fopen("profil.txt","r");
	bool trouve=false;
	do
	{
		fscanf(F,"%d  %s  %s  %d  %s  %s\n",&pro.id,&pro.nom,&pro.prenom,&pro.numero,&pro.adresse_email,&pro.ville);
		
		if(idR==pro.id)
    	{
    		trouve=true;
    		printf("\n****les informations du contact recherché sont********\n");
			printf("l'id\t:%d\n",pro.id);
			printf("le nom\t:%s\n",pro.nom);
			printf("le prenom\t:%s\n",pro.prenom);
			printf("le numero\t:%d\n",pro.numero);
			printf("l'adresse\t:%s\n",pro.adresse_email);
			printf("la ville\t:%s\n",pro.ville);
			
		}
         
		 
	}while(!feof(F));
	if(trouve!=true){
		printf("ce contact n'existe pas");
	}
	
		  
	fclose(F);	
}
/*suppression d'un contact*/

void supprimer_contact()
{
	char reponse='n';
	FILE*F;
	int idS;
	printf("entrer l'id du contact a supprimer:");
	scanf("%d",&idS);
	fflush(stdin);
	if(rech(idS)==1){
		printf("\n voulez vous vraiment supprimer ce contact o/n ? :");
		scanf("%c",&reponse);
		fflush(stdin);
		if(reponse=='o'||reponse=='O')
		 {
		 	FILE *fich,*F;
		 	F=fopen("profil.txt","r");
		 	fich=fopen("temp_profil.txt","a");
		 	do
		 	{
		 		fscanf(F,"%d  %s  %s  %d  %s  %s\n",&pro.id,&pro.nom,&pro.prenom,&pro.numero,&pro.adresse_email,&pro.ville);
		 		if(idS!=pro.id)
		 		{
		 		   fprintf(fich,"%d  %s  %s  %d  %s  %s\n",pro.id,pro.nom,pro.prenom,pro.numero,pro.adresse_email,pro.ville);
				 }
			 }while(!feof(F));
			 fclose(F);
			 fclose(fich);
			 remove("profil.txt");
			 rename("temp_profil.txt","profil.txt");
			 printf("suppression effectuée avec succes\n");
		 	
		 }else 
		 {
		 	printf("suppression annulée");
		 }
	}else 
	{
		printf("ce contact n'existe pas");
	}

	
}

/*madification d'un contact*/

void modifier_contact()
{
	int idM,i;
	char*c1,*c2;
	int pos1,pos2;
	bool trouve=false;
	char reponse='n';
	printf("entrer l'identifiant du contact a modifier:");
	scanf("%d",&idM);
	fflush(stdin);
	if(rech(idM)==1)
	  {
	  	printf("voulez vous vraiment modifier ce contact o/n ? :");
	  	scanf("%c",&reponse);
	  	fflush(stdin);
	  	if(reponse=='o'||reponse=='O')
	  	  {
	  	  	FILE *F,*fich;
	  	  	F=fopen("profil.txt","r");
	  	  	fich=fopen("temp.txt","a");
	  	  	do
	  	  	{
	  	        fscanf(F,"%d  %s  %s  %d  %s  %s\n",&pro.id,&pro.nom,&pro.prenom,&pro.numero,&pro.adresse_email,&pro.ville);
	  	        fflush(stdin);
	  	  		if(idM==pro.id){
	  	  		pro.id=idM;
	  	  		printf("\nentrer le nouveau nom:");
	  	  		scanf("%s",&pro.nom);
	  	  		fflush(stdin);
	  	  		printf("\nentrer le nouveau prenom:");
	  	  		scanf("%s",&pro.prenom);
	  	  		fflush(stdin);
				printf("\nentrer le nouveau numero:");
		        scanf("%d",&pro.numero);
				printf("\nentrer la nouvelle adresse:");
        	    scanf("%s",&pro.adresse_email);
	            	fflush(stdin);
				printf("\nentrer la nouvelle ville:");
				scanf("%s",pro.ville);
				fflush(stdin);
				}
				 fflush(stdin);
				fprintf(fich,"%d  %s  %s  %d  %s  %s\n",pro.id,pro.nom,pro.prenom,pro.numero,pro.adresse_email,pro.ville);
	  	  		
		   	}while(!feof(F));
	  	  		fclose(fich);
	  	  		fclose(F);
	  	  		remove("profil.txt");
	  	  		rename("temp.txt","profil.txt");
	  	  		printf("la modification est reussie");
			}else 
			{
				printf("\n la modification a ete annuler");
			}
	  }else{
	  	printf("\n ce contact n'existe pas");
	  	
	  }
	
}

void affichage_contact()
{
	FILE*F;
	F=fopen("profil.txt","r");

	printf("la liste des contacts est:\n\n");
	printf("identifiant\t  nom\t  prenom\t  numero\t  adresse_email\t\t\t  ville\n\n");
	
	do
	{	
		if(F==NULL){
		printf("aucune information disponible\n\n");
		break;
	}   
		fscanf(F,"%d  %s  %s  %d  %s  %s\n",&pro.id,&pro.nom,&pro.prenom,&pro.numero,&pro.adresse_email,&pro.ville);
		printf("%d\t\t",pro.id);
		printf("%s\t",pro.nom);
		printf("%s\t\t",pro.prenom);
		printf("%d\t\t",pro.numero);
		printf("%s\t\t\t",pro.adresse_email);
		printf("%s\n",pro.ville);
	}while(!feof(F));
	fclose(F);
	
}
      /*le menu du du principe*/
      
int main()
{
	int choix;
	char rep;
	do
	{
		printf("\n\n");
		printf("**************MENU************\n");
		printf("\n");
		printf("\t 1-ajouter un contact\n");
		printf("\t 2-rechercher un contact\n");
		printf("\t 3-supprimer un contact\n");
		printf("\t 4-modifier un contact\n");
		printf("\t 5-afficher tous les contacts\n");
		printf("\t 6-quitter \n\n");
	
	 do{
		printf("\n entrer votre choix:");
		scanf("%d",&choix);
	  }while(choix<1||choix>6);
	  
	 
	  switch(choix)
	  {
	  	case 1:ajouter_un_contact();
	  	break;
	  	case 2:recherche_contact();
	  	break;
	  	case 3:supprimer_contact();
	  	break;
	  	case 4:modifier_contact();
	  	break;
	  	case 5:affichage_contact();
	  	break;
	  	case 6:break;
	  }
	  
	         printf("\nvoulez vous rentrer au menu principal o/n :");
	         scanf("%s",&rep);
	  
	} 
	while(rep=='o'||rep=='O');
	
}




























