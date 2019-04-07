grammar Slang;



pou : 'PROGRAM' IDENTIFIER   'END_PROGRAM';


WS
   : [ \t\r\n] -> skip;

CHAR : ('a'..'z' | 'A'..'Z');

DIGIT : ('0'..'9');

IDENTIFIER : CHAR (CHAR | DIGIT | '_')*;