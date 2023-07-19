#include <iostream>

#include "doctest.h"
#include "trie.h"

using namespace std;
using namespace Trie;

const int MAX_WORD_LENGTH = 128;
const int MAX_QUERY_NAME_LENGTH = 30;
enum Query { Q_INSERT_TRIE, Q_SEARCH_TRIE, Q_DELETE_TRIE };

void getQueryName(Query query, char *queryName) {

  switch (query) {
    case Q_INSERT_TRIE:
      snprintf(queryName, MAX_QUERY_NAME_LENGTH, "Q_INSERT_TRIE");
      break;

    case Q_SEARCH_TRIE:
      snprintf(queryName, MAX_QUERY_NAME_LENGTH, "Q_SEARCH_TRIE");
      break;

    case Q_DELETE_TRIE:
      snprintf(queryName, MAX_QUERY_NAME_LENGTH, "Q_DELETE_TRIE");
      break;

    default:
      snprintf(queryName, MAX_QUERY_NAME_LENGTH, "Q_INVALID");
      break;
  }
}


TEST_CASE("TRIE TEST") {
  MESSAGE("[TRIE_TEST_BEGIN]");

  const char *keys[]{"about", "above", "arrive",      "above", "abomination", "abound",
                     "ab",    "raid",  "abomination", "ab",    "asking"};

  const Query queries[]{Q_INSERT_TRIE, Q_INSERT_TRIE, Q_SEARCH_TRIE, Q_INSERT_TRIE, Q_SEARCH_TRIE, Q_INSERT_TRIE,
                        Q_INSERT_TRIE, Q_SEARCH_TRIE, Q_DELETE_TRIE, Q_DELETE_TRIE, Q_SEARCH_TRIE};

  const int outcome[]{1, 1, 0, 2, 0, 1, 1, 0, 0, 1, 0};

  int numKeys = sizeof(keys) / sizeof(char *);
  int numQueries = sizeof(queries) / sizeof(Query);
  int numOutcomes = sizeof(outcome) / sizeof(int);

  REQUIRE(numKeys == numQueries);
  REQUIRE(numQueries == numOutcomes);

  initTrie();

  for (int q = 0; q < numQueries; ++q) {
    char key[MAX_WORD_LENGTH];
    snprintf(key, MAX_WORD_LENGTH, "%s", keys[q]);

    char queryName[MAX_QUERY_NAME_LENGTH];
    getQueryName(queries[q], queryName);

    INFO("Index == ", q);
    INFO("Key == ", key);
    INFO("Query == ", queryName);
    INFO("Outcome == ", outcome[q]);

    switch (queries[q]) {
      case Q_INSERT_TRIE:
        REQUIRE(outcome[q] == insertTrieKey(keys[q]));
        break;

      case Q_SEARCH_TRIE:
        REQUIRE(outcome[q] == searchTrieKey(keys[q]));
        break;

      case Q_DELETE_TRIE:
        REQUIRE(outcome[q] == deleteTrieKey(keys[q]));
        break;

      default:
        break;
    }
  }

  MESSAGE("[TRIE_TEST_END]");
}