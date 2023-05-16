#ifndef OCCURENCES_H
#define OCCURENCES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global_vars.h"



typedef struct
{
    char *liste;
    int i_debut;
    int i_fin;
} Occurrence;

typedef struct
{
    char *occ;
    int nb_occ;
} hashMap;

int min_len(char *motif);
Occurrence *occ_finder(char *t, char *pattern, int *i_occ);
void affiche_occ(Occurrence *occ, int i_occ);
void free_occ(Occurrence *occ, int i_occ);
int get(char *occ, hashMap *map, int size);
void affiche_union(hashMap *occ, int size);
hashMap *Union_ocm(Occurrence *occ1, int i_occ1, Occurrence *occ2, int i_occ2, int *size);
void printArray(hashMap *arr, int size);

#endif