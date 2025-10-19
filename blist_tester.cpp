#include "blist.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

void printNum(int number) {
  printf("%d\n", number);
}

bool isEven(int number) {
  return (number % 2 == 0) ? true : false;
}

bool beginsWithB(string str) {
  return (str[0] == 'b' || str[0] == 'B') ? true : false;
}

int main(int argc, char **argv) {
  blist<int> *numbers = new blist<int>();
  int figs[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  numbers->AddIf(figs, 10, [](int num)->bool{ return (num % 2) ? true : false; });
  numbers->Closure([](int n){ cout << n << endl; });

  delete numbers;

  return EXIT_SUCCESS;
}
