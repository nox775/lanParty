all:
	gcc main.c ./functii/taskFunctions.c ./functii/liste.c ./functii/stack.c ./functii/queue.c ./functii/BSTree.c ./functii/AVLtree.c -o lanParty
clean:
	rm -f lanParty
