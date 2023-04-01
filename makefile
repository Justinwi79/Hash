proj6: proj6.o passserver.o
	g++ -o proj6.x proj6.o passserver.o  
proj6.o: proj6.cpp 
	g++ -c -std=c++11 -lcrypt proj6.cpp 
passserver.o: passserver.h passserver.cpp hashtable.h hashtable.hpp 
	g++ -c -std=c++11 passserver.cpp

clean: 
	-rm *.o
	-rm *.h.gch