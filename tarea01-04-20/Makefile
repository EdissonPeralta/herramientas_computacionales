#$^ -> primera dependendia
#$< ->todas las dependencias
#$@ ->nombre del target

all : 1.x datos.txt 1.pdf

1.x : 1.cpp
	g++ $^ -o 1.x

datos.txt : 1.x
	./1.x > datos.txt

1.pdf : datos.txt
	gnuplot 1.gp

clean :
	rm -f datos.txt 1.x a.out 1.pdf
