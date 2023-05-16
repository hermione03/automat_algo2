#include "occurences.h"

int min_len(char *motif)
{
    int len = strlen(motif);
    if (strchr(motif, '?'))
        len -= 2;
    if (strchr(motif, '*'))
        len -= 2;
    if (strchr(motif, '+'))
        len -= 1;
    return len;
}

Occurrence *occ_finder(char *t, char *pattern, int *i_occ)
{
    int i = 0;
    Occurrence *occurrences = (Occurrence *)calloc(1, sizeof(Occurrence));
    *i_occ = 0;

    while (t[i] != '\0')
    {
        if (t[i] == pattern[0])
        {
            int j = 0;
            int acc = 0;
            int a = 1;
            int y;
            char *liste = calloc(strlen(t) + 1, sizeof(char));

            while (pattern[j] != '\0')
            {

                if (t[i] == pattern[j] && pattern[j] != '*' && pattern[j] != '+' && pattern[j] != '?')
                {
                    if (pattern[j + 1] == '*' || pattern[j + 1] == '+')
                    {
                        while (t[i] == pattern[j])
                        {
                            liste[acc] = pattern[j];
                            acc++;
                            i++;
                        }
                    }
                    // else if (pattern[j + 1] == '?')
                    // {
                    //     liste[acc] = pattern[j];
                    //     acc++;
                    //     i++;
                    // }
                    else
                    {
                        liste[acc] = pattern[j];
                        acc++;
                        i++;
                    }
                }
                else
                {
                    if (pattern[j + 1] == '+')
                    {
                        a = 0;
                        break;
                    }
                    else if (strchr(alphabet, pattern[j]) && strchr(alphabet, t[i]) && pattern[j + 1] != '*' && pattern[j + 1] != '?')
                    {
                        a = 0;
                        break;
                    }
                }
                j++;
            }

            y = i - strlen(liste);
            if ((int)(strlen(liste)) >= min_len(pattern) && a == 1)
            {
                occurrences = realloc(occurrences, (*i_occ + 1) * sizeof(Occurrence));
                occurrences[*i_occ].liste = liste;
                occurrences[*i_occ].i_debut = y;
                occurrences[*i_occ].i_fin = i - 1;
                (*i_occ)++;
            }
            else if (a == 1)
            {
                free(liste);
            }
        }
        else
        {
            i++;
        }
    }
    return occurrences;
}

void affiche_occ(Occurrence *occ, int i_occ)
{
    for (int i = 0; i < i_occ; i++)
    {
        printf(" %s,%d,%d\n", occ[i].liste, occ[i].i_debut, occ[i].i_fin);
    }
    printf("nb occ : %d\n", i_occ);
}

void free_occ(Occurrence *occ, int i_occ)
{
    for (int i = 0; i < i_occ; i++)
    {
        free(occ[i].liste);
    }
    free(occ);
}

// ##################### Etape 4 #####################

int get(char *occ, hashMap *map, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(map[i].occ, occ) == 0)
            return i;
    }
    return -1;
}

void affiche_union(hashMap *occ, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %s,%d\n", occ[i].occ, occ[i].nb_occ);
    }
}

hashMap *Union_ocm(Occurrence *occ1, int i_occ1, Occurrence *occ2, int i_occ2, int *size)
{
    hashMap *map = (hashMap *)calloc(i_occ1 + i_occ2, sizeof(hashMap));
    *size = 0;
    for (int i = 0; i < i_occ1; i++)
    {
        int index = get(occ1[i].liste, map, *size);
        if (index != -1)
        {
            map[index].nb_occ++;
        }
        else
        {
            map[*size].occ = occ1[i].liste;
            map[*size].nb_occ = 1;
            (*size)++;
        }
    }
    for (int i = 0; i < i_occ2; i++)
    {
        int index = get(occ2[i].liste, map, *size);
        if (index != -1)
        {
            map[index].nb_occ++;
        }
        else
        {
            map[*size].occ = occ2[i].liste;
            map[*size].nb_occ = 1;
            (*size)++;
        }
    }
    return map;
}

void printArray(hashMap *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s: %d\n", arr[i].occ, arr[i].nb_occ);
    }
    printf("\n");
}