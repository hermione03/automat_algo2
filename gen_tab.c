#include "gen_tab.h"

char *gen_tab(int taille)
{
    srand(time(0));
    char *result = (char *)calloc(taille + 1, sizeof(char));
    for (int i = 0; i < taille; i++)
    {
        int random_index = rand() % 4;
        result[i] = alphabet[random_index];
    }
    return result;
}