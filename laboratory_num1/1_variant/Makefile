
analyze: main.cpp person.cpp person.hpp
	clang-10 --analyze --analyzer-output text -Xanalyzer main.cpp person.cpp 
	cppchek -q -j4 --enable=performance,protability,warning,style main.cpp person.cpp
