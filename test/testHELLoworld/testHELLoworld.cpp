// REQUIRES: libcxx
// REQUIRES: uclibc
// RUN: %clangxx -emit-llvm %O0opt -std=c++11 %libcxx_includes -nostdinc++ -g -c %s -o %t.bc
// RUN: rm -rf %t.klee-out
// RUN: %klee --output-dir=%t.klee-out --libc=uclibc --libcxx %t1.bc 2>&1 | FileCheck %s

#include "klee/klee.h"
#include <iostream>
using namespace std;

int main() 
{ 
    cout << "Hello, world!" << endl;
    return 0; 
}