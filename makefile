all = main.cpp student.cpp student.h address.cpp address.h date.cpp date.h
out = main.o

$(out): $(all)
	g++ -o $(out) $(all)

clean:
	rm $(out)

run:	${out}
	./${out}
