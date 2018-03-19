assembler: assembler.o parser.o builder.o reader.o table.o data.o code.o switch.o
	gcc -ansi -Wall -pedantic assembler.o parser.o builder.o reader.o table.o data.o code.o switch.o -o assembler

assembler.o:
	gcc -c assembler.c

parser.o:
	gcc -c module/parser.c

builder.o:
	gcc -c module/builder.c

reader.o:
	gcc -c module/reader.c

table.o:
	gcc -c module/table.c

data.o:
	gcc -c module/data.c

code.o:
	gcc -c module/code.c

switch.o:
	gcc -c module/switch.c

clean:
	-rm -f assembler.o
	-rm -f parser.o
	-rm -f builder.o
	-rm -f reader.o
	-rm -f table.o
	-rm -f data.o
	-rm -f code.o
	-rm -f switch.o
