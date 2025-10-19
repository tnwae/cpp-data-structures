#include "blist.h"

#pragma once

template <typename T>
class bqueue {
public:
  bqueue() {
    list = new blist<T>();
  }

  ~bqueue() {
    delete list;
  }

  void Push(T value) {
    list->PushBack(value);
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
