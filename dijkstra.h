#pragma once

#include "graph.h"
#include "edge.h"
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;
typedef pair<int, Vertex> pair_; 
class Dijkstra {
    public:
        Dijkstra();
        Dijkstra(string node_filename, string neighbor_filename);
        vector<Vertex> find_shortest_path(Vertex start, Vertex end);
        vector<Vertex> backtrack(unordered_map<Vertex, Vertex> prev_vertex_, Vertex start, Vertex end);
        pair<Vertex, int> parse(string input);
    private:
        const static int INF;
        const static Vertex EMPTY_VERTEX;

        unordered_map<Vertex, bool> is_visited_;
        unordered_map<Vertex, bool> is_marked;
        unordered_map<Vertex, int> shortest_distance_from_start_;
        unordered_map<Vertex, Vertex> prev_vertex_;
        unordered_map<Vertex, int> target_map_;
        priority_queue<pair_, std::vector<pair_>, std::greater<pair_>> q2;
        Graph g_;
};
