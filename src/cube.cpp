#include "include/cube.h"

Cube::~Cube() {
	// Cube::reset();
}

Cube::Cube() {
	debug = false;
	for(int face = 1 ; face <= 6 ; face++)
		for(int row = 1 ; row <= 3 ; row++)
			for(int column = 1 ; column <= 3; column++)
				cube[face][row][column] = (char)face;	
	solved = true;
	Hash = "";
}

Cube::Cube(bool d) {
	debug = d;
	for(int face = 1 ; face <= 6 ; face++)
		for(int row = 1 ; row <= 3 ; row++)
			for(int column = 1 ; column <= 3; column++)
				cube[face][row][column] = (char)face;	
	solved = true;
	Hash = "";
}

void Cube::reset() {
	for(int face = 1 ; face <= 6 ; face++)
		for(int row = 1 ; row <= 3 ; row++)
			for(int column = 1 ; column <= 3; column++)
				cube[face][row][column] = (char)face;	
	solved = true;
}

///Debug functions
void Cube::w() {
	std::cerr << "W";
}
void Cube::r() {
	std::cerr << "\e[31mR\e[0m";
}
void Cube::g() {
	std::cerr << "\e[32mG\e[0m";	
}
void Cube::o() {
	std::cerr << "\e[35mO\e[0m";	
}
void Cube::b() {
	std::cerr << "\e[34mB\e[0m";	
}
void Cube::y() {
	std::cerr << "\e[33mY\e[0m";	
}

char Cube::giveColor(int face, int &row, int &column) {
	return cube[face][row][column];
}

char Cube::giveColor(char &c) {
	if(c == 'W')	return WHITE;
	if(c == 'G')	return GREEN;
	if(c == 'B')	return BLUE;
	if(c == 'O')	return ORANGE;
	if(c == 'Y') 	return YELLOW;
	if(c == 'R')	return RED;
}

void Cube::printColor(int face, int &row, int &column) {
	int Color = Cube::giveColor(face, row, column);
	switch(Color) {
		case 1: 
			Cube::w();
			break;
		case 2: 
			Cube::r();
			break;
		case 3: 
			Cube::g();
			break;
		case 4: 
			Cube::o();
			break;
		case 5: 
			Cube::b();
			break;
		case 6: 
			Cube::y();
			break;

	}
}

void Cube::printCube() {
	//TOP
	for(int row = 1 ; row <= 3 ; row++) {
		std::cerr << "      ";
		for(int column = 1 ; column <= 3; column++) {
			Cube::printColor(TOP, row, column); 
			std::cerr << " ";
		}
		std::cerr << "\n";
	}
	//LEFT
	for(int row = 1 ; row <= 3 ; row++) {
		for(int column = 1 ; column <= 3; column++) {
			Cube::printColor(LEFT, row, column); 
			std::cerr << " ";
		}
		for(int column = 1 ; column <= 3; column++) {
			Cube::printColor(FRONT, row, column); 
			std::cerr << " ";
		}
		for(int column = 1 ; column <= 3; column++) {
			Cube::printColor(RIGHT, row, column); 
			std::cerr << " ";
		}
		for(int column = 1 ; column <= 3; column++) {
			Cube::printColor(BACK, row, column); 
			std::cerr << " ";
		}
		std::cerr << "\n";
	}
	//DOWN
	for(int row = 1 ; row <= 3 ; row++) {
		std::cerr << "      ";
		for(int column = 1 ; column <= 3; column++) {
			Cube::printColor(DOWN, row, column); 
			std::cerr << " ";
		}
		std::cerr << "\n";
	}
	std::cerr << "\n";
}

void Cube::readScramble() {
	// std::cout << "Top face:\n";
	for(int face = 1 ; face <= 6 ; face++) 
		for(int row = 1 ; row <= 3 ; row++) 
			for(int column = 1 ; column <= 3 ; column++) {
				char c;
				std::cin >> c;
				cube[face][row][column] = giveColor(c);
			}
}

