all : compile run clean
compile :
	@g++ -c book.cpp -o book.o
	@g++ -c music.cpp -o music.o
	@g++ -c movie.cpp -o movie.o
	@g++ -c main.cpp -o main.o
	@g++ book.o music.o movie.o main.o -o x
	
run:
	@./x
	@echo "-----------------------------------------------"
clean: 
	@rm -f x
	@rm -f *.o
