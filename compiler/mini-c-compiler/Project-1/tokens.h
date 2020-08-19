/* 
* Compiler Design Project 1 : Lexical Analyser
*
* File        : tokens.h
* Description : This file defines tokens and the values associated to them.
*                  
* Authors     : Karthik M - 15CO22, Kaushik S Kalmady - 15CO222
* Date        : 17-1-2018
*/

enum keywords {
  INT = 100,
  LONG,
  LONG_LONG,
  SHORT,
  SIGNED,
  UNSIGNED,
  FOR,
  BREAK,
  CONTINUE,
  RETURN,
  CHAR,
  IF,
  ELSE
};

enum operators {
  DECR = 200,
  INCR,
  ACCESS,
  AND,
  OR,
  LESS_EQ,
  GREATER_EQ,
  EQ,
  NOT_EQ,
  ASSIGN,
  MINUS,
  PLUS,
  STAR,
  MOD,
  LESS,
  GREATER
};

enum special_symbols {
  DELIMITER = 300,
  LEFT_CURLY,
  RIGHT_CURLY,
  COMMA,
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  FW_SLASH
};

enum constants {
  HEX_CONSTANT = 400,
  DEC_CONSTANT,
  HEADER_FILE,
  STRING
};

enum IDENTIFIER {
  IDENTIFIER = 500
};
