#include "config.h"

#ifndef CUBE_H
#define CUBE_H

template<typename T1, typename T2, typename T3>
struct triplet {
	T1 first;
	T2 second;
	T3 third;
	triplet() {}
	triplet(T1 a, T2 b, T3 c) {
		first = a;
		second = b;
		third = c;
	}
	bool operator==(const triplet<T1, T2, T3> &t) const {
		if(t.first == first && t.second == second && t.third == third)
			return true;
		return false;
	}
	bool operator!=(const triplet<T1, T2, T3> &t) const {
		if(t.first == first && t.second == second && t.third == third)
			return false;
		return true;
	}
};

typedef triplet<int, int, int> TI;

class Cube {
	private:
	char cube[7][5][5];
	std::string Hash;
	bool solved;
	int h, f;	//do A*


	public:
	Cube(bool d);
	Cube();
	~Cube();
	int dist;
	//debug
	char giveColor(char &color);
	char giveColor(int face, int &row, int &column);
	void printColor(int face, int &row, int &column);
	bool debug;
	void w();
	void r();
	void g();
	void o();
	void b();
	void y();
	void printCube();
	void reset();

	void readScramble();
	void getScramble(PSI &scramble);

	void swapColors(TI &s1, TI &s2, TI &s3, TI &s4);
	void R(); 
	void R2(); 
	void RP();
	void F(); 
	void F2(); 
	void FP();
	void L(); 
	void L2(); 
	void LP();
	void B(); 
	void B2(); 
	void BP();
	void U(); 
	void U2(); 
	void UP();
	void D(); 
	void D2(); 
	void DP();
	void rotate(std::string &what);
	PSI readAlgo();
	void processAlgo(PSI Algo);
	PSI reversedAlgo(std::string Algo);

	std::string hashCube();
	int giveH();
	int giveF(int gFun);

	bool operator<(const Cube &k) const;
};	

#endif