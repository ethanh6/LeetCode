
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

class Node {
public: 
  int key, val;
  Node *next, *prev;
  Node(int k, int v) : key(k), val(v) {
    ;
  }
;

class LRUCache {
private:
  int capacity;

public:
  LRUCache(int c) : capacity(c) {
    ;
  }
  
  int get(int key) {
      
  }
  
  void put(int key, int value) {
      
  }
};


int main() {

  LRUCache lRUCache = LRUCache(2);
  lRUCache.put(1, 1); // cache is {1=1}
  lRUCache.put(2, 2); // cache is {1=1, 2=2}
  assert(lRUCache.get(1) == 1);    // return 1
  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  assert(lRUCache.get(2) == -1);    // returns -1 (not found)
  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  assert(lRUCache.get(1) == -1);    // return -1 (not found)
  assert(lRUCache.get(3) == 3);    // return 3
  assert(lRUCache.get(4) == 4);    // return 4

  return 0;
}
