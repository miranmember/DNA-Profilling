build_app:
	rm -f application.exe
	g++ -g -std=c++11 -Wall application.cpp -o application.exe
	
run_app:
	./application.exe

valgrind_app:
	valgrind --tool=memcheck --leak-check=yes ./application.exe


build_tests:
	rm -f tests.exe
	g++ tests.cpp -o tests.exe -lgtest -lgtest_main -lpthread
	
run_tests:
	./tests.exe

valgrind_tests:
	valgrind --tool=memcheck --leak-check=yes ./tests.exe

dna:
	rm -f application.exe
	g++ -g -std=c++11 -Wall application.cpp -o application.exe
	valgrind --tool=memcheck --leak-check=yes ./application.exe