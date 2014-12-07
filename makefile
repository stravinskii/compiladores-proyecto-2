all:        
	cd src/ && \
	flex pylex.l && \
	bison -d pysin.y -o pysin.cpp && \
	g++ pylex.cpp pysin.cpp -o pylex -std=c++0x
install:
	pwd=`pwd` && \
	echo "export PATH=$$PATH:$$pwd"
	echo ">> ~/.bashrc"
	echo "cp src/pythonpc ."
	echo "chmod +x pythonpc"
clean:
	rm pylex.cpp
	rm pylex
	rm pysin.cpp
	rm pysin.output
	rm pysin.hpp
