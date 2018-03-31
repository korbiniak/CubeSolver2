#include "include/config.h"
#include "include/cube.h"
#include "include/gen.h"
#include "include/solve.h"

int main(int argc, char * argv []) {
	// printf("%s\n", argv[0]);
	Cube kostka;
	bool debug = atoi(argv[2]);
	gen generuj(atoi(argv[1]), debug);
	std::cout << "Witaj!\n";
	bool loop = true;
	while(loop) {
		std::cout 	<< "[1]: Narysuj stan kostki\n"
					<< "[2]: Wroc kostke do poczatkowego stanu\n"
					<< "[3]: Wykonaj algorytm na kostce\n"
					<< "[4]: Podaj stan kostki\n"
					<< "[5]: Ukladaj\n"
					<< "[6]: Znajdz krawedz\n"
					<< "[7]: Znajdz naroznik\n"
					<< "[20]: Zakoncz\n";
		int choice;
		std::cin >> choice;
		switch(choice) {
			case 1:
				// system("clear");
				kostka.printCube();
				break;
			case 2:
				// system("clear");
				kostka.reset();
				break;
			case 3:
				// system("clear");
				kostka.processAlgo(kostka.readAlgo());
				kostka.printCube();
				break;
			case 4:
				// system("clear");
				kostka.readScramble();
				break;
			case 5: 
			{
				Solve ukladaj(kostka, debug);
				ukladaj.go(generuj);
				break;
			}
			case 20:
			{
				system("clear");
				std::cout << "Dzieki za korzystanie z programu!\n";
				loop = false;
				break;
			}
			default:
				std::cout << "Ups! Cos nie tak\n";
				return 0;
				break;
		}
	}
}