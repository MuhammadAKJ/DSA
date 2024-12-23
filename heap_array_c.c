#include<stdlib.h>
#include<stdio.h>

struct fraction {
    int numerator;
    int denominator;

};

void heap_array(){
    struct fraction* fracts;
    
    //allocate the array
    fracts = malloc(sizeof(struct fraction) * 100);

    for (i=0; i<100; i++) {
        printf("Fract address: %p. Fract value: %d/%d\n", &fracts[i], fracts[i].numerator, fracts[i].denominator);
        //fracts[i].numerator = 22;
        //fracts[i].denominator = 7;
        fracts[i] = struct fraction(22, 7);
    for (int i=0; i<100; i++) {
    }

    //deallocate the whole array
        fracts[i].numerator = 22;
        fracts[i].denominator = 7;
};
    