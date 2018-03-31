#include "config.h"
#include "cube.h"

#ifndef GEN_H
#define GEN_H

typedef triplet<Cube, std::string, int> TC;

class gen {
	public:
	std::string moves[18] = {"R", "RP", "U", "UP", "L", "LP", "D", 
							"DP", "F", "FP", "B", "BP", "R2", "L2", 
								"B2", "F2", "U2", "D2",};
	std::unordered_map<std::string, std::string> vis;
	gen(int dis, bool d);
	~gen();
	bool debug;
};

#endif
