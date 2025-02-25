#include "parser.h"


struct parser {
    FILE* file;
};


Parser* Parser_ctor(const char* file_name) {
    Parser* tmp = (Parser*) malloc(sizeof(Parser));
    tmp->file = fopen(file_name, "r");
    return tmp;
}


void Parser_dtor(Parser* pars) {
    fclose(pars->file);
    free(pars);
}


char* Parser_next(Parser* pars) {
    int cap = 100;
    int size = 0;
    char* word = (char*) malloc(cap);
    int ch;
    while ((ch = fgetc(pars->file)) != EOF && ch != ' ' && ch != '\n' && ch != '\t') {
        word[size++] = ch;
        if (size == cap) {
            cap *= 2;
            word = (char*) realloc(word, cap);
        }
    }
    if (size == 0) {
        free(word);
        return NULL;
    }
    word[size] = 0;
    return word;
}
