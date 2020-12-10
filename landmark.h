#pragma once

#include "dijkstra.h"
#include "cs225/graph.h"
#include <string>
#include <vector>

using namespace std;
class LandMark {
    public:
        LandMark();

        /**
         * 
         */
        LandMark(string json_filename, string target_filename);
        vector<Vertex> find_shortest_path(Vertex start, Vertex end, vector<Vertex> landmarks);
    
    private:
        Dijkstra d_;
};