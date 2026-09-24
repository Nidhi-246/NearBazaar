#include "ProductStore.hpp"

int main() {
    ProductStore store;

    store.insert({1, "Blue Pen", "Writing"});
    store.insert({2, "A4 Notebook", "Paper"});
    store.insert({3, "Geometry Box", "Instruments"});

    std::cout << "Total products stored: " << store.size() << std::endl;

    // Test lookup by ID
    auto p1 = store.findById(2);
    if (p1.has_value()) {
        std::cout << "Found by ID 2: " << p1->name << " (" << p1->category << ")" << std::endl;
    } else {
        std::cout << "Product ID 2 not found." << std::endl;
    }

    // Test lookup by name (different case, to prove case-insensitivity works)
    auto p2 = store.findByName("blue pen");
    if (p2.has_value()) {
        std::cout << "Found by name 'blue pen': product ID " << p2->id << std::endl;
    } else {
        std::cout << "Product 'blue pen' not found." << std::endl;
    }

    // Test a lookup that should fail
    auto p3 = store.findById(999);
    if (!p3.has_value()) {
        std::cout << "Correctly returned not-found for ID 999." << std::endl;
    }

    return 0;
}