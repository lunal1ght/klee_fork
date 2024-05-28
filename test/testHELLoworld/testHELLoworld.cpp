// RUN: %clangxx -emit-llvm -g -c %s -o %t.bc
// RUN: %klee %t.bc
#include "klee/klee.h"
#include <iostream>
using namespace std;

int main() 
{ 
    cout << "Hello, world!" << endl;
    return 0; 
}