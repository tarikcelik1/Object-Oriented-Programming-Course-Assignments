all : compile run clean
compile :
	@g++ -c world.cpp -o world.o
	@g++ -c robot.cpp -o robot.o
	@g++ -c romba.cpp -o romba.o
	@g++ -c bulldozer.cpp -o bulldozer.o
	@g++ -c humanic.cpp -o humanic.o
	@g++ -c robocop.cpp -o robocop.o
	@g++ -c optimusPrime.cpp -o optimusprime.o
	@g++ -c main.cpp -o main.o
	@g++  world.o robot.o romba.o bulldozer.o humanic.o robocop.o optimusprime.o main.o -o x
	
run:
	@./x
clean: 
	@rm -f x
	@rm -f *.o
