# CS 225 Final Report
## Algorithm Overview
### Dijkstra’s
Our implementation of Dijkstra’s algorithm takes in two node IDs (of the destination and starting point) and outputs the shortest path, using roads, between them. The results of this algorithm are also graphically rendered on a map of California. Dijkstra’s algorithm was the main component behind the GPS functionality of our program, and it allowed us to identify the quickest way to get from one point in California to another. Our implementation uses a min heap priority queue and thus has a time complexity of O(V + Elog(V)), where V represents the number of vertices and E represents the number of edges.

To test Dijkstra’s algorithm, we wrote multiple test cases for smaller subsets of our dataset and required that the results of running the algorithm on the graph was the same as the expected result, which we calculated by hand. We also ensured that the algorithm could run on non-connected graphs.

![dijkstra](https://media.github-dev.cs.illinois.edu/user/14051/files/f6276fcc-c407-4fe4-8dbf-a1cd51bc5f6c)

### Welsh-Powell
Our Welsh-Powell algorithm takes in a graph and outputs the upper bound on the colors needed to color the given graph. Upon running it on our dataset of California, we discovered that the maximum number of colors needed is three. This finding is aligned with our expectations, as after looking at our rendering of California, we saw that the average number of degrees each node has is 1-2. On top of that, our dataset is divided into many different connected components, which would further minimize the number of colors needed.

To ensure that our algorithm is correct, we created tests using smaller datasets whose results we could manually confirm. Aside from testing general behavior, one of our tests also ensured that the algorithm works with disjointed data.

### K-Nearest Neighbors
Our K-D Tree K-Nearest Neighbors algorithm takes in the user’s current coordinates (latitude longitude format) and outputs the latitude and longitude coordinates of the nearest attraction, or node, to the user. We were able to do this by representing our points in a two-dimensional tree. This algorithm allowed us to implement the find nearest attraction functionality of our program, and we were even able to find the closest California attraction to some of our group members’ houses. The K-Nearest Neighbors algorithm runs at a time complexity of O(logn). 

We verified the results of this algorithm by writing various test cases for not only the K-Nearest Neighbors algorithm (in both 2D and 3D) but also smaller functions of K-D Trees, such as shouldReplace and smallerDimVal

### Breadth-First Search
Our breadth-first search algorithm takes in a starting node and outputs a sequence of nodes that can be accessed from that starting node in the order in which they would be accessed through a breadth-first search traversal. Because the graph representation of our dataset is made up of numerous small connected components, the output of the algorithm often only prints a small subset of the dataset.

We confirmed that the traversal is working as intended by adding test cases using smaller datasets whose results we can manually confirm. 

## Leading Question
By implementing the aforementioned algorithms, we were able to accomplish our leading goal of “creat[ing] a tool that helps travelers navigate through the dataset.” 

Dijkstra’s, for instance, provides travelers with a GPS that outputs the shortest path from one node (potentially their current location) to another. Travelers seeking a thorough sample of attractions in California without visiting overlapping attractions can use our Welsh-Powell algorithm to retrieve the number of unique samples as well as the attractions corresponding to a particular sample. At the same time, travelers can find the coordinates of the closest attraction to their current location (or any location in California) using our k-nearest neighbors algorithm. Breadth-first search, meanwhile, can be used to obtain a route travelers can use to visit all of the attractions in a particular region of California. The combination of these features creates a robust touring guide to our dataset that could translate to the real world (if it were 2005). 

One of the discoveries we made while implementing the project was that California’s road networks aren’t as densely connected as we believed them to be. Our Welsh-Powell algorithm indicates that three colors is enough to color the entire graph, and our breadth-first search traversal further supports this discovery by only being able to traverse through small connected components We also observed that the attractions in California tend to cluster together in dense groups instead of being evenly dispersed throughout the state.
