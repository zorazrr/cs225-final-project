# Development Log

## Week 1

This week, our goals were to implement the Node class, construct the adjacency list for the Node Latitude Longitude (NLL) dataset, and set up a small test dataset. We accomplished all of these tasks this week.

Ellie: This week, something unfortunate happened in my personal life and I wasn’t feeling emotionally or physically well enough to complete my class work, which I notified my group members of. However, I will try my best to be fully back on track next week.

Grace: I worked with Zora to figure out the structure of the Node class and extracted a small subset of data for us to use with testing. I also implemented our Graph class’s constructor and the helper functions necessary for us to use our data to create a graph.

Zora: I set up the repo structure, including file storage, classes, and basic test and make files, with Grace. We determined the private members within each class and created general necessary functions like getters and setters. 

Thankfully, everything went relatively smoothly, and we were able to meet all of our goals. The biggest challenge was deciding on how exactly we would create our graph, but after discussing the issue amongst ourselves, we were able to successfully implement the constructor and helper function. 

Next week, our exciting plan is to implement the finding shortest path functionality through the Floyd-Warshall Algorithm and set up test cases for it. We also want to set up test cases for our graph’s constructor, to see if it creates the desired adjacency list from our input files successfully.

## Week 2
This week, our goals were to complete the Node class (set up the .cpp file and include any further necessary helper functions), create the MakeFile, begin setting up tests for our functions, and implement the Floyd-Warshall Algorithm. We wanted to make sure our Graph class was working as expected before starting the Floyd-Warshall Algorithm, and to do that we needed to have our MakeFile working. However, because we ran into issues with our MakeFile, we weren’t able to run our test cases. 

Ellie: This week, I coded the entirety of the Node.cpp file and implemented two helper functions to calculate the distance between two latitude/longitude coordinate pairs.

Grace: I implemented road.cpp, created smaller test files, and wrote extensive test cases to test the functionality of our Graph class.

Zora: This week I worked on getting the Makefile working. I also fixed some small mistakes throughout the files now that we are able to compile and the compiler starts to complain about things.

Next week (now that our MakeFile has been set up), we’ll implement the Floyd-Warshall algorithm as well as the K-D tree.

## Week 3
This week, our goals were to construct the K-D tree class to work with our Node class and also to implement the DFS search within this K-D tree class. Furthermore, we decided to replace the Floyd-Warshall algorithm with Dijkstra’s algorithm because of its increased efficiency. It also better matches what we hope our function will return. Thus, we had an added task of implementing Dijkstra’s algorithm this week as well.

Ellie: I was able to debug the Graph class test cases that we made from last week and get them to all pass. I also implemented the entire K-D tree class and wrote thorough test cases for it.

Grace & Zora: We did pair programming to finish Dijkstra’s algorithm to look for the shortest path from one node to all other nodes. To accomplish it, we also created a NodePair class and integrated it with Min Heap Priority Queue in C++ STL library (so that the node with shortest distance is visited first). We also wrote test cases for Dijkstra’s algorithm. 

Next week, we aim to complete Tarjan’s Strongly Connected Components as well as its test cases. 

## Week 4 
This week, our goals were to finish the BFS algorithm for our graph class (instead of DFS) and implement the Welsh Powell graph coloring algorithm instead of Tarjan’s Strongly Connected Components, since we found that Tarjan’s wouldn’t work for an undirected graph. 

Ellie: I implemented the BFS algorithm in the Graph class. Given a starting node, the algorithm prints out the BFS traversal as it goes. We decided to implement BFS so that it would represent a “strange traveler”; instead of wanting the shortest path by distance, someone might want the shortest path by number of roads taken. Perhaps it’s more scenic that way.

Zora & Grace: After realizing Tarjan’s Strongly Connected Components Algorithm only works for directed graphs, we spent some time picking a new algorithm. Then we did pair programming to complete the Welsh Powell Algorithm for Graph Colorability. We also tested the algorithm on a small dataset. 

Next week, we plan to tie up any loose ends and lingering parts. If time permits, we will also work on graphically rendering the results.

