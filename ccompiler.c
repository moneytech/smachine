#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "cpu.h"

enum TOKEN_TYPE_E {
    TOKEN_KW_IF = 0,        /* "if"     */
    TOKEN_KW_ELSE,          /* "else"   */
    TOKEN_KW_WHILE,         /* "while"  */
    TOKEN_KW_FOR,           /* "for"    */
    TOKEN_KW_DO,            /* "do"     */
    TOKEN_KW_RETURN,        /* "return" */

    TOKEN_TP_VOID,          /* "void" */
    TOKEN_TP_INT,           /* "int"  */
    TOKEN_TP_CHAR,          /* "char" */
    TOKEN_TP_ENUM,          /* "enum" */

    TOKEN_OP_PLUS,          /* "+" */
    TOKEN_OP_SUB,           /* "-" */
    TOKEN_OP_MUL,           /* "*" */
    TOKEN_OP_DIV,           /* "/" */
    TOKEN_OP_EQ,            /* "=" */
    TOKEN_OP_EM,            /* "!" exclamation mark */
    TOKEN_OP_TILDE,         /* "~"  */
    TOKEN_OP_XOR,           /* "^"  */
    TOKEN_OP_PERCENT,       /* "%"  */
    TOKEN_OP_AND,           /* "&&" */
    TOKEN_OP_OR,            /* "||" */
    TOKEN_OP_PP,            /* "++" */
    TOKEN_OP_SS,            /* "--" */
    TOKEN_OP_EE,            /* "==" */
    TOKEN_OP_LT,            /* "<"  */
    TOKEN_OP_GT,            /* ">"  */
    TOKEN_OP_LE,            /* "<=" */
    TOKEN_OP_GE,            /* ">=" */

    TOKEN_SP_LCURBRACE,     /* "{"  */
    TOKEN_SP_RCURBRACE,     /* "}"  */
    TOKEN_SP_LSQRBRACKET,   /* "["  */
    TOKEN_SP_RSQRBRACKET,   /* "]"  */
    TOKEN_SP_LRNDBRACKET,   /* "("  */
    TOKEN_SP_RRNDBRACKET,   /* "("  */
    TOKEN_SP_SEMICOLON,     /* ";"  */
    TOKEN_SP_COMMA,         /* ","  */

    TOKEN_ID,               /* user-defined */

    TOKEN_MAX,
}; 

struct __token__ {
    int   type;
    char *t;
    int   value;
};

struct __token__ id_token_pool[1024];

struct __token__ c_token_pool[] = {
    {TOKEN_KW_IF,            "if",       0},
    {TOKEN_KW_ELSE,          "else",     0},
    {TOKEN_KW_WHILE,         "while",    0},
    {TOKEN_KW_FOR,           "for",      0},
    {TOKEN_KW_DO,            "do",       0},
    {TOKEN_KW_RETURN,        "return",   0},

    {TOKEN_TP_VOID,          "void",     0},
    {TOKEN_TP_INT,           "int",      0},
    {TOKEN_TP_CHAR,          "char",     0},
    {TOKEN_TP_ENUM,          "enum",     0},

    {TOKEN_OP_PLUS,          "+",        0},
    {TOKEN_OP_SUB,           "-",        0},
    {TOKEN_OP_MUL,           "*",        0},
    {TOKEN_OP_DIV,           "/",        0},
    {TOKEN_OP_EQ,            "=",        0},
    {TOKEN_OP_EM,            "!",        0},
    {TOKEN_OP_TILDE,         "~",        0},
    {TOKEN_OP_XOR,           "^",        0},
    {TOKEN_OP_PERCENT,       "%",        0},
    {TOKEN_OP_AND,           "&&",       0},
    {TOKEN_OP_OR,            "||",       0},
    {TOKEN_OP_PP,            "++",       0},
    {TOKEN_OP_SS,            "--",       0},
    {TOKEN_OP_EE,            "==",       0},
    {TOKEN_OP_LT,            "<",        0},
    {TOKEN_OP_GT,            ">",        0},
    {TOKEN_OP_LE,            "<=",       0},
    {TOKEN_OP_GE,            ">=",       0},

    {TOKEN_SP_LCURBRACE,     "{",        0},
    {TOKEN_SP_RCURBRACE,     "}",        0},
    {TOKEN_SP_LSQRBRACKET,   "[",        0},
    {TOKEN_SP_RSQRBRACKET,   "]",        0},
    {TOKEN_SP_LRNDBRACKET,   "(",        0},
    {TOKEN_SP_RRNDBRACKET,   "(",        0},
    {TOKEN_SP_SEMICOLON,     ";",        0},
    {TOKEN_SP_COMMA,         ",",        0},

    {TOKEN_ID,               "",         0},
}; 

int main(int argc, char **argv)
{
    int ifd, ofd;
    struct stat st;

    if (argc != 2) {
        printf("%s [foo.c] [bar.bin]\n", argv[0]);
        exit(-1);
    }

    if ((ifd = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        exit(-1);
    }

    if ((ofd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0664)) == -1) {
        perror("open");
        exit(-1);
    }   

    return 0;
}