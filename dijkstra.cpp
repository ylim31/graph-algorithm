#include "dijkstra.h"
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <random>
#include <cmath>
#include "graph.h"


using namespace std;

const int Dijkstra::INF = 9999;
const Vertex Dijkstra::EMPTY_VERTEX = to_string(-1);
Dijkstra::Dijkstra() : g_(true, false) {}
Dijkstra::Dijkstra(string node_filename, string neighbor_filename) : g_(true, false) {
    vector<Vertex> vertex_list;

    ifstream lastfm_file;
    ifstream lastfm_neighbor_file;
    ifstream lastfm_target_file;
  

    lastfm_file.open(node_filename);
    lastfm_neighbor_file.open(neighbor_filename);

    lastfm_target_file.open("lastfm_asia_target.csv");

    while (lastfm_target_file.good()) {
        string line;
        getline(lastfm_target_file, line);
        pair<Vertex, int> target = parse(line);
        target_map_.insert(target);
        
    }
    lastfm_target_file.close();
    
    
    while (lastfm_file.good()) {
        string node_label;
        getline(lastfm_file, node_label, ',');
        g_.insertVertex(node_label);
        vertex_list.push_back(node_label);
        auto lookup = is_visited_.find(node_label);
        if (lookup == is_visited_.end()) {
            is_visited_[node_label] = false;
            shortest_distance_from_start_[node_label] = INF;
            prev_vertex_[node_label] = EMPTY_VERTEX;
            is_marked[node_label] = false;
        }  
        
        
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
            auto lookup = is_visited_.find(piece);
            if (lookup == is_visited_.end()) {
                is_visited_[piece] = false;
                shortest_distance_from_start_[piece] = INF;
                prev_vertex_[piece] = EMPTY_VERTEX;
                is_marked[piece] = false;
            }  
            g_.insertEdge(to_string(i), piece);
            g_.setEdgeWeight(to_string(i), piece, 1);
            //g_.insertEdge(vertex_list[i], piece);
            //g_.setEdgeWeight(vertex_list[i], piece, 1);
            piece = strtok(NULL, ", \" []");      
        }
        i++;
    }
    lastfm_neighbor_file.close();
    
   /*
   g_.setEdgeWeight(to_string(0), to_string(1), 2);
   g_.setEdgeWeight(to_string(0), to_string(2), 3);
   g_.setEdgeWeight(to_string(1), to_string(3), 16);
   g_.setEdgeWeight(to_string(3), to_string(5), 3);
   g_.setEdgeWeight(to_string(2), to_string(4), 2);
   g_.setEdgeWeight(to_string(4), to_string(5), 4);
   */
   
   
}

vector<Vertex> Dijkstra::find_shortest_path(Vertex start, Vertex end) {
    if (start == end) {
        return vector<Vertex>();
    }
    shortest_distance_from_start_[start] = 0;
    Vertex current_vertex = start;
    bool is_first = true;
    q2.push(make_pair(0, start));
    while (!q2.empty()) {
       
        vector<Vertex> its_neighbor = g_.getAdjacent(current_vertex);
        for (unsigned i = 0; i < its_neighbor.size(); i++) {
            if (is_visited_[its_neighbor[i]] == false) {
                int distance = shortest_distance_from_start_[current_vertex] + g_.getEdgeWeight(current_vertex, its_neighbor[i]);
                if (distance < shortest_distance_from_start_[its_neighbor[i]]) {
                    shortest_distance_from_start_[its_neighbor[i]] = distance;
                    prev_vertex_[its_neighbor[i]] = current_vertex;
                }
            }
        }

        is_visited_[current_vertex] = true;
        is_marked[current_vertex] = true;
        for (unsigned i = 0; i < its_neighbor.size(); i++) {
            if (is_marked[its_neighbor[i]] == false) {
                q2.push(make_pair(shortest_distance_from_start_[its_neighbor[i]], its_neighbor[i]));
            }
            is_marked[its_neighbor[i]] = true;
        }
        if (is_first) {
            q2.pop();
            is_first = false;
        }
        pair_ pair = q2.top();
        q2.pop();
 
        Vertex shortest_vertex = pair.second;
        current_vertex = shortest_vertex;
    }
    return backtrack(prev_vertex_, start, end);
}

vector<Vertex> Dijkstra::backtrack(unordered_map<Vertex, Vertex> prev_vertex_, Vertex start, Vertex end) {
    vector<Vertex> shortest_path;
    
    shortest_path.push_back(end);
    Vertex curr = end;
    
    Vertex lookup = prev_vertex_[end];
    if (lookup == EMPTY_VERTEX) {
        return vector<Vertex>(); 
    }

    unordered_map<Vertex, Vertex>::iterator it;
    for ( it = prev_vertex_.begin(); it != prev_vertex_.end(); it++ )
    {   
        std::cout << it->first  // string (key)
                << ':'
                << it->second   // string's value 
                << std::endl ;
                
    }
    while (curr != start) {
        curr = prev_vertex_[curr];
        shortest_path.push_back(curr);

    }
    std::reverse(shortest_path.begin(), shortest_path.end());
    return shortest_path;

}


pair<Vertex, int> Dijkstra::parse(string input) {
    string delimiter = ",";
    pair<Vertex, int> value;
    value.first = input.substr(0, input.find(delimiter));
    //value.second = stoi(input.substr(input.find(delimiter)));
    return value;

}
