#include <iostream>
#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>

class Node {
private:
    int nodeID;
    std::string message;
    Node* next;

public:
    Node(int id) : nodeID(id), message(""), next(nullptr) {}
    int getNodeID() const { return nodeID; }
    void setMessage(const std::string& msg) { message = msg; }
    std::string getMessage() const { return message; }
    void setNext(Node* nextNode) { next = nextNode; }
    Node* getNext() const { return next; }
};

class LinkedList {
private:
    Node* head;
    std::unordered_map<int, Node*> nodeMap;

public:
    LinkedList() : head(nullptr) {}

   ~LinkedList() {
    std::unordered_map<Node*, bool> visited;
    Node* current = head;
    while (current && !visited[current]) {
        visited[current] = true;
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}

    void addNode(int nodeID) {
        if (nodeMap.find(nodeID) != nodeMap.end()) {
            std::cout << "Node " << nodeID << " already exists.\n";
            return;
        }

        Node* newNode = new Node(nodeID);
        newNode->setNext(head);
        head = newNode;
        nodeMap[nodeID] = newNode;
    }

    void connectNodes(int fromNodeID, int toNodeID) {
    Node* fromNode = nodeMap[fromNodeID];
    Node* toNode = nodeMap[toNodeID];

    if (fromNode && toNode) {
        if (fromNode->getNext() != nullptr) {
            std::cout << "Warning: Node " << fromNodeID 
                      << " already connected. Overwriting previous connection.\n";
        }
        fromNode->setNext(toNode);
    } else {
        std::cout << "One or both nodes not found.\n";
        }
    }

    void sendMessage(int fromNodeID, const std::string& message) {
        Node* fromNode = nodeMap[fromNodeID];
        std::cout << "Sending message from Node " << fromNodeID << ": " << message << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (fromNode) {
            fromNode->setMessage(message);
        } else {
            std::cout << "Node " << fromNodeID << " not found.\n";
        }
    }

    void receiveMessage(int toNodeID) {
        Node* toNode = nodeMap[toNodeID];
        if (toNode) {
            Node* sender = head;
            while (sender && sender->getNext() != toNode) {
                sender = sender->getNext();
            }

            if (sender) {
                std::cout << "Node " << toNodeID << " received message: "
                          << sender->getMessage() << " from Node " << sender->getNodeID() << std::endl;
            } else {
                std::cout << "No message received by Node " << toNodeID << std::endl;
            }
        } else {
            std::cout << "Node " << toNodeID << " not found.\n";
        }
    }
};

// Example usage
int main() {
    LinkedList blockchainNetwork;

    blockchainNetwork.addNode(1);
    blockchainNetwork.addNode(2);

    blockchainNetwork.connectNodes(1, 2);

    blockchainNetwork.sendMessage(1, "Transaction: Node 1 sends 5 BTC to Node 2");
    blockchainNetwork.receiveMessage(2);

    return 0;
}