#include "blist.h"

#pragma once

template <typename T>
class bstack {
public:
  bstack() {
    list = new blist<T>();
  }

  ~bstack() {
    delete list;
  }

  void Push(T value) {
    list->PushFront(value);
  }

  T Pop() {
    if(list->Empty()) return (T) NULL;
    return list->PopFront();
  }

  bool Empty() {
    return list->Empty();
  }
private:
  blist<T> *list;
};
