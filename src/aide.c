#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "aide.h"




////////////////////////////////////// rechercher aide maitresse ///////////////////////////////////////////////
aide rechercher_aide(char chemin[], aide a)
{
aide me,dd;
FILE *f;
strcpy(dd.Nom,"-1");
strcpy(dd.Prenom,"-1");
f=fopen(chemin,"r+");
  
while(fscanf(f, "%s %s %s %s %s %s %s \n",me.Nom,me.Prenom,me.CIN,me.email,me.tel,me.adresse,me.classe)!=EOF )
{
if(((strcmp(a.Nom,me.Nom)==0)) && ((strcmp(a.Prenom,me.Prenom)==0)))	
{
dd=me ;
}
}
fclose(f);
return dd ;
}


void ajouter_aide(char chemin[], aide a)
{
    FILE *f;

    f=fopen(chemin,"a");

fprintf(f, "%s %s %s %s %s %s %s\n",a.Nom,a.Prenom,a.CIN,a.email,a.tel,a.adresse,a.classe);
fclose(f);
}

////////////////////////////          fonction supprimer //////////////////////////////////////////////////////////////////////
int supprimer_aide(char chemin[], char nom[], char prenom[])
{
 int y=0;
 int i=0,n=0;
 aide N[80];
    FILE *f;

    f=fopen(chemin,"r");
    if(f==NULL)
    {
    printf("erreur");
    return;
    }
	else
	{
	//remplir le tableau Age par la structure N
	while(fscanf(f,"%s %s %s %s %s %s %s \n", N[n].Nom, N[n].Prenom, N[n].CIN, N[n].email,N[n].tel,N[n].adresse, N[n].classe) !=EOF)
	{
		if((strcmp(nom,N[n].Nom) ==0) && (strcmp(prenom,N[n].Prenom) ==0))
			{i=n;
			y=1;}
	n++;
	}
	fclose(f);

	//recherche de l'enfant dans le tableau []

if(y==1){
	int j;
	for(j=i;j<n;j++) //suppression
	{
	N[j]=N[j+1];
	}
	n--;
	f=fopen(chemin,"w"); //on reouvre lefichier en mode w pour ecraser les anciens données 888

	if (f==NULL)
	printf("erreur");
	else
	{
	for(i=0;i<n;i++)
	fprintf(f, "%s %s %s %s %s %s %s\n", N[i].Nom, N[i].Prenom, N[i].CIN, N[i].email,N[i].tel,N[i].adresse,N[i].classe);//on ajoute les nouveaux données
	}fclose(f);
}
}

return y;
}

