#include "utils.h"

void welcome(Graph& graph) {
  std::cout << "Hello, traveler! Welcome to the Complete California Experience~" << std::endl;
  std::cout << "Note that routes are based on "
      "data from 2005, so unless you have traveled back in time to secure this amazing piece of technology, the "
      "output may not be completely of use to you. But. Either way, we hope you have an incredible time here!" << std::endl;
  select(graph);
}

void select(Graph& graph) {
  std::cout << "-----------------------" << std::endl;
  std::cout << "The Complete California Experience offers three components: 1) GPS, 2) Tour, and 3) Nearest Attractions." << std::endl;
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
    default:
      select(graph);
  }
}

void gps(Graph& graph) {
  std::cout << "Welcome to the most accurate, most trustworthy, and least outdated GPS you'll ever use!" << std::endl;
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
  std::cout << "Have a fun time getting there :)" << std::endl;
  select(graph);
}

void tour(Graph& graph) {
  std::cout << "Want a good sampling of places in California to visit? You're in luck!" << std::endl;
  std::cout << "This highly-rated (by yours truly), all-encompassing tour will provide you with a thorough selection"
    "of landmarks in California to visit, excluding places that are too similar to each other." << std::endl;
  std::cout << "Enter the magic number '1' to view the number of unique tours you can select from :): ";
  
  int input;
  std::cin >> input;

  if (input != 1) {
    select(graph);
    return;
  }
  Graph mediumGraph;
  mediumGraph.makeGraph("data/test_nodes.txt", "data/test_roads.txt");

  Welsh welsh(mediumGraph);
  welsh.printMaxColors();

  std::cout << "Enter a number from 1 to " << welsh.getMaxColors() << " corresponding to the tour you'd like to view. ";

  int color;
  std::cin >> color;

  if (color < 1 || color > welsh.getMaxColors()) {
    select(graph);
    return;
  }

  vector<int> colors = welsh.getColors();
  for (int i = 0; i < mediumGraph.getNumNodes(); ++i) {
    if (colors.at(i) == (color - 1)) {
      std::cout << mediumGraph.getNodes().at(i)->getId() << ", ";
    }
  }
  std::cout << "\n";
  std::cout << "Enjoy the tour, and don't get lost!" << std::endl;
  std::cout << "(But don't worry if you get lost, since I come with a handy GPS configured just for you :)" << std::endl;

  select(graph);

    // vector<int> colors = welsh.getColors();
    // for (auto color : colors) {
    //     std::cout << color << ", ";
    // }
    // std::cout << "\n";
    // welsh.printMaxColors();
}

void nearestAttractions(Graph& graph) {

}
