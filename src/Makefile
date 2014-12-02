all: compile

compile:
	g++ -std=c++0x ../lib/AST.hpp
	g++ -std=c++0x ../lib/MAST.hpp
	flex pylex.l
	bison -dv pysin.y -o pysin.cpp -t
	g++ pylex.cpp pysin.cpp -o pylex -std=c++0x
	g++ -std=c++0x Prueba.cpp -o prueba

clean:
	rm pylex.cpp pylex pysin.cpp pysin.output pysin.hpp
debug:
	flex -d -v pylex.l
	bison -dv pysin.y -o pysin.cpp
	g++ pylex.cpp pysin.cpp -o pylex -std=c++11
run1:
	more Prueba.py
	./pylex Prueba.py

run:
	more Ejemplo.py
	./pylex Ejemplo.py
