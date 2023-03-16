
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

  Node(): key(0), val(0) {}
  Node(int k, int v): key(k), val(v) {}
};

class DoubleLinkedList {
private:
  int size;
  Node *head;  // least recent node
  Node *tail;  // most recent node
public:
  DoubleLinkedList(): head(new Node()), tail(new Node()), size(0) {
    head->next = tail;
    tail->prev = head;
  }

  // add most recent record
  void addLast(Node* x) {
    tail->prev->next = x;
    x->next = tail;
    tail->prev->next = tail->prev;
    x->prev = x;
    size++ ;
  }

  // remove any given node
  // prereq: x must be in the D-list
  // purpose: when adding existing node
  // into the list, remove it firsts
  // and add it to the tail
  Node* remove(Node* x) {
    x->next->prev = x->prev;
    x->prev->next = x->next;
    delete x;
    size--;
    return x;
  }

  Node* removeFirst() {
    if (head->next == tail) {
      return nullptr;
    }

    Node* ret = head->next;
    remove(ret);
    return ret;
  }

  int getSize() {
    return size;
  }
};

class LRUCache {
private:
  int capacity;
  DoubleLinkedList* cache;
  unordered_map<int, Node> map;

public:
  LRUCache(int c): capacity(c) {
    cache = new DoubleLinkedList();
    map = unordered_map<int, Node>();
  }
  
  // main method
  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;
    }
    makeRecent(key);
    return map[key].val;
  }
  
  // main method
  void put(int key, int value) {
    // if the key exists, make it recently
    if (map.find(key) != map.end()) {
      removeKey(key);
      makeRecent(key);
    }

    // if the key doesn't exist
    else {
      if (capacity == map.size()) {
        removeLeastRecent();
      }
      addRecent(key, value);
    }
  }

  // promote a node to be the most recnet one
  void makeRecent(int key) {
    Node node = map[key];
    cache->remove(&node);
    cache->addLast(&node);
  }

  // add a node to tail
  void addRecent(int key, int val) {
    Node node = Node(key, val);
    map.insert({key, node});
    cache->addLast(&node);
  }

  void removeKey(int key){
    Node node = map[key];
    cache->remove(&node);
    map.erase(key);
  }

  void removeLeastRecent(){
    Node *deletedNode = cache->removeFirst();
    int key = deletedNode->key;
    map.erase(key);
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
