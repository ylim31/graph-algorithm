#include "bfs.h"
#include "graph.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

BFS::BFS() : g_(true, false) {}

BFS::BFS(string node_filename, string neighbor_filename) : g_(true, false) {
ifstream lastfm_file;
ifstream lastfm_neighbor_file;
lastfm_file.open(node_filename);
lastfm_neighbor_file.open(neighbor_filename);

while (lastfm_file.good()) {
    string node_label;
    getline(lastfm_file, node_label, ',');
    g_.insertVertex(node_label); 
    is_visited_[node_label] = false;
}

lastfm_file.close();

size_t i = 0;
while (lastfm_neighbor_file.good()) {
        string each;
        string node_neighbor;
        getline(lastfm_neighbor_file, node_neighbor, ']');
        char node_neighbor_char[node_neighbor.size()];
        strcpy(node_neighbor_char, node_neighbor.c_str());
        
        char* piece = strtok(node_neighbor_char, " , \" \t []");

        while (piece != NULL) { 
            g_.insertEdge(to_string(i), piece);
            piece = strtok(NULL, ", \" []");      
            is_visited_[piece] = false;
        }
        i++;  
    }

lastfm_neighbor_file.close();
}

vector<Vertex> BFS::traversal(Vertex start) {
    queue<Vertex> q;
    vector<Vertex> ret;
    
    is_visited_[start] = true;
    q.push(start);

    while(!q.empty()) {
        start = q.front();
        //cout<< start << " ";
        ret.push_back(start);
        q.pop();

        vector<Vertex> its_neighbor = g_.getAdjacent(start);
        for(int i = 0; i < its_neighbor.size(); i++) {
            if (!is_visited_[its_neighbor[i]]) {
                is_visited_[its_neighbor[i]] = true;
                q.push(its_neighbor[i]);
            }
        }
    }
    return ret;
}

