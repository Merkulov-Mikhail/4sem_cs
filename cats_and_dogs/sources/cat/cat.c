#include "cat.h"

void cat_voice(Animal* tmp) {
    printf("Meow, im %s\n", tmp->m->get_name(tmp));
}

struct animal_m cat_methods = {
    animal_get_name,
    cat_voice
};


Cat* cat_create(char* name) {
    Cat* tmp = (Cat*) malloc(sizeof(Cat));
    tmp->a.name = name;
    tmp->a.m = &cat_methods;
    return tmp;
}

