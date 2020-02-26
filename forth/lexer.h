/*
 *  Lexer.
 */
#ifndef _LEXER_H
#define _LEXER_H
 
#include "memory.h"
#include "screen.h"
#include "printf.h"
 
#define LINE_BUFFER_SIZE 256
#define TOKENS_BUFFER_SIZE 128

 
enum LEXER_READ {
	LEXER_READ_START,
	LEXER_READ_INT,
	LEXER_READ_WORD,
	LEXER_READ_PLUS,
	LEXER_READ_MINUS,
	LEXER_READ_MUL,
	LEXER_READ_DIV,
	LEXER_READ_MOD,
	LEXER_READ_DOT,
	LEXER_READ_COLON,
	LEXER_READ_SEMICOLON,
	LEXER_READ_EQ,
	LEXER_READ_LESS,
	LEXER_READ_MORE,
};
 
enum LEXER_STATE {
	LEXER_STATE_COMPILE,
	LEXER_STATE_EXECUTE,
};
 
/* Lexer */
typedef struct lexer{
	enum LEXER_STATE state;
	enum LEXER_READ read;
} Lexer;

enum TOKEN_TYPE {
	TOKEN_INT,
	TOKEN_WORD,
	TOKEN_DUP,
	TOKEN_DROP,
	TOKEN_SWAP,
	TOKEN_CL,
	TOKEN_ABS,
	TOKEN_IF,
	TOKEN_ELSE,
	TOKEN_THEN,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MUL,
	TOKEN_DIV,
	TOKEN_MOD,
	TOKEN_DOT,
	TOKEN_EQ,
	TOKEN_MORE,
	TOKEN_LESS,
	TOKEN_COLON,
	TOKEN_SEMICOLON,
};

 /* Token */
typedef struct token{
	 int int_value;
	 char* value;
	 unsigned int value_len;
	 enum TOKEN_TYPE type;
} Token;

/* Lexer methods */
Lexer* new_lexer();
Token* next_token(Lexer* l, char* buff, int* buff_shift);
void skip_spaces(char *buff, int* buff_shift);
void skip(char *buff, int* buff_shift);

/* Token methods */
void print_token(Token* t);
void print_token_value(Token* t);
void delete_token(Token* t);
Token* new_token();
Token* copy_token(Token* t);

/* Extra */
char is_digit(char c);
char is_lower(char c);
char is_alpha(char c);
char is_alphanum(char c);
char to_upper(char c);
char str_cmp(const char *s1, const char *s2);
char is_whitespace(char c);
int atoi(const char* str);
void* memcpy(void* destptr, const void* srcptr, size_t num);
int abs(int x);
#endif
