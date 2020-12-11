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
         * Loops the Dijkstra algorithm for every permutation of landmark vector to find the path
         * with shortest weights (cost) to travel.
         * @param start The start vertex.
         * @param end The end vertex.
         * @param landmarks Vector of vertices of the landmarks.
         * @return Shortest path between start and end that visits all the landmark vertices.
         */ 
        vector<Vertex> find_shortest_path(Vertex start, Vertex end, vector<Vertex> landmarks);
    
    private:
        Dijkstra d_;
};