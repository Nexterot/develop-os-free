/*
 *  Forth interpreter.
 */

#include "include/multiboot.h"
#include "sys.h"
#include "memory.h"
#include "printf.h"
#include "screen.h"
#include "cursor.h"
#include "time.h"
#include "keyboard.h"

#include "forth/stack.h"
#include "forth/lexer.h"
#include "forth/parser.h"

 
void main(multiboot_info_t* mbd, unsigned int magic) {   
    mem_init(mbd);
    key_init();
    rtc_seed();
    
    Lexer lex;
    Parser prs;
    Stack st;
    
    init_stack(&st, DATA_STACK_SIZE);
    
    char buff[LINE_BUFFER_SIZE];
    Token** tokens = (Token**) malloc(TOKENS_BUFFER_SIZE * sizeof(Token*));
	for (;;) {
		int i = 0, j = 0;
		puts("> ");
		gets(buff);
		putchar('\n');
		Token* t;
		skip_spaces(buff, &i);
		while (t = next_token(&lex, buff, &i)) {
			skip_spaces(buff, &i);
			tokens[j++] = t;
		}
		parse(&prs, &st, tokens, j);
	}
}
