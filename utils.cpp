#include "utils.h"
#include "calipng.h"

/**
 * Welcomes users to the program, generates the graph, calls the selection 
 * method
 **/
void welcome() {
  std::cout << "Hello, traveler! Welcome to the Complete California Experience~" << std::endl;
  std::cout << "Note that routes are based on "
      "data from 2005, so unless you have traveled back in time to secure this amazing piece of technology, the "
      "output may not be completely of use to you. But. Either way, we hope you have an incredible time here!" << std::endl;
  
  Graph graph;
  graph.makeGraph("data/nodes.txt", "data/roads.txt");
  select(graph);
}

/**
 * The main selection screen; gives users the ability to select which
 * algorithm to call
 * @param graph graph representation of the dataset
 **/
void select(Graph& graph) {
  std::cout << "-----------------------" << std::endl;
  std::cout << "The Complete California Experience offers three components: 1) GPS, 2) Sporadic Tour, 3) Nearest Attractions, 4) Lazy Tour." << std::endl;
  std::cout << "Enter the number corresponding to the component you're interested in, or enter '0' to exit." << std::endl;
  std::cout << "Remember that at any point the text box appears, you may enter '-1' to return to this selection page." << std::endl;

  int res;
  std::cin >> res;
  switch(res) {
    case 0:
      std::cout << "Enjoy your stay! If you're ever bored (which couldn't possibly be the case in California), remember "
        "that I'm here to give you a sense of false companionship!" << std::endl;
      return;
    case 1:
      gps(graph);
      break;
    case 2: 
      tour(graph);
      break;
    case 3:
      nearestAttractions(graph);
      break;
    case 4: 
      bfs(graph);
      break;
    default:
      select(graph);
  }
}

/**
 * Asks the user for two coordinates: starting point & destination point. 
 * Uses k-nearest neighbors to find the closest nodes to each coordinate, then
 * executes Dijkstra's to output the shortest path between the two nodes
 * @param graph graph representation of the dataset
 **/
void gps(Graph& graph) {
  std::cout << "-----------------------" << std::endl;
  std::cout << "Welcome to the most accurate, most trustworthy, and least outdated GPS you'll ever use!" << std::endl;
  std::cout << "(Node number ranges from 0 to 21047)" << std::endl;
  std::cout << "Enter the node you're starting at: ";

  int start;
  std::cin >> start;
  if (start == -1) {
      select(graph);
      return;
  }

  std::cout << "Enter the node you'd like to end at: ";
  int end;
  std::cin >> end;
  if (end == -1) {
      select(graph);
      return;
  }

  Dijkstra d(graph, start);
  d.printOnePath(end);
  drawShortestPath(graph, d, end);
  std::cout << "Have a fun time getting there :)" << std::endl;
  std::cout << "We printed out a path outline for you, check your folder for californiaShortestPath.png!" << std::endl;
  select(graph);
}

/**
 * Executes the Welsh-Powell algorithm. Asks the user to select a color 
 * (representing a unique sampling of places in California to visit), then
 * outputs all of the nodes corresponding to that color.
 * @param graph graph representation of the dataset
 **/
void tour(Graph& graph) {
  std::cout << "-----------------------" << std::endl;
  std::cout << "Want a good sampling of places in California to visit? You're in luck!" << std::endl;
  std::cout << "This highly-rated (by yours truly), all-encompassing tour will provide you with a thorough selection"
    " of landmarks in California to visit, excluding places that are too similar to each other." << std::endl;
  std::cout << "Enter the magic number '1' to view the number of unique tours you can select from :): ";
  
  int input;
  std::cin >> input;
  if (input != 1) {
    select(graph);
    return;
  }

  std::cout << "Loading... this can take up to 5 minutes. Maybe check out the scenery around you?" << std::endl;
  Welsh welsh(graph);
  welsh.printMaxColors();

  std::cout << "Enter a number from 1 to " << welsh.getMaxColors() << " corresponding to the tour you'd like to view. ";
  int color;
  std::cin >> color;
  if (color < 1 || color > welsh.getMaxColors()) {
    select(graph);
    return;
  }

  vector<int> colors = welsh.getColors();
  for (int i = 0; i < graph.getNumNodes(); ++i) {
    if (colors.at(i) == (color - 1)) {
      std::cout << graph.getNodes().at(i)->getId() << ", ";
    }
  }
  std::cout << "\n";
  std::cout << "Enjoy the tour, and don't get lost!" << std::endl;
  std::cout << "(But don't worry if you get lost, since I come with a handy GPS configured just for you :)" << std::endl;

  select(graph);
}

/**
 * Aks users for their current coordinates, then outputs the coordinates of the 
 * closest attraction (node) to those coordinates by using the k-nearest 
 * neighbors algorithm.
 * @param graph graph representation of the dataset
 **/
void nearestAttractions(Graph& graph) {
  std::cout << "-----------------------" << std::endl;
  std::cout << "Want to visit an attraction but too lazy to go somewhere far? My Nearest Attractions feature is just for you!" << std::endl;
  std::cout << "Simply enter in your current coordinates, and I'll find you the closest attraction to where you are!" << std::endl;
  std::cout << "Enter your current coordinates in the format [latitude] [longitude] (without brackets): ";
  double latitude;
  double longitude;

  try {
    std::cin >> latitude >> longitude;
    // Longitude ranges from -114.294 to -124.389 (10.095)
    // Latitude ranges from 32.5413 to 42.0172 (9.4759)
    if (longitude < -124.389343 || longitude > -114.294258 || latitude < 32.541302 || latitude > 42.017231) {
      std::cout << "Oh no hold up! You are going out of California!" << std::endl;
      std::cout << "The latitude of California goes from 32.541302 to 42.017231." << std::endl;
      std::cout << "The longitude of California goes from -124.389343 to -114.294258." << std::endl;
      std::cout << "Let's try it again:" << std::endl;
      nearestAttractions(graph);
    } else {
      Point<2> loc(latitude, longitude);
      KDTree<2> tree = getTree(graph);
      Point<2> nearest = tree.findNearestNeighbor(loc);

      std::cout << "The closest attraction to you is at coordinates " << nearest[0] << " " << nearest[1] << std::endl;
      std::cout << "I'm not sure exactly what it is, but that doesn't matter! Have fun!" << std::endl;
      select(graph);
    }
  } catch (const std::exception& e) {
    select(graph);
  }
}

/**
 * Gives the path to a weird traveler to travel the entirety of Clalifornia 
 * @param graph graph representation of the dataset
 **/
void bfs(Graph& graph) {
  std::cout << "-----------------------" << std::endl;
  std::cout << "Ok traveler, so you are lazy and want to only visit nearby connected scenic cluster! Now give me the node number you are currently at: " << std::endl;
  std::cout << "(Node number ranges from 0 to 21047)" << std::endl;
  int start;
  std::cin >> start;
  try {
    std::cout << "Follow through this path! It will take you through the current scenic cluster you are at!" << std::endl;
    graph.BFS(start);
    std::cout << "\n";
    select(graph);
  } catch (const std::exception& e) {
    select(graph);
  }
}

/**
 * Constructs and returns the k-d tree corresponding to the dataset
 * @param graph graph representation of the dataset
 * @return the k-dtree corresponding to the dataset
 **/
KDTree<2> getTree(Graph& graph) {
  vector<Point<2>> points;
  vector<Node*> nodes = graph.getNodes();

  for (Node* node : nodes) {
    Point<2> p(node->getLatitude(), node->getLongitude());
    points.push_back(p);
  }
  KDTree<2> tree(points);
  return tree;
}