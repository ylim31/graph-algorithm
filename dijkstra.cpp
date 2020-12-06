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
#include "graph.h"


using namespace std;

const int Dijkstra::INF = 9999;
const int Dijkstra::EMPTY_VERTEX = -1;
Dijkstra::Dijkstra() : g_(true, false) {}
Dijkstra::Dijkstra(string node_filename, string neighbor_filename) : g_(true, false) {


    ifstream lastfm_file;
    //lastfm_file.open("lastfm_node.csv");
    ifstream lastfm_neighbor_file;
    //lastfm_neighbor_file.open("lastfm_neighbor.csv");
    //adjacencent list
  
    //lastfm_file.open("test.csv");
    //lastfm_neighbor_file.open("test_neighbor.csv");

    lastfm_file.open(node_filename);
    lastfm_neighbor_file.open(neighbor_filename);

    while (lastfm_file.good()) {
        string node_label;
        getline(lastfm_file, node_label, ',');
        g_.insertVertex(node_label);

        auto lookup = is_visited_.find(node_label);
        if (lookup == is_visited_.end()) {
            is_visited_[node_label] = false;
            shortest_distance_from_start_[node_label] = INF;
            prev_vertex_[node_label] = EMPTY_VERTEX;
        }  
        
    }
    lastfm_file.close();
    /*
    for (int i = 0; i <= 7830; i++) {
        auto lookup = is_visited_.find(to_string(i));
        if (lookup == is_visited_.end()) {
            is_visited_[to_string(i)] = false;
            shortest_distance_from_start_[to_string(i)] = INF;
            prev_vertex_[to_string(i)] = EMPTY_VERTEX;
        }  
    }
    */
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
            }  

            g_.insertEdge(to_string(i), piece);
            g_.setEdgeWeight(to_string(i), piece, 1);
            piece = strtok(NULL, ", \" []");      
        }
        i++;
    }
    lastfm_neighbor_file.close();
    /*
    g_.setEdgeWeight(to_string(0), to_string(1), 6);
    g_.setEdgeWeight(to_string(0), to_string(3), 1);
    g_.setEdgeWeight(to_string(1), to_string(3), 2);
    g_.setEdgeWeight(to_string(1), to_string(4), 2);
    g_.setEdgeWeight(to_string(1), to_string(2), 5);
    g_.setEdgeWeight(to_string(2), to_string(4), 5);
    g_.setEdgeWeight(to_string(4), to_string(3), 1);
    */
}

vector<Vertex> Dijkstra::find_shortest_path(Vertex start, Vertex end) {
    if (start == end) {
        return vector<Vertex>();
    }
    shortest_distance_from_start_[start] = 0;
    bool should_break = false;
    Vertex current_vertex = start;
    int j = 0;
    while (should_break == false) {
        j++;
        vector<Vertex> its_neighbor = g_.getAdjacent(current_vertex);
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(its_neighbor.begin(), its_neighbor.end(), std::default_random_engine(seed));
        for (unsigned i = 0; i < its_neighbor.size(); i++) {
            //cout << j << endl;
            
            
            if (is_visited_[its_neighbor[i]] == false) {
                
                int distance = shortest_distance_from_start_[current_vertex] + g_.getEdgeWeight(current_vertex, its_neighbor[i]);
                
                if (distance < shortest_distance_from_start_[its_neighbor[i]]) {
                    shortest_distance_from_start_[its_neighbor[i]] = distance;
                    
                    prev_vertex_[its_neighbor[i]] = current_vertex;
                    if (its_neighbor[i] == end) {
                        
                        should_break = true;
                        break;
                    }
                }
            }
        }
 
        is_visited_[current_vertex] = true;
        Vertex shortest_vertex = get_shortest_distance(its_neighbor);
        if (shortest_vertex == start) {
            return vector<Vertex>();
        }
        if (j < 50) {
            cout << "SHORTEST V: " << shortest_vertex << endl;
        }
        
        current_vertex = shortest_vertex;
    }
    //cout << "WORK" << endl;
    return backtrack(prev_vertex_, start, end);
}

vector<Vertex> Dijkstra::backtrack(unordered_map<Vertex, Vertex> prev_vertex_, Vertex start, Vertex end) {
    vector<Vertex> shortest_path;
    
    shortest_path.push_back(end);
    Vertex curr = end;
    

    unordered_map<Vertex, Vertex>::iterator it;
    for ( it = prev_vertex_.begin(); it != prev_vertex_.end(); it++ )
    {
        std::cout << it->first  // string (key)
                << ':'
                << it->second   // string's value 
                << std::endl ;
    }
    cout << "start: " << start << endl;
    cout << "end: " << end << endl;
    cout << "prev_vertex[322]: " << prev_vertex_[to_string(322)] << endl;
    cout << "prev_vertex[7830]: " << prev_vertex_[to_string(7830)] << endl;

    while (curr != start) {
        
        curr = prev_vertex_[curr];
        shortest_path.push_back(curr);

    }
    std::reverse(shortest_path.begin(), shortest_path.end());
    return shortest_path;

}

Vertex Dijkstra::get_shortest_distance(vector<Vertex> neighbor) {
    Vertex min_vertex = neighbor[0];
    int min_dist = shortest_distance_from_start_[neighbor[0]];
    for (unsigned i = 0; i < neighbor.size(); i++) {
        if (is_visited_[neighbor[i]] == false) {
            min_vertex = neighbor[i];
            min_dist = shortest_distance_from_start_[neighbor[i]];
            break;
        }
    }
    
    for (unsigned i = 0; i < neighbor.size(); i++) {
        if (is_visited_[neighbor[i]] == false) {
            if (min_dist > shortest_distance_from_start_[neighbor[i]]) {
            min_dist = shortest_distance_from_start_[neighbor[i]];
            min_vertex = neighbor[i];
            }
        }
    }
    return min_vertex;
}

