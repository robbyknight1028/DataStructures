BST: main.o bst.o
	g++ main.o bst.o -o BST

main.o: main.cpp bst.h
	g++ -c main.cpp

bst.o: bst.cpp bst.h
	g++ -c bst.cpp

clean:
	rm *.o
	rm BST

run:	BST
	./BST	
