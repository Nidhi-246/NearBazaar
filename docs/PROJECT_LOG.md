# NearBazaar Project Log

## Status (end of Week 1)
Days 1-6 complete. Day 7 = review.

## What exists
- algo-service (C++, CMake build)
  - ProductStore.hpp: two hash maps (by ID, by lowercase name)
  - Trie.hpp: prefix autocomplete, IDs stored at every node
  - Catalog.hpp: seeds the 15-product demo catalog
  - server.cpp: HTTP server on port 8080 (cpp-httplib + nlohmann/json)
  - test_productstore, test_trie, test_catalog: console tests

## Current API
- GET /autocomplete?q=<prefix>
  returns JSON array of {id, name, category}, max 8 results

## Architecture (unchanged from spec)
Frontend -> Java backend -> (Python ai-service, C++ algo-service) -> MySQL
Only Java talks to MySQL.

## Known limitations / decisions pending
- Trie matches prefixes of the FULL name only. "note" does not match
  "Spiral Notebook". Option: also insert each word of a name separately.
  Decide before Java integration.
- Empty prefix returns no results (root stores no IDs). Intentional.
- Third-party headers (httplib.h, json.hpp) live in algo-service/include/
  and are gitignored. Re-download with curl on a fresh clone.

## Environment notes
- Windows + MSYS2 UCRT64 (g++), CMake with "MinGW Makefiles"
- Windows needs ws2_32 linked for the server target
- Work inside VS Code integrated terminal (Git Bash)

## Next
- Week 2: MySQL schema, SQL basics, Queue, Priority Queue, Graph, Dijkstra