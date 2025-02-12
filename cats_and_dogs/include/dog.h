#pragma once
#include "animal.h"

typedef struct dog Dog;


struct dog {
    Animal a;
};

Dog* dog_create(char* name);
