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
#include <math.h> 
#include "cs225/graph.h"
#include "include/json.hpp"


using namespace std;
using json = nlohmann::json;

const int Dijkstra::INF = 9999;
const Vertex Dijkstra::EMPTY_VERTEX = to_string(-1);
Dijkstra::Dijkstra() : g_(true, false) {}
Dijkstra::Dijkstra(string json_filename, string target_filename) : g_(true, false) {
    ifstream lastfm_target_file;
    
    lastfm_target_file.open(target_filename);
    while (lastfm_target_file.good()) {
        string line;
        getline(lastfm_target_file, line);
        //cout << line << endl;
        pair<Vertex, int> target = parse(line);
        auto lookup = target_map_.find(target.first);
        if (lookup == target_map_.end()) {
            target_map_[target.first] = target.second;
        }
        
        //cout << target.first << target.second << endl;
        
    }
    lastfm_target_file.close();
    //cout<<"work"<<endl;
    
    ifstream json_(json_filename);
    json j = json::parse(json_);
    for (auto &it : j.items()) {

        //cout<< "node: " <<it.key()<<endl;         

        //g_.insertVertex(it.key());
        for (auto &itr : it.value().items()) {
            
            //cout<<"work"<<endl;
            g_.insertEdge(it.key(), to_string(itr.value()));
            int weight = get_pythagorean_distance(get_coord(target_map_[it.key()]), get_coord(target_map_[to_string(itr.value())]));
            g_.setEdgeWeight(it.key(), to_string(itr.value()), weight);
            auto lookup = is_visited_.find(to_string(itr.value()));
            if (lookup == is_visited_.end()) {
                is_visited_[to_string(itr.value())] = false;
                shortest_distance_from_start_[to_string(itr.value())] = INF;
                prev_vertex_[to_string(itr.value())] = EMPTY_VERTEX;
                is_marked[to_string(itr.value())] = false;
            }  
        }
        auto lookup = is_visited_.find(it.key());
        if (lookup == is_visited_.end()) {
            is_visited_[it.key()] = false;
            shortest_distance_from_start_[it.key()] = INF;
            prev_vertex_[it.key()] = EMPTY_VERTEX;
            is_marked[it.key()] = false;
        }    
    }
    //g_.print();
    cout << "END OF JSON PARSING" << endl;
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
    value.second = stoi(input.substr(input.find(delimiter) + 1));

    
    return value;

}

int Dijkstra::get_pythagorean_distance(pair<int, int> coord_a, pair<int, int> coord_b) {
    int a = coord_a.first - coord_b.first;
    int b = coord_a.second - coord_b.second;
    int result = ceil(sqrt((a * a) + (b * b)));
    return result;
}

pair<int, int> Dijkstra::get_coord(int input) {
    pair<int, int> value;
    value.first = (input % 5) * 2;
    value.second = (input/5) * 2;
    return value;
}

void Dijkstra::clear(){
    for(unordered_map<Vertex,Vertex>::iterator it = prev_vertex_.begin();it!=prev_vertex_.end(); it++){
        prev_vertex_[it->first] = EMPTY_VERTEX;
    }
    for(unordered_map<Vertex,bool>::iterator it = is_visited_.begin();it!=is_visited_.end(); it++){
        is_visited_[it->first] = false;
        is_marked[it->first] = false;
    }
    for(unordered_map<Vertex,int>::iterator it = shortest_distance_from_start_.begin(); it!=shortest_distance_from_start_.end(); it++){
        shortest_distance_from_start_[it->first] = INF;
    }
}
