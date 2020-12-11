#include "dijkstra.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
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
        pair<Vertex, int> target = parse(line);
        auto lookup = target_map_.find(target.first);
        if (lookup == target_map_.end()) {
            target_map_[target.first] = target.second;
        }
    }
    lastfm_target_file.close();
    
    ifstream json_(json_filename);
    json j = json::parse(json_);
    for (auto &it : j.items()) {
        for (auto &itr : it.value().items()) {
            string each_neighbor = to_string(itr.value());
            each_neighbor.erase(remove(each_neighbor.begin(), each_neighbor.end(), '\"'), each_neighbor.end());
            g_.insertEdge(it.key(), each_neighbor);
            int weight = get_pythagorean_distance(get_coord(target_map_[it.key()]), get_coord(target_map_[each_neighbor]));
            g_.setEdgeWeight(it.key(), each_neighbor, weight);
            auto lookup = is_visited_.find(each_neighbor);
            if (lookup == is_visited_.end()) {
                is_visited_[each_neighbor] = false;
                shortest_distance_from_start_[each_neighbor] = INF;
                prev_vertex_[each_neighbor] = EMPTY_VERTEX;
                is_marked[each_neighbor] = false;
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
    //cout << "END OF JSON PARSING" << endl;
}


vector<Vertex> Dijkstra::find_shortest_path(Vertex start, Vertex end) {
    if (start == end) {
        vector<Vertex> v;
        v.push_back(start);
        return v;
    }
    auto lookup_start = is_visited_.find(start);
    auto lookup_end = is_visited_.find(end);
    if (lookup_start == is_visited_.end() || lookup_end == is_visited_.end()) {
        return vector<Vertex>();
    }
    shortest_distance_from_start_[start] = 0;
    Vertex current_vertex = start;

    queue.push(make_pair(0, start));
    while (!queue.empty()) {
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
                queue.push(make_pair(shortest_distance_from_start_[its_neighbor[i]], its_neighbor[i]));
            }
            is_marked[its_neighbor[i]] = true;
        }
        queue.pop();
        pair_ pair = queue.top();
        Vertex shortest_vertex = pair.second;
        current_vertex = shortest_vertex;
    }
    return backtrack(start, end);
}

vector<Vertex> Dijkstra::backtrack(Vertex start, Vertex end) {
    vector<Vertex> shortest_path;
    shortest_path.push_back(end);
    Vertex curr = end;
    Vertex lookup = prev_vertex_[end];
    if (lookup == EMPTY_VERTEX) {
        return vector<Vertex>(); 
    }
    /*
    unordered_map<Vertex, Vertex>::iterator it;
    for ( it = prev_vertex_.begin(); it != prev_vertex_.end(); it++ )
    {   
        std::cout << it->first  // string (key)
                << ':'
                << it->second   // string's value 
                << std::endl ;
                
    }
    */
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
    for (unordered_map<Vertex, Vertex>::iterator it = prev_vertex_.begin(); it != prev_vertex_.end(); it++ ) {
        prev_vertex_[it->first] = EMPTY_VERTEX;
        is_visited_[it->first] = false;
        is_marked[it->first] = false;
        shortest_distance_from_start_[it->first] = INF;
    }
}

int Dijkstra::get_total_cost(vector<Vertex> path) {
    int total = 0;
    for (unsigned i = 0; i < path.size() - 1; i++) {
        total += g_.getEdgeWeight(path[i], path[i + 1]);
    }

    return total;
}