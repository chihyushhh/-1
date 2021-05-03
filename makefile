all: quicksort.o mergesort.o radixsort.o quicksort2.o mergesort2.o radixsort2.o

quicksort.o : quicksort_num.c
	gcc quicksort_num.c -o a.exe
	./a.exe
mergesort.o : mergesort_num.c
	gcc  mergesort_num.c -o 1.exe
	./1.exe
radixsort.o : radixsort_num.c
	gcc radixsort_num.c -o 1.exe
	./1.exe
quicksort2.o : quicksort_str.c
	gcc quicksort_str.c -o 1.exe
	./1.exe
mergesort2.o : mergesort_str.c
	gcc mergesort_str.c -o 1.exe
	./1.exe
radixsort2.o : radixsort_str.c
	gcc radixsort_str.c -o 1.exe
	./1.exe