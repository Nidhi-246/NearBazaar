
#pragma once
#include <string>
#include <unordered_map>
#include <optional>
#include <iostream>

// Represents one row from the shared product catalog.
struct Product {
    int id;
    std::string name;
    std::string category;
};

// ProductStore wraps two hash maps over the same data:
// one keyed by product ID (fast lookup for order validation),
// one keyed by lowercase product name (fast lookup for AI-resolved text).
class ProductStore {
private:
    std::unordered_map<int, Product> byId;
    std::unordered_map<std::string, Product> byName;

    // Helper: lowercase a string, so "Blue Pen" and "blue pen" match the same key.
    std::string toLower(const std::string& s) const {
        std::string result = s;
        for (char& c : result) c = tolower(c);
        return result;
    }

public:
    // Insert a product into both maps. O(1) average.
    void insert(const Product& p) {
        byId[p.id] = p;
        byName[toLower(p.name)] = p;
    }

    // Look up by ID. Returns std::optional so callers can check "did we find it?"
    // without needing a sentinel value like id == -1.
    std::optional<Product> findById(int id) const {
        auto it = byId.find(id);
        if (it == byId.end()) return std::nullopt;
        return it->second;
    }

    // Look up by exact name (case-insensitive).
    std::optional<Product> findByName(const std::string& name) const {
        auto it = byName.find(toLower(name));
        if (it == byName.end()) return std::nullopt;
        return it->second;
    }

    size_t size() const {
        return byId.size();
    }
};