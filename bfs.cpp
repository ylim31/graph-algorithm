#include "bfs.h"
#include "graph.h"
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

const int BFS::INF = 9999;
const int BFS::EMPTY_VERTEX = -1;

BFS::BFS() : g_(true, false) {}

BFS::BFS(string node_filename, string neighbor_filename) : g_(true, false) {

ifstream lastfm_file;
ifstream lastfm_neighbor_file;
lastfm_file.open(node_filename);
lastfm_neighbor_file.open(neighbor_filename);

lastfm_neighbor_file.close();

}

void BFS::traversal(Vertex start) {
    
}

