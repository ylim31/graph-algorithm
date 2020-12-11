#include "bfs.h"
#include "cs225/graph.h"
#include "include/json.hpp"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

BFS::BFS() : g_(true, false) {}

BFS::BFS(string json_filename) : g_(true, false) {
    numVertices = 0;
    ifstream json_(json_filename);
    json j = json::parse(json_);
    for (auto &it : j.items()) {
        for (auto &itr : it.value().items()) {
            string each_neighbor = to_string(itr.value());
            each_neighbor.erase(remove(each_neighbor.begin(), each_neighbor.end(), '\"'), each_neighbor.end());
            g_.insertEdge(it.key(), each_neighbor);   
            is_visited_[each_neighbor] = false;
        }
        numVertices++;
        is_visited_[it.key()] = false;  
    }
    //g_.print();
    cout << "END OF JSON PARSING" << endl;
}

pair<Vertex, int> BFS::parse(string input) {
    string delimiter = ",";
    pair<Vertex, int> value;
    value.first = input.substr(0, input.find(delimiter));
    value.second = stoi(input.substr(input.find(delimiter) + 1));    
    return value;
}

vector<Vertex> BFS::traversal(Vertex start) {
    vector<Vertex> ret;
    queue<Vertex> q;
    
    is_visited_[start] = true;
    q.push(start);

    while(!q.empty()) {
        start = q.front();
        ret.push_back(start);
        q.pop();
        vector<Vertex> its_neighbor = g_.getAdjacent(start);
        for(int i = 0; i < (int)its_neighbor.size(); i++) {
            if (!is_visited_[its_neighbor[i]]) {
                is_visited_[its_neighbor[i]] = true;
                q.push(its_neighbor[i]);
            }
        }
    }
    return ret; 
}

vector<vector<Vertex>> BFS::connectedComp() {
    vector<Vertex> vertices = g_.getVertices();
    vector<vector<Vertex>> result;

    for(int i = 0; i < (int)vertices.size(); i++) {
        if (!is_visited_[vertices[i]]) {
            result.push_back(traversal(vertices[i]));
        }
    }
    
    return result; 
}

int BFS::numNodes() {
    return numVertices;
}





