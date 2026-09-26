#pragma once
#include "ProductStore.hpp"
#include "Trie.hpp"
#include <vector>

// Seeds the full 15-product demo catalog into both structures at once,
// so every test file uses identical data instead of duplicating it.
inline void seedCatalog(ProductStore& store, Trie& trie) {
    std::vector<Product> catalog = {
        {1, "Blue Pen", "Writing"},
        {2, "Black Pen", "Writing"},
        {3, "A4 Notebook", "Paper"},
        {4, "Spiral Notebook", "Paper"},
        {5, "Long Notebook", "Paper"},
        {6, "Drawing Notebook", "Paper"},
        {7, "Geometry Box", "Instruments"},
        {8, "A4 Sheets Pack", "Paper"},
        {9, "Eraser", "Writing"},
        {10, "Sharpener", "Writing"},
        {11, "Highlighter", "Writing"},
        {12, "Stapler", "Office"},
        {13, "Glue Stick", "Office"},
        {14, "Sketch Pens Pack", "Art"},
        {15, "Scale Ruler", "Instruments"}
    };
    for (const auto& p : catalog) {
        store.insert(p);
        trie.insert(p.name, p.id);
    }
}