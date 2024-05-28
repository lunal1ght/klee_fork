// RUN: %clangxx %s -emit-llvm %O0opt -c -o %t1.bc
// RUN: rm -rf %t.klee-out
// RUN: %klee --output-dir=%t.klee-out --write-no-tests --exit-on-error --external-calls=none %t1.bc

#include <iostream>
using namespace std;

int main() 
{ 
    cout << "Hello, world!" << endl;
    return 0; 
}