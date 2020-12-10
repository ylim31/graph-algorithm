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
        LandMark(string json_filename, string target_filename);
        vector<Vertex> find_shortest_path(Vertex start, Vertex end, vector<Vertex> landmarks);
    
    private:
        Dijkstra d_;
};