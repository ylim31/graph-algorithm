# Development

---
#### WEEK 1
- [x] Set up repository 
- [x] Write the Makefile
- [x] Get Dataset 
- [x] Add Contracts and Project Goals

#### We initiated all the fundamental files, such as Makefule, graph.cpp/h, edge.cpp/h, and our datasets. We got inspiration for these from past labs and mps! We also got the files for our chosen dataset and submitted supplementary files like contracts and potential goals.
---
#### WEEK 2
- [x] Implement Graph Library 
- [x] Finish Initializing Graphs

#### We finished initializing the graph, so implementing the graph.cpp/h and edge.cpp/h onto our lastfm dataset. We also divided BFS and Dijkstra among the four of us into two teams. For Dijkstra, we implemented a class that will to go through a csv file and created functions like find_shortest_path. 

---
#### WEEK 3
- [x] Implement code for BFS for normal graphs
- [x] Start implementing code for Dijkstra
- [x] Add basic tests for Dijkstra
- [x] Add basic tests for BFS

#### After completing the complete implimentation of Dijkstra algorithm, we created a baby csv file that copies an example from a video. We will use this as our exemplar and once we pass all necessary cases on the baby, we will start writing tests for the actual dataset. 

#### As for BFS, we implemented the basic algorithm. 
#### In line with the feeback we got from various posts on Piazza and the Discord server, ee then made a smaller representation of our dataset to test our BFS implimentation and to check our progress.
---
#### WEEK 4
- [x] Updated BFS to include Components
- [x] Start writing LandMark path
- [x] Add additional tests of different types of graphs for BFS
- [x] Change data structure from set to priority_queue for Dijkstra

#### For Dijkstra I realized that the Dijkstra was running very slow because I was using a set. Change to priority_queue.
#### After our midpoint check-in with Brad, we updated our BFS implimentation to make it more extendible i.e. so that it can work for Components as well. We then added tests for our BFS implimentation to make sure it is air-tight.
#### For LandMark, we thought of looping through Dijkstra to find the shortest path from landmark vertices.

---
#### WEEK 5 (FINAL)
- [x] Implement third party library that parse json
- [x] Finish LandMark path and add more tests
- [x] Fix edge cases for Dijkstra and BFS
- [x] Finish implementing BFS
- [x] Find a way to set edge weights using the target file
- [x] Finish README.md, RESULT.md, and DEVELOPMENT.md

#### We found a library that could parse json which was really helpful because our previous way of extracting data from the file was very messy. It also meant that the graph can take letters and symbols as nodes rather than just integers. Finish landmark and BFS and wrote more test cases for them. For setting the edge weights, we first converted the target id (from the target file) into a point in the coordinate graph. This coordinate graph has a width of 5 and any integer greater will be on higher y axis. After mapping the target ids, the distance between two points will be the edge weight between those nodes with that target id.