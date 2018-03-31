#include "config.h"
#include "cube.h"
#include "gen.h"

#ifndef SOLVE_H
#define SOLVE_H

class Solve {
	private:
	Cube cube;

	public:
	Solve(Cube &input, bool d);
	~Solve();
	void go(gen &states);
	bool debug;
};

#endif