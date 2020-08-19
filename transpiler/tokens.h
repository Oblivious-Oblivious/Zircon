#ifndef __TOKENS_H_
#define __TOKENS_H_

/* cObjects token list */
enum c84_keywords {
    OBJECT = 100,
    MODEL,
    PROTOCOL,

    INIT,
    DEFER,
    FIELDS,

    IMPLEMENTS,
    SELF,
    SUPER,
    MESSAGE,
    SUPERMESSAGE
};
enum c89_keywords {
    AUTO = 200,
    BREAK,
    CASE,
    CHAR,
    CONST,
    CONTINUE,
    DEFAULT,
    DO,
    DOUBLE,
    ELSE,
    ENUM,
    EXTERN,
    FLOAT,
    FOR,
    GOTO,
    IF,
    INT,
    LONG,
    REGISTER,
    RETURN,
    SHORT,
    SIGNED,
    SIZEOF,
    STATIC,
    STRUCT,
    SWITCH,
    TYPEDEF,
    UNION,
    UNSIGNED,
    VOID,
    VOLATILE,
    WHILE
};
enum c99_keywords {
    BOOL = 250,
    COMPLEX,
    IMAGINARY,
    INLINE,
    RESTRICT
};
enum c11_keywords {
    ALIGNAS = 270,
    ALIGNOF,
    ATOMIC,
    GENERIC,
    NORETURN,
    STATIC_ASSERT,
    THREAD_LOCAL
};

enum c84_symbols {
    SEND = 300,
    OBJECT_NOTATION
};
enum symbols {
    LEFT_PAREN = 350,
    RIGHT_PAREN,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    LEFT_CURLY,
    RIGHT_CURLY,
    COLON,
    SEMICOLON,
    COMMA,
    SLASH
};

enum operators {
    /* Arithmetic */
    ADD = 400,
    SUB,
    MUL,
    DIV,
    MOD,
    INCR,
    DECR,

    /* Relational */
    EQ = 410,
    NOT_EQ,
    GREATER,
    LESS,
    GREATER_EQ,
    LESS_EQ,

    /* Logical */
    AND = 420,
    OR,
    NOT,

    /* Bitwise */
    BAND = 430,
    BOR,
    BXOR,
    BNOT,
    BSHIFT_LEFT,
    BSHIFT_RIGHT,

    /* Assignment */
    ASSIGN = 440,
    ADD_EQ,
    SUB_EQ,
    MUL_EQ,
    DIV_EQ,
    MOD_EQ,
    SHIFT_LEFT_EQ,
    SHIFT_RIGHT_EQ,
    AND_EQ,
    XOR_EQ,
    OR_EQ,

    /* Conditional */
    TERNARY = 450,

    /* Pointer */
    /*
    PTR_SIZEOF = 460,
    ADDRESS,
    POINTER,
    */

    MEMBER,
    ACCESS,

    /* VA_ARGS */
    VARIABLE_ARGUMENTS
};

enum identifier {
    IDENTIFIER = 500,
    STRING,
    FUNC_NAME,
    HEADER
};

enum constants {
    TYPEDEF_NAME = 600,
    CONSTANT,
    ENUMERATION_CONSTANT,
    INT_CONSTANT,
    FLOAT_CONSTANT,
};

#endif
