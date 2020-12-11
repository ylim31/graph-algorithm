#include <iostream>
#include <fstream>
#include "cs225/PNG.h"
#include "cs225/graph.h"
#include "dijkstra.h"
#include "landmark.h"
#include "bfs.h"
#include <string.h>

using namespace std;
int main(int argc, char* argv[]){
   
    vector<Vertex> result;
    string start;
    string end;
    string each_landmark;
    vector<Vertex> landmark;
    if (strcmp(argv[1], "Dijkstra") == 0) {
        Dijkstra d_(argv[2], argv[3]);
        cout << "Enter start and end vertex: " << endl;
        cin >> start;
        cin >> end;
        result = d_.find_shortest_path(start, end);
        if (result.empty()) {
            cout << "You entered an invalid vertex ";
            return 0;
        }
        cout << "Shortest path from " + start + " to " + end + " is: < ";
        for (unsigned i = 0; i < result.size(); i++) {
            cout << result[i] + " ";
        } 
        cout << ">";
        return 0;
    } else if (strcmp(argv[1], "LandMark") == 0) {
        LandMark l_(argv[2], argv[3]);
        cout << "Enter start and end vertex: " << endl;
        cin >> start;
        cin >> end;
        cout << "Enter landmark vertices (type STOP to end): " << endl;
        while (cin >> each_landmark && each_landmark != "STOP") {
            landmark.push_back(each_landmark);
        }
        result = l_.find_shortest_path(start, end, landmark);
        if (result.empty()) {
            cout << "You entered an invalid vertex ";
            return 0;
        }
        cout << "Shortest path from " + start + " to " + end + " while visiting : ";
        for (unsigned i = 0; i < landmark.size(); i++) {
            cout << landmark[i] + " ";
        }
        cout<<"is: < ";
        for (unsigned i = 0; i < result.size(); i++) {
            cout << result[i] + " ";
        } 
        cout << ">";
        return 0;
    } else if (strcmp(argv[1], "BFS") == 0) {
        BFS b_(argv[2]);
        cout << "Enter start vertex: " << endl;
        cin >> start;
        result = b_.traversal(start);
        if (result.empty()) {
            cout << "You entered an invalid vertex ";
            return 0;
        }
        cout << "Traverse order: < ";
        for (unsigned i = 0; i < result.size(); i++) {
            cout << result[i] + " ";
        } 
        cout << ">";
    }
    return 0;
}