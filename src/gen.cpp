#include "include/gen.h"

gen::gen(int dis, bool d) {
	debug = d;
	if(dis == 0) {
		std::cout << "Baza juz stworzona\n";
		return;
	}
	int kon = 8240087;
	Cube cube;
	std::fstream file;
	file.open("states.txt", std::ios::out);
	if(!file.good()) {
		std::cerr << "COS SIE ZJEBALO\n";
		return;
	}
	std::queue<TC> q;
	int cnt = 1;
	int prev = 1;
	q.push(TC(cube, "", 0));
	while(q.front().third < dis) {
		auto cur = q.front();
		q.pop();
		for(int i = 0 ; i < MOVES_CNT ; i++) {
			Cube seq;
			seq = cur.first;
			seq.rotate(moves[i]);
			if(vis.count(seq.hashCube()) == 0) {
				// seq.printCube();
				q.push(TC(seq, cur.second + " " + moves[i], cur.third + 1));
				vis.insert({seq.hashCube(), cur.second + " " + moves[i]});
				file << (seq.hashCube() + " " + cur.second + " " + moves[i]) << "\n";
				file.flush();
				cnt++;
			}
		}
		if(cnt*100/kon != prev) {
			system("clear");
			prev = cnt*100/kon;
			std::cout << prev << "%\n";
		}
	}
	std::cout << "Stanow: " << cnt - 1 << "\n";
	file.close();
}

gen::~gen() {
}