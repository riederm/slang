grammar Slang;



pou : 'PROGRAM' pouName=IDENTIFIER declarationContainers+=declarations* 'END_PROGRAM';

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

IDENTIFIER : CHAR (CHAR | DIGIT | '_')*;

fragment CHAR : ('a'..'z' | 'A'..'Z');

fragment DIGIT : ('0'..'9');


