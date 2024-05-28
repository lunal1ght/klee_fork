// RUN: %clangxx -emit-llvm -g -c %s -o %t.bc
// RUN: %klee %t.bc

#include <iostream>
using namespace std;

int main() 
{ 
    cout << "Hello, world!" << endl;
    return 0; 
}