grammar arit;
expr: expr op=('*'|'/'|'%') expr  # MulDivMod   
    | expr op=('+'|'-') expr      # AddSub     
    | INT                         # Int
    | FLOAT                       # Float
    | '(' expr ')'                # Parenthesis
    ;
INT: [0-9]+;
FLOAT: [0-9]+ '.' [0-9]+;
WS: [ \t\r\n]+ -> skip;

