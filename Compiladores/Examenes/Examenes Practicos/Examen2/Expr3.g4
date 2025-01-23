grammar Expr3;

root: action+ EOF;

action: NAME ':=' expr            # Assign
      | 'write' NAME             # Write
      | NAME '++'                # Increment
      | NAME '--'                # Decrement
      ;

expr: <assoc=right> expr '^' expr    # Power
    | expr ('*'|'/') expr            # MulDiv
    | expr ('+'|'-') expr            # AddSub
    | NUM                            # Number
    | NAME                           # Variable
    ;

NUM: '-'? [0-9]+ ('.' [0-9]+)? ([eE] [+-]? [0-9]+)?;
NAME: [A-Za-z_] [A-Za-z0-9_]*;
WS: [ \t\r\n]+ -> skip;

