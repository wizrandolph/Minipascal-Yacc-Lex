flex pascal_lex.l
yacc -d pascal_yacc.y
gcc main.c y.tab.c lex.yy.c ir.c ast.c table.c -o bas.exe
dot graphviz.dot -Tpng -o ast.png