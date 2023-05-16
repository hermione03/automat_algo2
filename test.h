#ifndef TEST_H
#define TEST_H

#include "tri.h"

int is_the_same(Occurrence *a, int size_a, Occurrence *b, int size_b);
int is_the_same2(hashMap *a, int size_a, hashMap *b, int size_b);
int estDecroissant(hashMap *tab, int size);
void test();

#endif