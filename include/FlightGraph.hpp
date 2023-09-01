#ifndef FLIGHTGRAPH_HPP
#define FLIGHTGRAPH_HPP

#include <queue>
#include <unordered_map>
#include "City.hpp"

using namespace std;

// Graf yapısı
struct GraphNode {
    string name;
    unordered_map<string, int> flights; // Havalimanı ve mesafe
};

// Graf sınıfı
class FlightGraph {
private:
    unordered_map<string, GraphNode> graphNodes;

public:
    // Yeni bir havalimanı ekler
    void addNode(string name) {
        graphNodes[name] = {name};
    }

    // Havalimanları arasına uçuş ekler
    void addFlight(string source, string destination, int distance) {
        graphNodes[source].flights[destination] = distance;
        graphNodes[destination].flights[source] = distance;
    }

    // BFS Algorithm
    bool hasFlight(string source, string destination) {
        if (graphNodes.find(source) == graphNodes.end() || graphNodes.find(destination) == graphNodes.end()) {
            return false;
        }

        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (current == destination) {
                return true;
            }

            for (const auto& flight : graphNodes[current].flights) {
                string neighbor = flight.first;
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return false;
    }
};

#endif //FLIGHTGRAPH_HPP
