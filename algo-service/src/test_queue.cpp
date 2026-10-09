#include "OrderQueue.hpp"
#include <iostream>

int main() {
    OrderQueue q;

    q.enqueue({101, 1, "PLACED"});
    q.enqueue({102, 2, "PLACED"});
    q.enqueue({103, 1, "PLACED"});

    std::cout << "Queue size: " << q.size() << std::endl;

    auto front = q.peek();
    if (front.has_value()) {
        std::cout << "Front (peek): order " << front->id << std::endl;
    }
    std::cout << "Size after peek: " << q.size() << std::endl;

    while (!q.empty()) {
        auto o = q.dequeue();
        std::cout << "Processing order " << o->id << std::endl;
    }

    auto none = q.dequeue();
    if (!none.has_value()) {
        std::cout << "Dequeue on empty queue handled safely." << std::endl;
    }

    return 0;
}