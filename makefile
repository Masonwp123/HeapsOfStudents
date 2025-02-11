all = main.cpp
out = main.o

$(out): $(all)
	g++ -o $(out) $(all)

clean:
	rm $(out)

run:	${out}
	./${out}
