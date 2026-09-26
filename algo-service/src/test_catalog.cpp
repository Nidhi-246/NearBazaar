#include "Catalog.hpp"
#include <iostream>

void printResults(const std::string& prefix, ProductStore& store, Trie& trie) {
    std::cout << "Autocomplete for \"" << prefix << "\":" << std::endl;
    auto ids = trie.autocomplete(prefix);
    if (ids.empty()) {
        std::cout << "  (no matches)" << std::endl;
    }
    for (int id : ids) {
        auto p = store.findById(id);
        if (p.has_value()) std::cout << "  - " << p->name << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    ProductStore store;
    Trie trie;
    seedCatalog(store, trie);

    std::cout << "Catalog loaded: " << store.size() << " products\n" << std::endl;

    printResults("a4", store, trie);        // should match A4 Notebook, A4 Sheets Pack
    printResults("s", store, trie);          // single character - should match several
    printResults("geometry", store, trie);   // exact full match
    printResults("zzz", store, trie);        // no match at all
    printResults("", store, trie);           // empty prefix - what should this even return?

    return 0;
}