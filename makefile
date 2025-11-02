bin/programa2 : src/Punteros.cpp
	c++ src/Punteros.cpp -o bin/programa2 -I include

ejecutar : bin/programa2
	./bin/programa2


bin/ejemplo : src/prueba.cpp
	c++ src/prueba.cpp -o bin/ejemplo -I include -l ftxui-screen

ejemplo : bin/ejemplo
	./bin/ejemplo

run : bin/animacion
	./bin/animacion

bin/animacion : src/Examen.cpp include/*.hpp
	@mkdir -p bin
	g++ -Iinclude -o bin/animacion src/Examen.cpp -lftxui-component -lftxui-dom -lftxui-screen
# esto es un comentario 