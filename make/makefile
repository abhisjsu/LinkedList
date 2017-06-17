out: singlyLinkedList.o
	gcc -o out ./../bin/singlyLinkedList.o
	mv out ./../output/

singlyLinkedList.o: ./../src/singlyLinkedList.c
	gcc -c ./../src/singlyLinkedList.c
	mv singlyLinkedList.o ./../bin/

run: ./../output/out
	./../output/out
