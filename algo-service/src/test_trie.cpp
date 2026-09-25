#include "Trie.hpp"
#include "ProductStore.hpp"
#include <iostream>

int main() {
    ProductStore store;
    Trie trie;

    std::vector<Product> catalog = {
        {1, "Notebook", "Paper"},
        {2, "Notebook A4", "Paper"},
        {3, "Spiral Notebook", "Paper"},
        {4, "Drawing Notebook", "Paper"},
        {5, "Blue Pen", "Writing"},
        {6, "Geometry Box", "Instruments"}
    };

    for (const auto& p : catalog) {
        store.insert(p);
        trie.insert(p.name, p.id);
    }

    std::cout << "Autocomplete for 'note':" << std::endl;
    for (int id : trie.autocomplete("note")) {
        auto p = store.findById(id);
        if (p.has_value()) std::cout << "  - " << p->name << std::endl;
    }

    std::cout << "\nAutocomplete for 'blue':" << std::endl;
    for (int id : trie.autocomplete("blue")) {
        auto p = store.findById(id);
        if (p.has_value()) std::cout << "  - " << p->name << std::endl;
    }

    std::cout << "\nAutocomplete for 'xyz' (should be empty):" << std::endl;
    auto results = trie.autocomplete("xyz");
    std::cout << "  Results found: " << results.size() << std::endl;

    return 0;
}