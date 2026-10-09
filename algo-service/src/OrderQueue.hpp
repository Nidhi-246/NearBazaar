#pragma once
#include <queue>
#include <optional>
#include <string>

// A minimal order record. We'll grow this later.
struct Order {
    int id;
    int customerId;
    std::string status;   // e.g. "PLACED"
};

// FIFO queue of orders waiting to be handled.
class OrderQueue {
private:
    std::queue<Order> orders;   // std::queue gives O(1) push/pop at the ends

public:
    // Add an order to the back of the line. O(1)
    void enqueue(const Order& order) {
        orders.push(order);
    }

    // Remove and return the front order. O(1)
    // Returns nullopt if the queue is empty (instead of crashing).
    std::optional<Order> dequeue() {
        if (orders.empty()) return std::nullopt;
        Order front = orders.front();
        orders.pop();
        return front;
    }

    // Look at the front order without removing it. O(1)
    std::optional<Order> peek() const {
        if (orders.empty()) return std::nullopt;
        return orders.front();
    }

    size_t size() const { return orders.size(); }
    bool empty() const { return orders.empty(); }
};