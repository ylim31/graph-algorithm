#pragma once

#include "dijkstra.h"
#include "cs225/graph.h"
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
class LandMark {
    public:
        LandMark();
        LandMark(string node_filename, string neighbor_filename);
        vector<Vertex> find_shortest_path(Vertex start, Vertex end, vector<Vertex> landmarks);
    
    private:
        Dijkstra d_;
};