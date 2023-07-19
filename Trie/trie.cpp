#include "trie.h"

namespace Trie {


  int root;
  int poolIndex;
  Tn triePool[TRIE_POOL_SIZE];


  int getNewTrieNode() {
    triePool[poolIndex].isWordEnd = 0;
    triePool[poolIndex].prefixCount = 0;

    for (int j = 0; j < ALPHA_SIZE; ++j) {
      triePool[poolIndex].child[j] = NULL_INDEX;
    }

    return poolIndex++;
  }


  void initTrie() {
    poolIndex = 0;
    root = getNewTrieNode();
  }


  int insertTrieKey(const char *key) {
    int index = root;

    for (int j = 0; key[j] != '\0'; ++j) {
      int cindex = C2I(key[j]);

      if (triePool[index].child[cindex] == NULL_INDEX) {
        triePool[index].child[cindex] = getNewTrieNode();
      }

      triePool[index].prefixCount++;
      index = triePool[index].child[cindex];
    }

    return ++triePool[index].isWordEnd;
  }


  int searchTrieKey(const char *key) {
    int index = root;

    for (int j = 0; key[j] != '\0'; ++j) {
      int cindex = C2I(key[j]);

      if (triePool[index].child[cindex] == NULL_INDEX) {
        return 0;
      }

      index = triePool[index].child[cindex];
    }

    return triePool[index].isWordEnd;
  }


  int deleteTrieKey(const char *key) {
    int foundCount = searchTrieKey(key);
    int index = root;

    for (int j = 0; key[j] != '\0'; ++j) {
      int cindex = C2I(key[j]);

      triePool[index].prefixCount -= foundCount;
      if (triePool[index].prefixCount == 0) {
        triePool[index].child[cindex] = NULL_INDEX;
        break;
      }

      index = triePool[index].child[cindex];
    }

    triePool[index].isWordEnd -= foundCount;

    return foundCount;
  }


}// namespace Trie