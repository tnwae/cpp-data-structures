#include "bqueue.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv) {
  bqueue<string> *people = new bqueue<string>();

  people->Push("Washington");
  people->Push("Adams");
  people->Push("Jefferson");
  people->Push("Madison");
  people->Push("Monroe");
  people->Push("Quincy Adams");
  people->Push("Jackson");
  people->Push("Van Buren");
  people->Push("Harrison");
  people->Push("Tyler");

  while(!people->Empty()) {
    cout << people->Pop() << endl;
  }
    
  return EXIT_SUCCESS;
}
