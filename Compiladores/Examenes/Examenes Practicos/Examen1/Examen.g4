grammar Examen;
prog:   expr +; 
expr:   '(' expr ')'                     # PAR
    |   '-''(' expr ')'                  # NEGPAR
    |   expr '^' expr                    # POT
    |   expr ('*'|'/') expr              # MULDIV
    |   expr ('+'|'-') expr              # SUMRES
    |   expr '&&' expr                   # AND
    |   expr '||' expr                   # OR
    |   '-' atom                         # NEGATOM
    |   '-' expr                         # NEG
    |   atom                             # ATOM
    ;
atom:   ID                               # VAR
    |   NUMBER                           # NUM
    ;
ID      : [a-zA-Z]+ ;                 
NUMBER  : [0-9]+ ('.' [0-9]+)? ;      
WS      : [ \t\r\n]+ -> skip ;       
