/**
 * Project: FIT VUT Brno IFJ Project
 * Description: Implementation of Compiler for IFJ18 language.
 * Author: Vojtech Pilar (xpilar06)
 * Contact: xpilar06@stud.fit.vutbr.cz
 * Date of creation: 2018-11-20
 * Version: 1.00
 * */

#ifndef _ERROR_H
#define _ERROR_H


// Error codes
#define LEX_ERR                 1 // Lexical error
#define SYNTAX_ERR              2 // Syntax error
#define SEM_ERR_UNDEF_VAR       3 // Semantic error - undefined variable
#define SEM_ERR_TYPE_COMP       4 // Semantic error - uncompatible types
#define SEM_ERR_PARAM_COUNT     5 // Semantic error - not matching param count
#define SEM_ERR_OTHER           6 // Semantic error - other
#define RUN_ERR_DIV_NULL        9 // Runtime error - division by null
#define ERROR_INTERNAL         99 // Internal error, eg. malloc error etc.


#endif //_ERROR_H
