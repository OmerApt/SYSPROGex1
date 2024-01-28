LOOPOBJECTS = basicClassification.o advancedClassificationLoop.o
RECOBJECTS = basicClassification.o advancedClassificationRecursion.o

recursive: libclassrec.a
loops: libclassloops.a
loopsd: libclassloops.so
recursived:libclassrec.so

flags = -Wall -g


all: mains maindloop maindrec

basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -g -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -Wall -g -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -Wall -g -c advancedClassificationRecursion.c

main.o: main.c NumClass.h
	gcc ${flags} -c main.c

libclassloops.a: ${LOOPOBJECTS}
	ar rcs libclassloops.a ${LOOPOBJECTS}
	ranlib libclassloops.a
	
libclassrec.a: ${RECOBJECTS}
	ar rcs libclassrec.a ${RECOBJECTS}
	ranlib libclassrec.a

libclassloops.so:${LOOPOBJECTS}
	gcc -shared -fpic -o libclassloops.so ${LOOPOBJECTS}

libclassrec.so:${LOOPOBJECTS}
	gcc -shared -fpic -o libclassrec.so ${LOOPOBJECTS}

mains: main.o libclassrec.a
	gcc -Wall -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	gcc ${flags} -o maindloop main.o ./libclassloops.so

maindrec: main.o libclassrec.so
	gcc ${flags} -o maindrec main.o ./libclassrec.so

clean: 
	rm -f *.a *.o *.so mains maindloop maindrec
.PHONY: clean all
