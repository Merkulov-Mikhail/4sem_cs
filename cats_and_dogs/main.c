#include "cat.h"
#include "dog.h"


int main() {
    Animal* a = (Animal*) cat_create("Hello");
    Animal* b = (Animal*) dog_create("Dog");
    a->m->voice(a);
    b->m->voice((Animal*) b);
    // a->voice((Animal*) b);
}