#include "Knn.h"
#include<math.h>
#include<stdio.h>
#include <stdlib.h>
int pointClass(cellule *pointer,int n,int k,cellule p){
    int i,j,V_count=0,R_count=0;
         for (int i = 0; i < n; i++)
            {
            (pointer+i)->distance = sqrt(((pointer+i)->x - p.x) * ((pointer+i)->x - p.x) + ((pointer+i)->y - p.y) * ((pointer+i)->y - p.y));
            }
        triDitance(pointer,n);



    
    for(j=0;j<k;j++){
        if((pointer+j)->type == 0){
            V_count++;
        }
        else
            R_count++;
    }

    return (V_count>R_count?0:1);

}
void triDitance(cellule *pointer, int n)
{
    cellule temp;
	int i, j, min_idx;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if ((pointer+j)->distance < (pointer+min_idx)->distance)
        {
			min_idx = j;
        }
		
        temp = *(pointer+min_idx);
	    *(pointer+min_idx) = *(pointer+i);
	    *(pointer+i) = temp;

	}

}