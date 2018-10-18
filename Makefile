# ADDBRA001 Makefile Template

## FLAGS ==================================================================
CC=g++ -std=c++11
LIBS=-lm
## ========================================================================

pca: pca.o
	$(CC) pca.o -o pca $(LIBS)


pca.o: pca.cpp
	$(CC) -c pca.cpp

clean:
	@rm -f *.o
	@rm pca

install:

	@mv pca ~/bin
