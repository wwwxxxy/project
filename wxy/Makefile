main:main.o queue.o stack.o graph.o 
	gcc  main.o queue.o stack.o graph.o  -o a.out

main.o:main.c
	gcc  -c main.c

queue.o:queue.c
	gcc  -c queue.c

stack.o:stack.c
	gcc  -c stack.c

graph.o:graph.c
	gcc  -c graph.c

clean:
	rm main.o && rm queue.o && rm tree.o && rm stack.o && rm graph.o && rm a.out

