#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct pair;

typedef struct pair Pair;

void  Pair_inc (Pair* pair);
Pair* Pair_ctor(const char* str);
void  Pair_dtor(Pair* pair);
int   Pair_get_cnt(const Pair* pair);
const char* Pair_get_str(const Pair* pair);
int   Pair_compare(const Pair* p1, const Pair* p2);

struct container;       

typedef struct container Container;

Container* Container_ctor();
void Container_dtor(Container* cont);
Pair* Container_find(const Container* cont, const char* str);
void Container_add(Container* cont, const char* str);
Pair** Container_get_pairs(Container* cont);
int Container_get_size(Container* cont);