all:
	gcc main.c ./functii/taskFunctions.c ./functii/liste.c -o lanParty
clean:
	rm -f lanParty
