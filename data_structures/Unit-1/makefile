IDIR =include
CC=gcc

ODIR=obj
SRCDIR=src

test:	$(ODIR)/test.o $(ODIR)/singly_linked_list.o $(ODIR)/recursion.o $(ODIR)/pointers_arrays.o $(ODIR)/doubly_linked_list.o
	$(CC) -o test $(ODIR)/test.o $(ODIR)/singly_linked_list.o $(ODIR)/recursion.o $(ODIR)/pointers_arrays.o $(ODIR)/doubly_linked_list.o

$(ODIR)/test.o:	test.c
	$(CC) -o $(ODIR)/test.o -c test.c

$(ODIR)/singly_linked_list.o:	$(SRCDIR)/singly_linked_list.c $(IDIR)/SinglyLinkedList.h
	$(CC) -o $(ODIR)/singly_linked_list.o -c $(SRCDIR)/singly_linked_list.c

$(ODIR)/recursion.o:	$(SRCDIR)/recursion.c $(IDIR)/Recursion.h
	$(CC) -o $(ODIR)/recursion.o -c $(SRCDIR)/recursion.c

$(ODIR)/pointers_arrays.o:	$(SRCDIR)/pointers_arrays.c $(IDIR)/PointersArrays.h
	$(CC) -o $(ODIR)/pointers_arrays.o -c $(SRCDIR)/pointers_arrays.c

$(ODIR)/doubly_linked_list.o:	$(SRCDIR)/doubly_linked_list.c $(IDIR)/DoublyLinkedList.h
	$(CC) -o $(ODIR)/doubly_linked_list.o -c $(SRCDIR)/doubly_linked_list.c

clean:
	rm -f $(ODIR)/*.o
	rm test