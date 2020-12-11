# jaehyuk3-devjw2-nda6-ylim31

# CS 225 Final Project: BFS, Dijkstra, and LandMark
## Team Members: Nishita Amberkar, Dev Wadhwa, Jae Lee, Josh Lim

## Dataset
*You can check out and download the dataset at https://snap.stanford.edu/data/feather-lastfm-social.html*

We used the LastFM dataset where nodes are LastFM users and edges are mutual follower relationships between them. From the dataset, we used their lastfm_asia_features.json file to set the node and its neighbors. We had to process our data to create the edge weights using the lastfm_asia_target.csv file. How we process them can be found in out presentation video.


When creating your own json and target (csv) files, you must create following this format:


| Type | Format  |
| ---- | --------- |
| .json|<pre lang="json">{<br>  "0": [1, 2]<br>}</pre>|
| .csv | 0, 1|

You can see some example json and target files we created in the `test_folder\` and `BFS-tests\` folders. We wrote many test cases in the `tests\` folder where we use the files.

## RUN
To run the algorithms, you can compile the executable by linking your code using the following command: 

```make ```

You can run it in this format: 

```./main [algorithm name] [path file to json] [path file to target file]```

| Algorithm Name |
| ---- |
| Dijkstra |
|LandMark|
|BFS|

Then you will be prompt to enter an input depending on the algorithm you called.

To run the test cases, you can compile the executable by linking your code using the following command: 

```make test ```

You can run it in this format:

```./test```

#### Note: While the algorithm works very fast on small graphs, for large datasets, such as LastFM, it will take longer. Parsing through large json takes ~30 seconds and finding the shortest path using Dijkstra takes another ~10 seconds. For LandMarks, which is loops of Dijkstra, it will take even longer but it works!

## External Libraries
- https://github.com/nlohmann/json Third party library that iterate and parse json.
- `graph.cpp/h` Graph implementation from CS 255.