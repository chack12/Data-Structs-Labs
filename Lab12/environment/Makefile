HelloWorld.exe: Main.o HelloWorld.o
		g++ -g -o HelloWorld.exe HelloWorld.o Main.o
		
Main.o: Main.cxx HelloWorld.hxx
		g++ -g -o Main.o -c Main.cxx
		
HelloWorld.o: HelloWorld.cxx HelloWorld.hxx
		g++ -g -o HelloWorld.o -c Main.cxx
clean: 
		rm HelloWorld.o Main.o HelloWorld.o
