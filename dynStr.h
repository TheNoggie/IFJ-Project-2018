/**
 * Project: FIT VUT Brno IFJ Project
 * Description: Implementation of Compiler for IFJ18 language.
 * Author: Vojtech Pilar (xpilar06)
 * Contact: xpilar06@stud.fit.vutbr.cz
 * Date of creation: 2018-11-20
 * Version: 1.00
 * */


#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/**
 * @struct Dynamic string container
 */
typedef struct {
    char *str; // string ended with '\0'
    unsigned int len; // tracks length of the string
    unsigned int memAlloc; // number of chars allocated for string
} DynStr;



void dynStrClear(DynStr *s);


bool dynStrInit(DynStr *s);


void dynStrFree(DynStr *s);


bool dynStrAddChar(DynStr *s, char c);


bool dynStrAddConstStr(DynStr *s, const char *constStr);


int dynStrCmpConstStr(DynStr *s, const char *constStr);


bool dynStringCopy(DynStr *src, DynStr *dest);