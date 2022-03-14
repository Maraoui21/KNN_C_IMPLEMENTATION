#include <stdio.h>
#include "Knn.h"
#include<string.h>
#include<stdlib.h>
int main()
{
    int Type,i,k=3;
	cellule arr[17],*p;
    p = arr;
    int n = sizeof(arr)/sizeof(arr[0]);
    char buf[1024];
    int line_count=0;
    int case_count=0;
    FILE *F;

    F = fopen("Cellule_data.csv","r");

    i = 0;
    while (fgets(buf,1024,F))
    {   case_count = 0;
        line_count++;
         if(line_count==1){continue;}
        char* token = strtok(buf,",");
            while( token){
                if(case_count == 0)
                    arr[i].x = atof(token);
                if(case_count == 1)
                    arr[i].y = atof(token);
                if(case_count == 2)
                    arr[i].type = atoi(token);
	            token =  strtok(NULL, ",");
                case_count++;
            }
        i++;
    }


    int reponse,attent;
    
    // cellule pour tester
    cellule p1;
    do{
    system("cls");
    printf("============================= DONNER LES COORDONNEES DE VOTRE CELLULE =============================\n");
    printf("X:  ");scanf(" %lf",&p1.x);
    printf("Y:  ");scanf(" %lf",&p1.y);
    printf("=================================================================================================\n");
    printf("Tapez 1 pour saine \n");
    printf("Tapez 0 pour infectee \n");
    printf("=================================================================================================\n");
    printf("Votre attente ? : ");
    scanf("%d",&attent);
    printf("=================================================================================================\n");
    Type = pointClass(p,n,k,p1);

    if (Type == 0)
        printf("La cellule est saine \n");
    else if(Type == 1)
        printf("La cellule est  infectee \n");
    printf("=================================================================================================\n");
    printf("Tapez 1 si oui \n");
    printf("Tapez 0 si non \n");
    printf("Voulez-vous tester d'autre cellule ?  \n");scanf("%d",&reponse);
    }
    while(reponse == 1 );
    
	return 0;
}
