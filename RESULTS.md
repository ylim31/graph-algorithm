# Results

---
#### A one- to two-page final report describing the outcome of your project, including any discoveries made. Figures should be in the same directory (if using MDs) or the same file (if using PDFs) but are not included in the page limit.
# Results
BFS (Traversal)

Dijkstra's Algorithm

Land Mark Implementation
The Landmark implementation aims to find the shortest path between two nodes under one condition. It has to visited specified nodes during its journey. As we have already implemented Dijkstra's alogorithm, it was natural to use our Dijkstra's algorithm within our landmark implementation. In simple terms, we use two vectors: one that includes the landmark nodes and one that will return the final path. We iterated through the landmarks in the first vector applying Dijkstra's algorithm every interval we needed to satisfy. Compared to our manual calculations for smaller scaled tests, our landmark algorithm has returned our expected results for every test. One important discovery we have made is the permutation of the landmarks vector. For example, if we gave a landmarks vector of <1,2,3>. Due to the fact we iterate through this vector in order, the algorithm assumes we have to visit 1, 2, 3, in that specific order. However, this is not the case. So, we run this enitre algorithm on every possible permutation of this vector, checking <1,3,2> <2,1,3> <2,3,1> <3,1,2> <3,2,1>. Thus, the path with the smallest total edge weight is the path we return. Overall, the Land Mark implementation was a success.

