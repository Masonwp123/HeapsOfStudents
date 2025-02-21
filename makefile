objects: main.o student.o address.o date.o
	g++ main.o student.o address.o date.o -o objects

main.o: main.cpp
	g++ -g -c main.cpp

student.o: student.h student.cpp
	g++ -g -c student.cpp

address.o: address.h address.cpp
	g++ -g -c address.cpp

date.o: date.h date.cpp
	g++ -g -c date.cpp

clean:
	rm *.o
	rm objects

run: objects
	./objects

debug: objects
	gdb objects

valgrind: objects
	valgrind --leak-check=full ./objects