void Cube::swapColors(TI &s1, TI &s2, TI &s3, TI &s4) {
	char buffor = cube[s1.first][s1.second][s1.third];
	cube[s1.first][s1.second][s1.third] = cube[s2.first][s2.second][s2.third];
	cube[s2.first][s2.second][s2.third] = cube[s3.first][s3.second][s3.third];
	cube[s3.first][s3.second][s3.third] = cube[s4.first][s4.second][s4.third];	
	cube[s4.first][s4.second][s4.third] = buffor;
}

void Cube::R() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(TOP, 3, 3);
	s2 = TI(FRONT, 3, 3);
	s3 = TI(DOWN, 3, 3);
	s4 = TI(BACK, 1, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 2, 3);
	s2 = TI(FRONT, 2, 3);
	s3 = TI(DOWN, 2, 3);
	s4 = TI(BACK, 2, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 3);
	s2 = TI(FRONT, 1, 3);
	s3 = TI(DOWN, 1, 3);
	s4 = TI(BACK, 3, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(RIGHT, 1, 1);
	s2 = TI(RIGHT, 3, 1);
	s3 = TI(RIGHT, 3, 3);
	s4 = TI(RIGHT, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(RIGHT, 1, 2);
	s2 = TI(RIGHT, 2, 1);
	s3 = TI(RIGHT, 3, 2);
	s4 = TI(RIGHT, 2, 3);
	swapColors(s1, s2, s3, s4);	
}
void Cube::R2() {
	Cube::R();
	Cube::R();
} 
void Cube::RP() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(TOP, 3, 3);
	s2 = TI(BACK, 1, 1);	
	s3 = TI(DOWN, 3, 3);
	s4 = TI(FRONT, 3, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 2, 3);
	s2 = TI(BACK, 2, 1);	
	s3 = TI(DOWN, 2, 3);
	s4 = TI(FRONT, 2, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 3);
	s2 = TI(BACK, 3, 1);	
	s3 = TI(DOWN, 1, 3);
	s4 = TI(FRONT, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(RIGHT, 1, 1);
	s2 = TI(RIGHT, 1, 3);
	s3 = TI(RIGHT, 3, 3);
	s4 = TI(RIGHT, 3, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(RIGHT, 1, 2);
	s2 = TI(RIGHT, 2, 3);
	s3 = TI(RIGHT, 3, 2);
	s4 = TI(RIGHT, 2, 1);
	swapColors(s1, s2, s3, s4);	
}
void Cube::F() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(TOP, 3, 1);
	s2 = TI(LEFT, 3, 3);
	s3 = TI(DOWN, 1, 3);
	s4 = TI(RIGHT, 1, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 3, 2);
	s2 = TI(LEFT, 2, 3);
	s3 = TI(DOWN, 1, 2);
	s4 = TI(RIGHT, 2, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 3, 3);
	s2 = TI(LEFT, 1, 3);
	s3 = TI(DOWN, 1, 1);
	s4 = TI(RIGHT, 3, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 1, 1);
	s2 = TI(FRONT, 3, 1);
	s3 = TI(FRONT, 3, 3);
	s4 = TI(FRONT, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 1, 2);
	s2 = TI(FRONT, 2, 1);
	s3 = TI(FRONT, 3, 2);
	s4 = TI(FRONT, 2, 3);
	swapColors(s1, s2, s3, s4);	
} 
void Cube::F2() {
	Cube::F();
	Cube::F();
} 
void Cube::FP() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(TOP, 3, 1);
	s2 = TI(RIGHT, 1, 1);	
	s3 = TI(DOWN, 1, 3);
	s4 = TI(LEFT, 3, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 3, 2);
	s2 = TI(RIGHT, 2, 1);	
	s3 = TI(DOWN, 1, 2);
	s4 = TI(LEFT, 2, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 3, 3);
	s2 = TI(RIGHT, 3, 1);	
	s3 = TI(DOWN, 1, 1);
	s4 = TI(LEFT, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 1, 1);
	s2 = TI(FRONT, 1, 3);
	s3 = TI(FRONT, 3, 3);
	s4 = TI(FRONT, 3, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 1, 2);
	s2 = TI(FRONT, 2, 3);
	s3 = TI(FRONT, 3, 2);
	s4 = TI(FRONT, 2, 1);
	swapColors(s1, s2, s3, s4);	
}
void Cube::L() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(TOP, 3, 1);
	s2 = TI(BACK, 1, 3);	
	s3 = TI(DOWN, 3, 1);
	s4 = TI(FRONT, 3, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 2, 1);
	s2 = TI(BACK, 2, 3);	
	s3 = TI(DOWN, 2, 1);
	s4 = TI(FRONT, 2, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 1);
	s2 = TI(BACK, 3, 3);	
	s3 = TI(DOWN, 1, 1);
	s4 = TI(FRONT, 1, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(LEFT, 1, 1);
	s2 = TI(LEFT, 3, 1);
	s3 = TI(LEFT, 3, 3);
	s4 = TI(LEFT, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(LEFT, 1, 2);
	s2 = TI(LEFT, 2, 1);
	s3 = TI(LEFT, 3, 2);
	s4 = TI(LEFT, 2, 3);
	swapColors(s1, s2, s3, s4);	
} 
void Cube::L2() {
	Cube::L();
	Cube::L();
} 
void Cube::LP() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(TOP, 3, 1);
	s2 = TI(FRONT, 3, 1);
	s3 = TI(DOWN, 3, 1);
	s4 = TI(BACK, 1, 3);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 2, 1);
	s2 = TI(FRONT, 2, 1);
	s3 = TI(DOWN, 2, 1);
	s4 = TI(BACK, 2, 3);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 1);
	s2 = TI(FRONT, 1, 1);
	s3 = TI(DOWN, 1, 1);
	s4 = TI(BACK, 3, 3);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(LEFT, 1, 1);
	s2 = TI(LEFT, 1, 3);
	s3 = TI(LEFT, 3, 3);
	s4 = TI(LEFT, 3, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(LEFT, 1, 2);
	s2 = TI(LEFT, 2, 3);
	s3 = TI(LEFT, 3, 2);
	s4 = TI(LEFT, 2, 1);
	swapColors(s1, s2, s3, s4);	
}
void Cube::B() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(TOP, 1, 1);
	s2 = TI(RIGHT, 1, 3);
	s3 = TI(DOWN, 3, 3);
	s4 = TI(LEFT, 3, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 2);
	s2 = TI(RIGHT, 2, 3);
	s3 = TI(DOWN, 3, 2);
	s4 = TI(LEFT, 2, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 3);
	s2 = TI(RIGHT, 3, 3);
	s3 = TI(DOWN, 3, 1);
	s4 = TI(LEFT, 1, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(BACK, 1, 1);
	s2 = TI(BACK, 3, 1);
	s3 = TI(BACK, 3, 3);
	s4 = TI(BACK, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(BACK, 1, 2);
	s2 = TI(BACK, 2, 1);
	s3 = TI(BACK, 3, 2);
	s4 = TI(BACK, 2, 3);
	swapColors(s1, s2, s3, s4);	
} 
void Cube::B2() {
	Cube::B();
	Cube::B();
}
void Cube::BP() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(TOP, 1, 1);
	s2 = TI(LEFT, 3, 1);	
	s3 = TI(DOWN, 3, 3);
	s4 = TI(RIGHT, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 2);
	s2 = TI(LEFT, 2, 1);	
	s3 = TI(DOWN, 3, 2);
	s4 = TI(RIGHT, 2, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 3);
	s2 = TI(LEFT, 1, 1);	
	s3 = TI(DOWN, 3, 1);
	s4 = TI(RIGHT, 3, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(BACK, 1, 1);
	s2 = TI(BACK, 1, 3);
	s3 = TI(BACK, 3, 3);
	s4 = TI(BACK, 3, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(BACK, 1, 2);
	s2 = TI(BACK, 2, 3);
	s3 = TI(BACK, 3, 2);
	s4 = TI(BACK, 2, 1);
	swapColors(s1, s2, s3, s4);	
}
void Cube::U() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(FRONT, 1, 1);
	s2 = TI(RIGHT, 1, 1);
	s3 = TI(BACK, 1, 1);
	s4 = TI(LEFT, 1, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 1, 2);
	s2 = TI(RIGHT, 1, 2);
	s3 = TI(BACK, 1, 2);
	s4 = TI(LEFT, 1, 2);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 1, 3);
	s2 = TI(RIGHT, 1, 3);
	s3 = TI(BACK, 1, 3);
	s4 = TI(LEFT, 1, 3);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 1);
	s2 = TI(TOP, 3, 1);
	s3 = TI(TOP, 3, 3);
	s4 = TI(TOP, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 2);
	s2 = TI(TOP, 2, 1);
	s3 = TI(TOP, 3, 2);
	s4 = TI(TOP, 2, 3);
	swapColors(s1, s2, s3, s4);	
} 
void Cube::U2() {
	Cube::U();
	Cube::U();
} 
void Cube::UP() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(FRONT, 1, 1);
	s2 = TI(LEFT, 1, 1);	
	s3 = TI(BACK, 1, 1);
	s4 = TI(RIGHT, 1, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 1, 2);
	s2 = TI(LEFT, 1, 2);	
	s3 = TI(BACK, 1, 2);
	s4 = TI(RIGHT, 1, 2);
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 1, 3);
	s2 = TI(LEFT, 1, 3);	
	s3 = TI(BACK, 1, 3);
	s4 = TI(RIGHT, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 1);
	s2 = TI(TOP, 1, 3);
	s3 = TI(TOP, 3, 3);
	s4 = TI(TOP, 3, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(TOP, 1, 2);
	s2 = TI(TOP, 2, 3);
	s3 = TI(TOP, 3, 2);
	s4 = TI(TOP, 2, 1);
	swapColors(s1, s2, s3, s4);	
}
void Cube::D() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(FRONT, 3, 1);
	s2 = TI(LEFT, 3, 1);
	s3 = TI(BACK, 3, 1);
	s4 = TI(RIGHT, 3, 1);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 3, 2);
	s2 = TI(LEFT, 3, 2);
	s3 = TI(BACK, 3, 2);
	s4 = TI(RIGHT, 3, 2);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 3, 3);
	s2 = TI(LEFT, 3, 3);
	s3 = TI(BACK, 3, 3);
	s4 = TI(RIGHT, 3, 3);	
	swapColors(s1, s2, s3, s4);
	s1 = TI(DOWN, 1, 1);
	s2 = TI(DOWN, 3, 1);
	s3 = TI(DOWN, 3, 3);
	s4 = TI(DOWN, 1, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(DOWN, 1, 2);
	s2 = TI(DOWN, 2, 1);
	s3 = TI(DOWN, 3, 2);
	s4 = TI(DOWN, 2, 3);
	swapColors(s1, s2, s3, s4);	
}
void Cube::D2() {
	Cube::D();
	Cube::D();
} 
void Cube::DP() {
	TI s1;
	TI s2;
	TI s3;
	TI s4;
	s1 = TI(FRONT, 3, 1);
	s2 = TI(RIGHT, 3, 1);	
	s3 = TI(BACK, 3, 1);
	s4 = TI(LEFT, 3, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 3, 2);
	s2 = TI(RIGHT, 3, 2);	
	s3 = TI(BACK, 3, 2);
	s4 = TI(LEFT, 3, 2);
	swapColors(s1, s2, s3, s4);
	s1 = TI(FRONT, 3, 3);
	s2 = TI(RIGHT, 3, 3);	
	s3 = TI(BACK, 3, 3);
	s4 = TI(LEFT, 3, 3);
	swapColors(s1, s2, s3, s4);
	s1 = TI(DOWN, 1, 1);
	s2 = TI(DOWN, 1, 3);
	s3 = TI(DOWN, 3, 3);
	s4 = TI(DOWN, 3, 1);
	swapColors(s1, s2, s3, s4);
	s1 = TI(DOWN, 1, 2);
	s2 = TI(DOWN, 2, 3);
	s3 = TI(DOWN, 3, 2);
	s4 = TI(DOWN, 2, 1);
	swapColors(s1, s2, s3, s4);	
}

