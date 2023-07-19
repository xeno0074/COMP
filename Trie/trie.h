#pragma once

namespace Trie {


#define ALPHA_SIZE 26
#define TRIE_POOL_SIZE 100//00003
#define NULL_INDEX -1
#define C2I(c) c - 'a'

  struct TrieNode {
    int isWordEnd;
    int prefixCount;
    int child[ALPHA_SIZE];
  };

  typedef TrieNode Tn;

  extern int root;
  extern int poolIndex;
  extern Tn triePool[TRIE_POOL_SIZE];

  int getNewTrieNode();

  void initTrie();

  int insertTrieKey(const char *key);

  int searchTrieKey(const char *key);

  int deleteTrieKey(const char *key);


}// namespace Trie