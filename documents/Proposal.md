# Project Proposal

## Leading Question

We love California! As a result, we want to create a tool that helps travelers navigate through the state. Given a dataset, our code base will be able to guide its users in several aspects:

1. **GPS**: Upon receiving starting coordinates and the location the user wishes to arrive at, the code base will return the shortest path between the two locations, along with a list of places along the way. This will be achieved via the Floyd-Warshall algorithm, which finds the shortest paths in a directed weighted graph. The nodes of our graph will be the coordinates, the edges the roads, and the weights the lengths of the roads.

2. **The Complete California Experience**: Do you love California even more than we do and want to visit as many attractions as possible with as little effort as possible? Using Tarjan’s strongly connected components algorithm, which utilizes depth first search (our traversal of choice for this project), the code base will return the largest strongly connected components within California. Each strongly connected component represents a cluster of attractions where every attraction is directly accessible (meaning you only have to use a single road) to every other attraction in the cluster.

3. **If time allows: Nearest Attractions:** Want to find the nearest parks? Nearest trails? Nearest hospitals? Given the user’s current locations, category of interest (e.g. park, trail, hospital), and a number k representing the number of search results desired, our code base will return the k closest places in the desired category. We’ll achieve this by building a 2-d tree similar to the one used in MP Mosaics and implementing the k-nearest neighbors algorithm.

## Data Acquisition and Processing

We will be using: [California Road Network and Points of Interest Dataset](https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm)

### Data Format

Our input dataset consists of three files obtained from the University of Utah’s CS department. The first file contains a list of California road network nodes, with each line containing the node’s ID, its longitude, and its latitude. The second file describes the graph’s roads, which act as edges; each line of the file contains an edge’s ID, the IDs of the edge’s start and end nodes, and the distance of the road. The final file contains a list of attractions, where each attraction is categorized (e.g. school, arch, etc.) and has a corresponding longitude and latitude.

The first two files are under 600 KB large, and the third is 2670 KB large. In order to best achieve our purposes of providing a comprehensive guide to California’s road networks, we’ll be using the entire dataset.

### Data Correction

When building our graph, we’ll implement various checks that fix any existing errors. The first check will confirm that the latitudes and longitudes make sense. If any of the numbers are outside of their possible range, we’ll increase or decrease the number to the closest number that’s possible. Any edges with start and/or end node IDs that don’t exist will be ignored (this will be trivial to check because node IDs are numbered from 0 to 21047), and any repeat longitudes and latitudes that are categorized differently will also be ignored.

### Data Storage

Our “GPS” and “Complete California Experience” functionalities both require a graph where nodes are obtained from the first file and edges are road networks obtained from the second file. We’ll represent this graph using an adjacency list; index i of the list is node ID i, and an index j in the corresponding list means there’s an edge between nodes i and j. The space complexity for this is O(number of edges + number of nodes) storage. We’ll also have an additional linked list where the indices correspond to node IDs and the values are the node’s longitudes and latitudes. The space complexity for this second list is O(number of nodes).

If time allows, we’ll also implement “Nearest Attractions.” This functionality will need us to build a k-d tree, as will our “GPS” functionality if the user’s current coordinates don’t exist in our dataset. The space complexity for this tree is O(number of nodes). Incidentally, our estimate of the total storage costs for our dataset is O(number of edges + number of nodes) + O(number of nodes) + O(number of nodes), which is approximately O(number of edges + number of nodes).

## Graph Algorithms

### Function Inputs

Our project will utilize the Floyd-Warshall to calculate the smallest distance between longitude and latitude points. Since our dataset already separates information about the nodes and edges into two files, we can use these files as inputs to build our graph into an adjacency list. The longitudes and latitudes will be another input and can also be easily used to calculate distances between points. Furthermore, for the second part of our project—returning the largest strongly connected components within California—we’ll be using Tarjan’s strongly connected components algorithm. We expect the inputs to be the same as the ones for the Floyd-Warshall algorithm, as we’ll be using the same graph to conduct our traversals.

If time allows, for the “Nearest Attractions” part of our project, we will create our own Node class, convert the dataset into Node objects, and construct a K-D tree. We will then use the find k-nearest neighbors algorithm (introduced in MP Mosaics) to return the closest point of interest.

### Function Outputs

The expected output for the Floyd-Warshall algorithm would be the shortest distance between two points using only the roads provided. We will store all the roads taken to achieve this distance and visualize the output by printing out the list of roads. Similarly, the expected output for Tarjan’s strongly connected components is a list of nodes corresponding to the strongly connected components. If time allows, the output for the K-d tree find nearest neighbor algorithm would be the nearest Node objects that match the user’s specifications (ex: nearest park). We will print out the information about this Node, such as latitude, longitude, and name. If we have time, we will render the necessary roads as an image.

### Function Efficiency

The target Big O efficiency for our implementation of the Floyd-Warshall algorithm is $O(n^3)$, where $n$ is the number of vertices in our dataset. The target Big O efficiency of Tarjan’s strongly connected components, meanwhile, is $O(E + V)$, where $E$ is the number of edges and V the number of vertices. The target Big O efficiency for our implementation of the K-D tree find nearest neighbor algorithm is $O(log n)$.

## Timeline

#### Week 1 (Mar 28th)

1. Set up `node` class
2. Construct adjacency list for NLL
3. Set up small-sized test dataset

#### Week 2 (Apr 4th)

1. Implement finding shortest path with Floyd-Warshall Algorithm
2. Test cases for adjacency list and shortest path

#### Week 3 (Apr 11th)

Note: Mid-Project Check In (Apr 15th)

1. Construct K-D tree for NLL
2. Implement K-D Tree DFS Search for mapping user input

#### Week 4 (Apr 18th)

1. Finish Tarjan’s Strongly Connected Components
2. Test cases for K-D Tree DFS ans Tarjan's algorithm

#### Week 5 (Apr 25th)

1. Finish any lingering parts
2. If time permits, graphically render the results

#### Week 6 (May 6th)

Note: Final Deliverables (May 6th)

1. Code and documentation clean-up
2. Final Deliverables Production: Presentation and Report
