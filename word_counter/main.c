#include <stdio.h>
#include "container.h"
#include "parser.h"





int main() {
    Container* cont = Container_ctor();
    Parser* pars = Parser_ctor("file.txt");

    char* str;
    while((str = Parser_next(pars)) != NULL) {
        Container_add(cont, str);
        free(str);
    }

    Pair** pairs = Container_get_pairs(cont);
    int size = Container_get_size(cont);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (Pair_compare(pairs[i], pairs[j]) < 0) {
                Pair* tmp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = tmp;
            }
        }
    }
    for (int i = 0; i < size; i++)
        printf("<%s %d>\n", Pair_get_str(pairs[i]), Pair_get_cnt(pairs[i]));

    Parser_dtor(pars);
    Container_dtor(cont);
}