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
    vector<Vertex> eachShortestPath;
    landmarks.insert(landmarks.begin(), start);
    landmarks.push_back(end);
<<<<<<< HEAD
    
    for (unsigned i = 0; i < landmarks.size() - 1; i++) {
        
        eachShortestPath = d_.find_shortest_path(landmarks[i], landmarks[i+1]);
        /*
        for(unsigned j = 0 ; j < eachShortest.size(); j++){
            cout<<"HERE IS SHORTEST PATH" + whatever[j]<<endl;
        }
        */
        if(i>0){
            eachShortestPath.erase(eachShortestPath.begin());
        }
        
        shortest_path.insert(shortest_path.end(), eachShortestPath.begin(), eachShortestPath.end());
        d_.clear();
=======


    for (unsigned i = 0; i < landmarks.size() - 1; i++) {
        shortest_path.insert(shortest_path.end(), shortest_path.begin(), d_.find_shortest_path(landmarks[i], landmarks[i+1]).end());
>>>>>>> cdf40c67fe183ed08a8f79117e9556cf82ca28b6
    }
    return shortest_path;
    
}


