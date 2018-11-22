/**
 * Project: FIT VUT Brno IFJ Project
 * Description: Implementation of Compiler for IFJ18 language.
 * Author: Vojtech Pilar (xpilar06)
 * Contact: xpilar06@stud.fit.vutbr.cz
 * Date of creation: 2018-11-20
 * Version: 1.00
 * */


#include "dynStr.h"


#define DYN_STR_INC_LEN 8 // Initialized length of string.


void dynStrClear(DynStr *s){
    s->len = 0;
    s->str[s->len] = '\0';
}

bool dynStrInit(DynStr *s){
    s->str = (char *) malloc(DYN_STR_INC_LEN);

    if(s->str == NULL){
        return false;
    }

    dynStrClear(s);
    s->alloc_size = DYN_STR_INC_LEN;

    return true;
}

void dynStrFree(DynStr *s){
    free(s->str);
}

bool dynStrAddChar(DynStr *s, char c){
    if (s->len + 1 >= s->memAlloc){
        unsigned int newSize = s->len + DYN_STR_INC_LEN;
        s->str = (char *) realloc(s->str, newSize);
        if(s->str == NULL){
            return false;
        }

        s->memAlloc = newSize;
    }

    s->str[s->len++] = c;
    s->str[s->len] = '\0';

    return true;
}

bool dynStrAddConstStr(DynStr *s, const char *constStr){
    unsigned int constStrLen = (unsigned int) strlen(constStr);

    if (s->len + constStrLen + 1 >= s->memAlloc){
        unsigned int newSize = s->len + constStrLen + 1;
        s->str = (char *) realloc(s->str, newSize);
        if(s->str == NULL){
            return false;
        }

        s->memAlloc = newSize;
    }

    s->len += constStrLen;
    strcat(s->str, constStr);
    s->str[s->len] = '\0';

    return true;
}

int dynStrCmpConstStr(DynStr *s, const char *constStr){
    return strcmp(s->str, constStr);
}

bool dynStringCopy(DynStr *src, DynStr *dest){
    unsigned int newSize = src->len;
    if (newSize >= dest->memAlloc)
    {
        dest->str = (char *) realloc(dest->str, newSize + 1);
        if(dest->str == NULL){
            return false;
        }
        dest->memAlloc = newSize + 1;
    }

    strcpy(dest->str, src->str);
    dest->len = newSize;

    return true;
}