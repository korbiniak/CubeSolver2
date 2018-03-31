#include "include/solve.h"

Solve::Solve(Cube &input, bool d) {
	cube = input;
	debug = d;
}

Solve::~Solve() {}

void Solve::go(gen &states) {
	std::unordered_set<std::string> vis;
	if(debug)	cube.printCube();
	std::priority_queue<std::pair<Cube, std::string>> q;
	q.push(mp(cube, ""));
	std::string act = "";
	int cnt = 1;
	cube.dist = 0;
	while(states.vis.count(cube.hashCube()) == false && q.size() < 1000000) {
		if(debug) std::cout << cnt << " ";
		cube = q.top().first;
		act = q.top().second;
		q.pop();
		for(int i = 0 ; i < MOVES_CNT ; ++i) {
			Cube cube2 = cube;
			cube2.rotate(states.moves[i]);
			cube2.dist = cube.dist + 1;
			if(vis.count(cube2.hashCube()) == 0) {
				cnt++;
				cube2.giveH();
				cube2.giveF(cube2.dist);
				q.push(mp(cube2, act + " " + states.moves[i]));
				vis.insert(cube2.hashCube());
			}
		}
	}
	vis.clear();
	while(!q.empty())
		q.pop();
	std::cout << "Skonczylem!\nRozwiazanie: ";
	std::cout << act << " ";
	std::string alg = states.vis[cube.hashCube()];
	auto obrot = cube.reversedAlgo(alg);
	if(debug) std::cout << alg << "\nPo obrocie: "; 
	std::cout << obrot.first << "\n";
	std::cout << "Liczba ruchow: " << cube.dist + 6 << "\n";
}

