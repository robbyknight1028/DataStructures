BTrees: main.o btree.o btreenode.o
	g++ main.o bst.o -o BST

main.o: main.cpp btree.h btreenode.h
	g++ -c main.cpp

btree.o: btree.cpp btree.h 
	g++ -c btree.cpp

btreenode.o: btreenode.cpp btreenode.h btree.h
	g++ -c btreenode.cpp

clean:
	rm *.o
	rm BTrees

run:    BTrees
	./BTrees
