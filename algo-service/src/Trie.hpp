#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// One node per character. children maps 'next character' -> next node.
// productIds collects every product ID reachable from this node onward,
// so autocomplete doesn't need a separate tree-walk to gather results.
struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    std::vector<int> productIds;
    bool isEndOfWord = false;
};

class Trie {
private:
    TrieNode* root;

    std::string toLower(const std::string& s) const {
        std::string result = s;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word, tagging every node along the path with this product's ID.
    // O(L) where L = word length.
    void insert(const std::string& word, int productId) {
        std::string w = toLower(word);
        TrieNode* current = root;
        for (char ch : w) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
            current->productIds.push_back(productId);
        }
        current->isEndOfWord = true;
    }

    // Return product IDs for every word starting with this prefix.
    // O(L) to walk to the prefix node, then results are already collected there.
    std::vector<int> autocomplete(const std::string& prefix, int limit = 8) const {
        std::string p = toLower(prefix);
        TrieNode* current = root;
        for (char ch : p) {
            auto it = current->children.find(ch);
            if (it == current->children.end()) {
                return {}; // no word has this prefix at all
            }
            current = it->second;
        }
        std::vector<int> results = current->productIds;
        if ((int)results.size() > limit) {
            results.resize(limit);
        }
        return results;
    }
};