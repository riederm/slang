grammar Slang;

pou : program;

program : 'PROGRAM' pouName=IDENTIFIER 
            declarationContainers+=declarations* 
            body=block
      'END_PROGRAM';

declarations:
   varDeclarations; 

varDeclarations :
   'VAR'
      variableDeclarations += variableDeclaration*
   'END_VAR';

variableDeclaration :
   variableName = IDENTIFIER ':' type=typeRef (variableDefinition)?';';

variableDefinition :
   ':=' variableDefinition;

typeRef :
   scalarTypeRef;

scalarTypeRef :
   typeName = ('INT' | 'BOOL' | 'LONG');

block :
   statements+=statement*;

statement :
   simpleStatement
   | structuredStatement;

structuredStatement:
   'STRUCTURED_STATEMENT';

expression: 
   simpleExpression (op=('='|'<>'|'<'|'>'|'<='|'>=') expression)?;

simpleExpression
   : left=term (additiveOperator=('+'|'-'|'OR') right=simpleExpression)?;

term:
   signedFactor (multiplicativeOperator=('*'|'/'|'MOD'|'AND') term)?;

signedFactor:
   prefix=('+'|'-')? factor;

factor:
   | notFactor
   | boolLiteral
   | unsignedInteger
   | callExpression;

notFactor:
   'NOT' op=factor;

callExpression:
   op=reference  ('(' parameters=parameterList? ')')?;

parameterList:
   expressions+= expression (',' expressions+=expression)*;

unsignedInteger: 
   value=NUM_INT;

boolLiteral:
   value=(TRUE|FALSE);

relationaloperator: 
   EQUAL
   | NOT_EQUAL
   | LT
   | LE
   | GE
   | GT
   ;

simpleStatement :
   assignmentStatement SEMI;

assignmentStatement:
   left=expression (':=' right=expression)?;

reference:
   IDENTIFIER;

WS
   : [ \t\r\n] -> skip;

TRUE: 'TRUE';
FALSE: 'FALSE';

IDENTIFIER : CHAR (CHAR | DIGIT | '_')*;

NUM_INT
   : ('0' .. '9') +
   ;

fragment CHAR : ('a'..'z' | 'A'..'Z');

fragment DIGIT : ('0'..'9');

EQUAL : '=';
NOT_EQUAL : '<>';
LT : '<';
LE : '<=';
GE : '>=';
GT : '>';
SEMI: ';';

