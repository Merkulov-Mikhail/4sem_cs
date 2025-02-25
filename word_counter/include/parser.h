#pragma once
#include <stdio.h> // for FILE descriptor
#include <string.h>
#include <stdlib.h>

struct parser;

typedef struct parser Parser;


Parser* Parser_ctor(const char*);
void Parser_dtor(Parser*);
char* Parser_next(Parser* pars);