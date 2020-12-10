#pragma once

#include "dijkstra.h"
#include "cs225/graph.h"
#include <string>
#include <vector>

using namespace std;

/**
 * LandMark class. LandMark algorithm using the Dijkstra algorithm.
 */
class LandMark {
    public:
        LandMark();

        /**
         * Builds LandMark from json file and target file.
         * @param json_filename The nodes and its neighbor in json format.
         * @param target_filename The nodes and its target to process their edge weights. 
         */
        LandMark(string json_filename, string target_filename);

        /**
         * Loops of the dijkstra algorithm to find the
         * @param
         * @
         * @
         * @
         */ 
        vector<Vertex> find_shortest_path(Vertex start, Vertex end, vector<Vertex> landmarks);
    
    private:
        Dijkstra d_;
};