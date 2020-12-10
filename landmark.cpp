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
LandMark::LandMark(string json_filename, string target_filename) : d_(json_filename, target_filename) { }

vector<Vertex> LandMark::find_shortest_path(Vertex start, Vertex end, vector<Vertex> landmarks) {
    vector<Vertex> shortest_path;
    vector<Vertex> eachShortestPath;
    vector<Vertex> smallest_shortest_path;

    vector<Vertex> copy;
    int min_cost = 999;
    
    sort(landmarks.begin(), landmarks.end());
    
    do {
        copy = landmarks;
        copy.insert(copy.begin(), start);
        copy.push_back(end);
        for (unsigned i = 0; i < copy.size(); i++) {
            cout << "COPY PATH: "<< copy[i] << endl;
        }
        for (unsigned i = 0; i < copy.size() - 1; i++) {
            
            eachShortestPath = d_.find_shortest_path(copy[i], copy[i+1]);
            if (i > 0) {
                eachShortestPath.erase(eachShortestPath.begin());
            }
            shortest_path.insert(shortest_path.end(), eachShortestPath.begin(), eachShortestPath.end());
            d_.clear();
        }
        for (unsigned i = 0; i < shortest_path.size(); i++) {
            cout << "SHORTEST PATH: "<< shortest_path[i] << endl;
        }
        int total_cost = d_.get_total_cost(shortest_path);
        cout << total_cost << endl;
        if (total_cost < min_cost) {
            min_cost = total_cost;
            smallest_shortest_path = shortest_path;
        }
        shortest_path.clear();
    } while (std::next_permutation(landmarks.begin(), landmarks.end()));
    return smallest_shortest_path;  
}
