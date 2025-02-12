#pragma once
#include <stdlib.h>
#include <stdio.h>


typedef struct animal Animal;

struct animal {
    struct animal_m* m;
    char* name;
};


struct animal_m {
    char* (*get_name) (Animal*);
    void  (*voice)    (Animal*);
};

char* animal_get_name(Animal*);