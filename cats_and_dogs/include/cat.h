#pragma once
#include "animal.h"

typedef struct cat Cat;


struct cat {
    Animal a;
};

Cat* cat_create(char* name);
void cat_voice(Animal* tmp);