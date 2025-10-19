#include "bstack.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
  bstack<string> *people = new bstack<string>();

  people->Push("bwk");  // B. W. Kernighan, Princeton
  people->Push("dmr");  // D. M. Ritchie, Bell Labs
  people->Push("spj");  // S. P. Jobs, Apple
  people->Push("ken");  // Ken Thompson, Bell Labs
  people->Push("jsp");  // J. S. Plank, Tennessee
  people->Push("wae");  // W. A. Ellison, Route 38

  while(!people->Empty()) {
    cout << people->Pop() << endl;
  }
  
  return EXIT_SUCCESS;
}