void Cube::rotate(std::string &what) {
	if(what == "R")			Cube::R();
	else if(what == "R2")	Cube::R2();
	else if(what == "RP")	Cube::RP();
	else if(what == "L")	Cube::L();
	else if(what == "L2")	Cube::L2();
	else if(what == "LP")	Cube::LP();
	else if(what == "D")	Cube::D();
	else if(what == "D2")	Cube::D2();
	else if(what == "DP")	Cube::DP();
	else if(what == "U")	Cube::U();
	else if(what == "UP")	Cube::UP();
	else if(what == "U2")	Cube::U2();
	else if(what == "L")	Cube::L();
	else if(what == "L2")	Cube::L2();
	else if(what == "LP")	Cube::LP();
	else if(what == "B")	Cube::B();
	else if(what == "B2")	Cube::B2();
	else if(what == "BP")	Cube::BP();		
	else if(what == "F")	Cube::F();
	else if(what == "F2")	Cube::F2();
	else if(what == "FP")	Cube::FP();		
}

PSI Cube::readAlgo() {
	int cnt = 0;
	std::string ans = "";
	std::string cur = "";
	std::cin >> cur;
	while(cur != "K") {
		ans = ans.append(cur + " ");
		cnt++;
		std::cin >> cur;
	}
	// ans.pop_back();
	return mp(ans, cnt);
}

