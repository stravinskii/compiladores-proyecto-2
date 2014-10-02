all:
	flex pylex.l
	bison -dv pysin.y -o pysin.cpp
	g++ pylex.cpp pysin.cpp -o pysin
debug:
	flex -d -v pylex.bck.l
	bison -dv pysin.y -o pysin.cpp
	g++ pylex.cpp pysin.cpp -o pysin
