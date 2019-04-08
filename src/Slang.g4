grammar Slang;



pou : 'PROGRAM' pouName=IDENTIFIER declarations 'END_PROGRAM';

declarations :
   'VAR'
      variableDeclaration*
   'END_VAR';

variableDeclaration :
   IDENTIFIER ':' typeRef (variableDefinition)?';';

variableDefinition :
   ':=' variableDefinition;

typeRef :
   IDENTIFIER;

WS
   : [ \t\r\n] -> skip;

CHAR : ('a'..'z' | 'A'..'Z');

DIGIT : ('0'..'9');

IDENTIFIER_NONDIGIT : [a-zA-Z_];

IDENTIFIER : IDENTIFIER_NONDIGIT (IDENTIFIER_NONDIGIT | DIGIT | '_')*;