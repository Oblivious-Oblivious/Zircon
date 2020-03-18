%{
    #include <math.h>
    #include "y.tab.h"
%}

%%

[0-9]+|[0-9]*\.[0-9]+ {
    yylval.p = atof(yytext);
    return num; /* Return nonterminal */
}

exit    exit(0);
sin     return SIN;
cos     return COS;
square  return SQUARE;
cube    return CUBE;
ln      return LN;
tan     return TAN;
log     return LOG;
sqrt    return SQRT;
[ \t]   ;
\n      return 0;
.       return yytext[0];

%%

int yywrap(void) {
    return 1;
}
