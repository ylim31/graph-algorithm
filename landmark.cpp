#include "landmark.h"
#include "dijkstra.h"
#include <algorithm>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include "cs225/graph.h"

using namespace std;


LandMark::LandMark() : d_("", "") { }
LandMark::LandMark(string json_filename, string target_filename) : d_(json_filename, target_filename) {
}

vector<Vertex> LandMark::find_shortest_path(Vertex start, Vertex end, vector<Vertex> landmarks) {
    vector<Vertex> shortest_path;
    landmarks.insert(landmarks.begin(), start);
    landmarks.push_back(end);


    for (unsigned i = 0; i < landmarks.size() - 1; i++) {
        shortest_path.insert(shortest_path.end(), shortest_path.begin(), d_.find_shortest_path(landmarks[i], landmarks[i+1]).end());
    }
    return shortest_path;
    
}


