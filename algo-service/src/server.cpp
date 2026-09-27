#include "httplib.h"
#include "json.hpp"
#include "Catalog.hpp"
#include <iostream>

using json = nlohmann::json;

int main() {
    ProductStore store;
    Trie trie;
    seedCatalog(store, trie);
    std::cout << "Catalog loaded: " << store.size() << " products" << std::endl;

    httplib::Server svr;

    // GET /autocomplete?q=note
    svr.Get("/autocomplete", [&](const httplib::Request& req, httplib::Response& res) {
    std::string prefix = req.has_param("q") ? req.get_param_value("q") : "";
    std::cout << "Received query param 'q' = [" << prefix << "]" << std::endl;

    auto ids = trie.autocomplete(prefix);
    std::cout << "Number of matching IDs: " << ids.size() << std::endl;

    json response = json::array();
    for (int id : ids) {
        auto p = store.findById(id);
        if (p.has_value()) {
            response.push_back({{"id", p->id}, {"name", p->name}, {"category", p->category}});
        }
    }

    res.set_content(response.dump(), "application/json");
});

    std::cout << "algo-service listening on http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}