#pragma once

#include "cs225/graph.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;
typedef pair<int, Vertex> pair_;

/**
 * Dijkstra class. Dijkstra algorithm of an adjacency list implemented graph using priority queue.
 */
class Dijkstra {
    public:
        /**
         * Standard Constructor.
         */
        Dijkstra();

        /**
         * Builds Dijkstra from json file and target file.
         * @param json_filename The nodes and its neighbor in json format.
         * @param target_filename The nodes and its target to process their edge weights.
         */
        Dijkstra(string json_filename, string target_filename);

        /**
         * Finds the shortest path between two nodes by finding the shortest distance from the
         * start to every other nodes in the graph.
         * @param start The start vertex.
         * @param end The end vertex.
         * @return A vector of vertex that is the shortest path from start to end.
         */
        vector<Vertex> find_shortest_path(Vertex start, Vertex end);
        
        /**
         * Set all values in prev_vertex_, is_visited_, is_marked, and shortest_distance_from_start_ to default.
         */ 
        void clear();

        /**
         * Adds all the edge weights of the path.
         * @return The total cost to travel that path
         */ 
        int get_total_cost(vector<Vertex> path);
    private:
        /**
         * Backtrack through the prev_vertex_ to from end to start to return the shortest path.
         * @param start The start vertex.
         * @param end The end vertex.
         * @return A vector of vertex that is the shortest path from start to end.
         */ 
        vector<Vertex> backtrack(Vertex start, Vertex end);

        /**
         * Split each input on the comma. Used to parse each line of the target file.
         * @param input The string to be parsed.
         * @return A pair of vector and int.
         */
        pair<Vertex, int> parse(string input);

        /**
         * Convert the integer input into a point in the coordinate graph. This coordinate graph
         * has a width of 5 and any integer greater will be on higher y axis.
         * @param input The integer that will be mapped.
         * @return An ordered pair of ints that respresents a point in the coordinate graph.
         */
        pair<int, int> get_coord(int input);

        /**
         * Solves and gets the distance between two points.
         * @param coord_a The first point.
         * @param coord_b The second point.
         * @return The int distance between coord_a and coord_b.
         */
        int get_pythagorean_distance(pair<int, int> coord_a, pair<int, int> coord_b);

        const static int INF;
        const static Vertex EMPTY_VERTEX;
        unordered_map<Vertex, bool> is_visited_;
        unordered_map<Vertex, bool> is_marked;
        unordered_map<Vertex, int> shortest_distance_from_start_;
        unordered_map<Vertex, Vertex> prev_vertex_;
        unordered_map<Vertex, int> target_map_;
        priority_queue<pair_, std::vector<pair_>, std::greater<pair_>> queue;
        Graph g_;
};
