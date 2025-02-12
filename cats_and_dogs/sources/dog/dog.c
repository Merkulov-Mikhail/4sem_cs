#include "dog.h"


void dog_voice(Animal* tmp) {
    printf("Bark, im %s\n", tmp->m->get_name(tmp));
}

struct animal_m dog_methods = {
    animal_get_name,
    dog_voice
};

Dog* dog_create(char* name) {
    Dog* tmp = (Dog*) malloc(sizeof(Dog));
    tmp->a.name = name;
    tmp->a.m = &dog_methods;
    return tmp;
}
