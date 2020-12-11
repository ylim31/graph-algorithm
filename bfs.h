#pragma once

#include "cs225/graph.h"
#include "cs225/edge.h"
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

/**
 * BFS class. Breadth First Search traversal is an algorithm, which is used to visit all of the nodes of a given graph.
 */
class BFS {
    public:
        /**
         * Standard Constructor.
         */
        BFS();

        /**
         * Builds vectors for BFS to work on from json file.
         * @param json_filename The nodes and its neighbor in json format.
         */
        BFS(string node_filename);

        /**
         * Given the starting vertex, traverses through the given graph.
         * @param start The start vertex.
         * @return A vector of vertex that is the path taken for the BFS traversal.
         */
        vector<Vertex> traversal(Vertex start);

        /**
         * Traverses through the entire graph, irrespective of if they are connected or not. 
         * @return A vector of vertex that is the path taken for the BFS traversal.
         */
        vector<vector<Vertex>> connectedComp();

        /**
         * Calculated the number of nodes of the graph. 
         * @return The number of nodes of the graph.
         */
        int numNodes();

    private:
        // A map to check if a particular node is visited or not.
        unordered_map<Vertex, bool> is_visited_;

        // The number of nodes.
        int numVertices;

        // The entire graph.
        Graph g_;
};