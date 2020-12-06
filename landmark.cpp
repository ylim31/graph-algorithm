#include "landmark.h"
#include "dijkstra.h"
#include <algorithm>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;


LandMark::LandMark() : d_("", "") { }
LandMark::LandMark(string node_filename, string neighbor_filename) : d_(node_filename, neighbor_filename) {
}

vector<Vertex> LandMark::find_shortest_path(Vertex start, Vertex end, vector<Vertex> landmarks) {
    vector<Vertex> shortest_path;
    landmarks.insert(landmarks.begin(), start);
    landmarks.push_back(end);

    for (unsigned i = 0; i < landmarks.size() - 1; i++) {
        shortest_path.insert(shortest_path.begin(), shortest_path.end(), d_.find_shortest_path(landmarks[i], landmarks[i+1]).end());
    }
    return shortest_path;
    
}