void Cube::processAlgo(PSI Algo) {
	std::string alg = Algo.first;
	int cnt = Algo.second;
	int wsk = 0;
	std::cerr << Algo.second << "\n";
	for(int i = 0 ; i < cnt ; i++) {
		std::string rotation = "";
		while(alg[wsk] != ' ')
			rotation += alg[wsk++];
		wsk++;
		if(debug)	std::cerr << rotation << " ";
		Cube::rotate(rotation);
	}
	std::cerr << "\n";
} 

std::string Cube::hashCube() {
	std::string has = "";
	for(int face = 1 ; face <= 6 ; ++face) 
		for(int row = 1 ; row <= 3 ; ++row) 
			for(int column = 1 ; column <= 3 ; ++column)
				has.push_back((char)(cube[face][row][column] + '0'));
	return Hash = has;
}

int Cube::giveH() {
	int res = 0;
	for(int face = 1 ; face <= 6 ; ++face) {
		int curRes = 0;
		for(int row = 1 ; row <= 3 ; ++row) {
			for(int column = 1 ; column <= 3 ; ++column) {
				if(cube[face][row][column] == cube[face][row][column + 1])
					++curRes;
				if(cube[face][row][column] == cube[face][row + 1][column])
					++curRes;
			}
		}
		//std::cout << face << " " << curRes << std::endl;
		res += curRes;
	}
	return h = res;
}	

int Cube::giveF(int gFun) {
	return f = h - gFun;
}

bool Cube::operator<(const Cube &k) const {
	return f < k.f;
}

PSI Cube::reversedAlgo(std::string Algo) {
	std::string ans = "";
	std::string alg = Algo;
	std::vector<std::string> rotations;
	int wsk = 0;
	int cnt = 0;
	for( ; wsk < (int)alg.size() ;) {
		std::string rotation = "";
		while(wsk < (int)alg.size() && alg[wsk] != ' ')
			rotation += alg[wsk++];
		wsk++;
		//if(wsk >= (int)alg.size())	break;	
		if(rotation.size() == 1)
			rotations.push_back(rotation + "P");
		else if(rotation[1] == 'P')
			rotations.push_back(rotation.substr(0, 1));
		else 
			rotations.push_back(rotation);
	}
	for(int i = rotations.size() - 1; i >= 0 ; --i) 
		ans += (rotations[i] + " ");
	return mp(ans, (int)rotations.size());
}