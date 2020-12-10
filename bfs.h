#pragma once

#include "cs225/graph.h"
#include "cs225/edge.h"
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

class BFS {
    public:
        BFS();
        BFS(string node_filename, string neighbor_filename);
        vector<Vertex> traversal(Vertex start);
    private:
        unordered_map<Vertex, bool> is_visited_;
        Graph g_;
};