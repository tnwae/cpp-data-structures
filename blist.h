#include <cstdlib>
#include <functional>
using namespace std;

template<typename T>
class blist_node {
public:
  blist_node(T _value, blist_node *_next, blist_node *_prev) {
    value = _value;
    next = _next;
    prev = _prev;
  }
  blist_node(T _value) {
    value = _value;
    next = NULL;
    prev = NULL;
  }
  blist_node() {
    next = NULL;
    prev = NULL;
  }

  T Value() { return value; }
  void Value(T _val) { value = _val; }

  blist_node<T> *Next() { return next; }
  blist_node<T> *Prev() { return prev; }
  void Next(blist_node<T> *node) { next = node; }
  void Prev(blist_node<T> *node) { prev = node; }
private:
  T value;
  blist_node<T> *next;
  blist_node<T> *prev;
};

template<typename T>
class blist_sentinel_node : public blist_node<T>
{
public:
  blist_sentinel_node() {
    size = 0;
  }
  int Size() { return size; }
  void Size(int new_size) { size = new_size; }
private:
  int size;
};

template<typename T>
class blist
{
public:
  blist() {
    sentinel = new blist_sentinel_node<T>();
    sentinel->Next(sentinel);
    sentinel->Prev(sentinel);
    sentinel->Size(0);
  }

  ~blist() {
    while(sentinel->Next() != sentinel) {
      blist_node<T> *node = sentinel->Next();
      Delete(node);
      sentinel->Size(sentinel->Size() - 1);
  }
  }
  blist_node<T> *First() { return sentinel->Next(); }
  blist_node<T> *Last() { return sentinel; }
  int Size() { return sentinel->Value(); }

  void InsertBefore(T _value, blist_node<T> *next) {
    blist_node<T> *new_node = new blist_node<T>(_value);
    new_node->Prev(next->Prev());
    next->Prev()->Next(new_node);
    next->Prev(new_node);
    new_node->Next(next);
    sentinel->Size(sentinel->Size() + 1);
  }

  void InsertAfter(T _value, blist_node<T> *prev) {
    InsertBefore(_value, prev->Prev());
  }

  void PushFront(T _value) {
    InsertBefore(_value, First());
  }

  void PushBack(T _value) {
    InsertBefore(_value, Last());
  }

  T PopFront() {
    T retval;

    blist_node<T> *front = sentinel->Next();
    retval = front->Value();
    Delete(front);

    return retval;
  }

  bool Empty() {
    bool retval = false;
    if(sentinel->Next() == sentinel) retval = true;
    return retval;
  }

  void Closure(std::function<void(T)> callback) {
    for(blist_node<T> *node = First(); node != Last(); node = node->Next()) {
      callback(node->Value());
    }
  }

  void Delete(blist_node<T> *node) {
    node->Next()->Prev(node->Prev());
    node->Prev()->Next(node->Next());
    delete node;
    sentinel->Size(sentinel->Size() - 1);
  }

  blist_node<T> *Find(T value) {
    for(blist_node<T> *node = First(); node != Last(); node = node->Next()) {
      if(node->Value() == value) return node;
    }
    return NULL;
  }

  void DeleteIf(std::function<bool(T)> test) {
    blist_node<T> *next;
    for(blist_node<T> *node = First(); node != Last(); node = next) {
      next = node->Next();
      if(test(node->Value()) == true) Delete(node);
    }
  }

//  void AddIf(T source[], int sourceLength, bool (*test)(T)) {
//    int i = 0;
//    for( ; i < sourceLength; i++) {
//      T atom = source[i];
//      if(test(atom) == true) PushBack(atom);
//    }
//  }

  void AddIf(T source[], int sourceLength, std::function<bool(T)> test) {
    int i = 0;
    for( ; i < sourceLength; i++) {
      T atom = source[i];
      if(test(atom) == true) PushBack(atom);
    }
  }
private:
  blist_sentinel_node<T> *sentinel;
};
