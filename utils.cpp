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
  std::cout << "The Complete California Experience offers three components: 1) GPS, 2) Coloring Fun, and 3) Nearest Attractions." << std::endl;
  std::cout << "Enter the number corresponding to the component you're interested in, or enter '0' to exit." << std::endl;
  std::cout << "Remember that at any point the text box appears, you may enter '-1' to return to this selection page." << std::endl;

  int res;
  std::cin >> res;
  switch(res) {
    case 0:
      std::cout << "Enjoy your stay in California! If you're ever bored (which couldn't possibly be the case in California :), remember "
        "that I'm here to give you a sense of false companionship!" << std::endl;
      return;
    case 1:
      gps(graph);
      break;
    case 2: 
      coloring(graph);
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

void coloring(Graph& graph) {

}

void nearestAttractions(Graph& graph) {

}
