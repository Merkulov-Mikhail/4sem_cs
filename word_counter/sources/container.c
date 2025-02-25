#include "container.h"


struct container {
    Pair** ptr;
    int size;
    int capacity;
};


struct pair {
    const char* string;
    int cnt;
};


void Pair_dtor(Pair* pair) {
    free(pair->string);
    free(pair);
}

Pair* Pair_ctor(const char* str) {
    Pair* tmp = (Pair*) malloc(sizeof(Pair));
    tmp->string = (char*) malloc(strlen(str) + 1);
    tmp->cnt = 1;
    strcpy(tmp->string, str);
    return tmp;
}

void Pair_inc(Pair* pair) {
    if (pair)
        pair->cnt++;
}

const char* Pair_get_str(const Pair* pair) {
    if (pair)
        return pair->string;
    return NULL;
}

int Pair_get_cnt(const Pair* pair) {
    if (pair)
        return pair->cnt;
    return -1;
}


int Pair_compare(const Pair* p1, const Pair* p2) {
    return p1->cnt - p2->cnt;
}


Container* Container_ctor() {
    Container* tmp = (Container*) malloc(sizeof(Container));

    tmp->size = 0;
    tmp->capacity = 10;
    tmp->ptr = (Pair**) malloc(sizeof(Pair*) * tmp->capacity);

    return tmp;
}


void Container_dtor(Container* cont) {
    for (int i = 0; i < cont->size; i++) {
        Pair_dtor(cont->ptr[i]);
    }
    free(cont->ptr);
    free(cont);
}

Pair* Container_find(const Container* cont, const char* str) {
    for (int i = 0; i < cont->size; i++) 
        if (strcmp(cont->ptr[i]->string, str) == 0) 
            return cont->ptr[i];
    return NULL;
}


// I understand, that this is unsafe, but pretty sure, that it's not rellevant for the task
void Container_realloc(Container* cont) {
    cont->capacity *= 2;
    cont->ptr = (Pair**) realloc(cont->ptr, cont->capacity * sizeof(Pair*));
}

void Container_add(Container* cont, const char* str) {
    Pair* pair = Container_find(cont, str);
    if (pair != NULL) {
        Pair_inc(pair);
        return;
    }

    if (cont->size == cont->capacity)
        Container_realloc(cont);
    cont->ptr[cont->size] = Pair_ctor(str);
    cont->size++;
}


Pair** Container_get_pairs(Container* cont) {
    return cont->ptr;
}


int Container_get_size(Container* cont) {
    return cont->size;
}