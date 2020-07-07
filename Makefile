TARGET:= minipascal

CFLAGS = -Wall -g
CFLAGS_TOOLS = -g
LD_FLAGS = -g

all: $(TARGET)

$(TARGET): pascal_lex.o pascal_yacc.o ast.o ir.o table.o main.o
	gcc $(LD_FLAGS) -o $@ $^

ast.o: ast.c ast.h
	gcc $(CFLAGS) -c -o $@ ast.c

ir.o: ir.c ir.h table.h
	gcc $(CFLAGS) -c -o $@ ir.c

table.o: table.c table.h pascal_yacc.h
	gcc $(CFLAGS) -c -o $@ table.c

pascal_lex.o: pascal_lex.c pascal_yacc.h
	gcc $(CFLAGS_TOOLS) -c -o $@ pascal_lex.c

pascal_lex.c pascal_lex.h: pascal_lex.l
	flex -L -o pascal_lex.c --header-file=pascal_lex.h pascal_lex.l

pascal_yacc.o: pascal_yacc.c pascal_yacc.h pascal_lex.h
	gcc $(CFLAGS_TOOLS) -c -o $@ pascal_yacc.c

pascal_yacc.c pascal_yacc.h: pascal_yacc.y
	bison -l -v -d -o pascal_yacc.c pascal_yacc.y

main.o: main.c pascal_yacc.h pascal_lex.h
	gcc $(CFLAGS) -c -o $@ main.c

tmpclean:
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf *.dSYM
	rm -f pascal_lex.c pascal_lex.h
	rm -f pascal_yacc.c pascal_yacc.h pascal_yacc.output
	rm -f $(TARGET)

zip:
	tar --exclude *.tar.* -cvf $(TARGET).tar *
	gzip -f $(TARGET).tar
