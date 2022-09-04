all: main csvToBinary

csvToBinary: csvToBinary.o
	g++ csvToBinary.o -o csvToBinary

csvToBinary.o: csvToBinary.cpp;
	g++ -c csvToBinary.cpp

main: main.o funcoes.o
	g++ main.o funcoes.o -o main

main.o:: main.cpp
	g++ -c main.cpp

funcoes.o:	funcoes.cpp
	g++ -c funcoes.cpp
