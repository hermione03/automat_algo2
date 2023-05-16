#include "test.h"

// ##################### Etape 6 #####################

int is_the_same(Occurrence *a, int size_a, Occurrence *b, int size_b)
{
    if (size_a != size_b)
    {
        // return 0;
        // printf("Test non concluant ..."); // les tableaux ont des tailles différentes, ils ne sont donc pas égaux
        return 0;
    }

    for (int i = 0; i < size_a; i++)
    {
        if (strcmp(a[i].liste, b[i].liste) != 0 || a[i].i_debut != b[i].i_debut || a[i].i_fin != b[i].i_fin)
        {

            // return 0; // une différence a été trouvée, les tableaux ne sont pas égaux
            return 0;
        }
    }
    return 1;
}
int is_the_same2(hashMap *a, int size_a, hashMap *b, int size_b)
{
    if (size_a != size_b)
    {
        // return 0;
        // printf("Test non concluant ..."); // les tableaux ont des tailles différentes, ils ne sont donc pas égaux
        return 0;
    }

    for (int i = 0; i < size_a; i++)
    {
        if (strcmp(a[i].occ, b[i].occ) != 0 || a[i].nb_occ != b[i].nb_occ)
        {

            // return 0; // une différence a été trouvée, les tableaux ne sont pas égaux
            return 0;
        }
    }
    return 1;
}

int estDecroissant(hashMap *tab, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (tab[i].nb_occ > tab[i - 1].nb_occ)
        {
            return 0;
        }
    }
    return 1;
}

void test()
{
    char *tab_test1 = "DDMSDESSDMSSSSDEMDDSMSESSMSDDE";
    Occurrence test1[] = {
        {"MSDE", 2, 5},
        {"MSSSSDE", 9, 15},
        {"MSE", 20, 22},
        {"MSDDE", 25, 29}};
    int size_test = sizeof(test1) / sizeof(Occurrence);
    int i1 = 0;
    Occurrence *occ1 = occ_finder(tab_test1, motif1, &i1);
    if (is_the_same(test1, size_test, occ1, i1))
    {
        printf("Test motif1 :Success !!");
    }
    else
    {
        printf("Test motif1 : non concluant ...");
    }
    printf("\n");
    char *tab_test2 = "DMEDSSSMDESEMDDDMMSEMDEMSSSDE";
    Occurrence test2[] = {
        {"MDE", 7, 9},
        {"MD", 12, 13},
        {"MDE", 20, 22}};
    size_test = sizeof(test2) / sizeof(Occurrence);
    int i2 = 0;
    Occurrence *occ2 = occ_finder(tab_test2, motif2, &i2);
    if (is_the_same(test1, size_test, occ1, i2))
    {
        printf("Test motif2 :Success !!");
    }
    else
    {
        printf("Test motif2: non concluant ...");
    }
    printf("\n");
    // ##################### Etape 7 #####################
    hashMap union_test[] = {
        {"MSDE", 1},
        {"MSSSSDE", 1},
        {"MSE", 1},
        {"MSDDE", 1},
        {"MDE", 2},
        {"MD", 1},
    };
    int size_u = sizeof(union_test) / sizeof(hashMap);
    int size = 0;
    hashMap *union_t = Union_ocm(occ1, i1, occ2, i2, &size);
    //printArray(union_t, size);
    if (is_the_same2(union_test, size_u, union_t, size))
    {
        printf("Test Union : Success !!");
    }
    else
    {
        printf("Test Union: non concluant ...");
    }
    // ##################### Etape 8 #####################
    printf("\n");
    quickSort(union_t, 0, size - 1);
    // printArray(union_t, size);
    if (estDecroissant(union_t, size))
    {
        printf("Test Union Trié : Success !!");
    }
    else
    {
        printf("Test Union Trié:  non concluant ...");
    }
    printf("\n");
}