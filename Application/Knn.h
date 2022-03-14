#ifndef Knn
#define Knn
#include<stdio.h>
#include <stdlib.h>
typedef struct cellule {
      int type;
      double x,y;
      double distance;
} cellule;
void triDitance(cellule *pointer, int n);
int pointClass(cellule *pointer,int n,int k,cellule p);


#endif