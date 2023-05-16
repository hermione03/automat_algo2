#include "tri.h"
#include "gen_tab.h"
char *alphabet = "MSDE";
char *motif1 = "MS+D*E";
char *motif2 = "MS?DE*";

int main(void)
{
    char *tab = gen_tab(200);
    int i_occ_1 = 0;
    int i_occ_2 = 0;
    int i_union = 0;
    Occurrence *occu_mot1 = occ_finder(tab, motif1, &i_occ_1);
    Occurrence *occu_mot2 = occ_finder(tab, motif2, &i_occ_2);
    hashMap *occu = Union_ocm(occu_mot1, i_occ_1, occu_mot2, i_occ_2, &i_union);
    printf("Tableau des lettres :\n' %s '\n", tab);
    printf("\n############ Motif 1: ############ \n");
    affiche_occ(occu_mot1, i_occ_1);
    printf("\n############ Motif 2: ############ \n");
    affiche_occ(occu_mot2, i_occ_2);
    printf("\n############ Union des Motifs: ############ \n");
    affiche_union(occu, i_union);
    int n = i_union;
    quickSort(occu, 0, n - 1);
    printf("\n############ Union des Motifs Triés: ############ \n");
    printArray(occu, n);
    free_occ(occu_mot1, i_occ_1);
    free_occ(occu_mot2, i_occ_2);
    free(occu);
    free(tab);
    return 0;
}