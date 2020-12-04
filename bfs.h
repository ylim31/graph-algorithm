#pragma once

#include "graph.h"
#include "edge.h"
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

class BFS {
    public:
        BFS();
        BFS(string node_filename, string neighbor_filename);
        void traversal(Vertex start);
    private:
        unordered_map<Vertex, bool> is_visited_;
        int numVertices_;
        Graph g_;
};