
main: main.o horses.o
	g++ -std=c++11 -o main main.o horses.o

main.o: main.cpp horses.cpp
	g++ -std=c++11 -c main.cpp horses.cpp

horses.o: horses.cpp horses.h
	g++ -std=c++11 -c horses.cpp


clean: 
	rm *.out ./main *.o