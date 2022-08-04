
#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <assert.h>
using namespace std;

class LRUCache {
private:
  int capacity;

  // list of key
  // cache.back -> least recent key
  // cache.front -> most recent key
  list<int> cache;

  // key -> iterator
  unordered_map<int, list<int>::iterator> key_2_it;

  // key -> value
  unordered_map<int, int> kv;                   

public:
  LRUCache(int c): capacity(c) {}

  void print() {
    cout << "cache=[" ;
    for (auto it: cache) {
      cout << "(" << it << ", " << kv[it] << "), ";
    }
    cout << "], ";

    cout << "key_2_it=[";
    for (auto it: key_2_it) {
      cout << "(" << it.first << ", " << *it.second << "), ";
    }
    cout << "], ";

    cout << "kv=[";
    for (auto it: kv) {
      cout << "(" << it.first << ", " << it.second << "), ";
    }
    cout << "], ";

    cout << endl << endl;
  }
  
  int get(int key) {
    if (kv.count(key) == 0) {
      return -1;
    }

    // update cache
    cache.erase(key_2_it[key]);
    cache.push_front(key);
    key_2_it[key] = cache.begin();

    // return safely since
    // the key must exist
    return kv[key];
  }

  void put(int key, int value) {
    // there are 4 cases to be considered
    if (kv.size() == capacity && kv.count(key) == 0) {
      int k = cache.back();
      cout << "Key to be removed: " << k << endl;

      // remove last key
      key_2_it.erase(k);
      kv.erase(k);
      cache.pop_back();

      kv[key] = value;
      cache.push_front(key);
      key_2_it[key] = cache.begin();
    }
    else if (kv.size() == capacity && kv.count(key) != 0) {
      cout << "Key to be updated: " << key << endl;
      kv[key] = value;
      cache.erase(key_2_it[key]);
      key_2_it.erase(key);

      cache.push_front(key);
      key_2_it[key] = cache.begin();
    }
    else if (kv.size() < capacity && kv.count(key) == 0) {
      kv[key] = value;
      cache.push_front(key);
      key_2_it[key] = cache.begin();
    }
    else if (kv.size() < capacity && kv.count(key) != 0) {
      cout << "Key to be updated: " << key << endl;
      kv[key] = value;
      cache.erase(key_2_it[key]);
      key_2_it.erase(key);

      cache.push_front(key);
      key_2_it[key] = cache.begin();
    }

  }
};


int main() {

  LRUCache cache = LRUCache(2);

  cache.put(2, 1);
  cache.put(1, 1);
  cache.put(2, 3);
  cache.put(4, 1);
  assert(cache.get(1) == -1);
  assert(cache.get(2) == 3);
  cout << "(1) all test passed." << endl << endl;

  cache = LRUCache(2);

  cache.put(1, 1); // cache is {1=1}
  cache.put(2, 2); // cache is {1=1, 2=2}
  assert(cache.get(1) == 1);    // return 1
  cache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cache.print();
  assert(cache.get(2) == -1);    // returns -1 (not found)
  cache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  assert(cache.get(1) == -1);    // return -1 (not found)
  assert(cache.get(3) == 3);    // return 3
  assert(cache.get(4) == 4);    // return 4
  cout << "(2) all test passed." << endl;

  return 0;
}
