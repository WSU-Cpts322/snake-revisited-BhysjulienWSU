GCC=g++


all: snake
snake: snake_source/main.cpp
	$(GCC) -g -Wall -o snake snake_source/main.cpp snake_source/snake.cpp snake_source/scoreManager.cpp snake_source/fruit.cpp snake_source/badSnake.cpp snake_source/settings.cpp snake_source/selectionMngr.cpp snake_source/terminal.cpp snake_source/specialPrints.cpp snake_source/gameManager.cpp snake_source/fileIO.cpp snake_source/security.cpp -lncurses

clean: 
	$(RM) snake
