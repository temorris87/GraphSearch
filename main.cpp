#include <iostream>
#include "Graph.h"

int main() {
    Graph * g = new Graph(15);

    g->add_edge(0, 1, 1);
    g->add_edge(0, 6, 1.41);
    g->add_edge(0, 5, 1);
    g->add_edge(1, 6, 1);
    g->add_edge(1, 5, 1.41);
    g->add_edge(1, 0, 1);
    g->add_edge(2, 3, 1);
    g->add_edge(2, 8, 1.41);
    g->add_edge(2, 7, 1);
    g->add_edge(2, 1, 1);
    g->add_edge(3, 2, 1);
    g->add_edge(3, 8, 1);
    g->add_edge(3, 4, 1);
    g->add_edge(3, 7, 1.41);
    g->add_edge(3, 9, 1.41);
    g->add_edge(4, 3, 1);
    g->add_edge(4, 9, 1);
    g->add_edge(4, 8, 1.41);
    g->add_edge(5, 0, 1);
    g->add_edge(5, 6, 1);
    g->add_edge(5, 10, 1);
    g->add_edge(5, 1, 1.41);
    g->add_edge(5, 11, 1.41);
    g->add_edge(6, 1, 1);
    g->add_edge(6, 5, 1);
    g->add_edge(6, 11, 1);
    g->add_edge(6, 7, 1);
    g->add_edge(6, 0, 1.41);
    g->add_edge(6, 10, 1.41);
    g->add_edge(6, 12, 1.41);
    g->add_edge(7, 2, 1);
    g->add_edge(7, 8, 1);
    g->add_edge(7, 12, 1);
    g->add_edge(7, 6, 1);
    g->add_edge(7, 3, 1.41);
    g->add_edge(7, 13, 1.41);
    g->add_edge(7, 11, 1.41);
    g->add_edge(8, 3, 1);
    g->add_edge(8, 7, 1);
    g->add_edge(8, 13, 1);
    g->add_edge(8, 9, 1);
    g->add_edge(8, 2, 1.41);
    g->add_edge(8, 4, 1.41);
    g->add_edge(8, 12, 1.41);
    g->add_edge(9, 4, 1);
    g->add_edge(9, 8, 1);
    g->add_edge(9, 3, 1.41);
    g->add_edge(10, 5, 1);
    g->add_edge(10, 11, 1);
    g->add_edge(10, 6, 1.41);
    g->add_edge(11, 10, 1);
    g->add_edge(11, 6, 1);
    g->add_edge(11, 12, 1);
    g->add_edge(11, 5, 1.41);
    g->add_edge(11, 7, 1.41);
    g->add_edge(12, 11, 1);
    g->add_edge(12, 7, 1);
    g->add_edge(12, 13, 1);
    g->add_edge(12, 6, 1.41);
    g->add_edge(12, 8, 1.41);
    g->add_edge(13, 12, 1);
    g->add_edge(13, 8, 1);
    g->add_edge(13, 7, 1.41);
    g->add_edge(14, 13, 1);
    g->add_edge(14, 9, 1);

    g->set_coordinates(0, 0, 0);
    g->set_coordinates(1, 1, 0);
    g->set_coordinates(2, 2, 0);
    g->set_coordinates(3, 3, 0);
    g->set_coordinates(4, 4, 0);
    g->set_coordinates(5, 0, -1);
    g->set_coordinates(6, 1, -1);
    g->set_coordinates(7, 2, -1);
    g->set_coordinates(8, 3, -1);
    g->set_coordinates(9, 4, -1);
    g->set_coordinates(10, 0, -2);
    g->set_coordinates(11, 1, -2);
    g->set_coordinates(12, 2, -2);
    g->set_coordinates(13, 3, -2);
    g->set_coordinates(14, 4, -2);

    std::cout << "Graph without weights.\n";
    g->print_graph();

    std::cout << "\nGraph with weights.\n";
    g->print_graph_with_weights();

    std::cout << "\nGenerating path:\n";
    std::forward_list<int> * path = g->astar(0, 4);
    for (auto it = path->begin(); it != path->end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    delete(g);

    return 0;
}
