// REQUIRES: libcxx
// REQUIRES: uclibc
// RUN: %clangxx -emit-llvm %O0opt -std=c++11 %libcxx_includes -nostdinc++ -g -c %s -o %t.bc
// RUN: rm -rf %t.klee-out
// RUN: %klee --output-dir=%t.klee-out --libc=uclibc --libcxx %t1.bc 2>&1 | FileCheck %s

#include <iostream>
#include <thread>
#include <mutex>

int sharedVariable = 0;
std::mutex mutex; // Мьютекс для синхронизации доступа к общей переменной

void updateVariable(int value) {
std::lock_guard<std::mutex> lock(mutex);
sharedVariable = value;
}

void thread1() {
updateVariable(123);
}

void thread2() {
updateVariable(456);
}

int main() {
setlocale(LC_ALL, "Russian");
std::thread t1(thread1);
std::thread t2(thread2);

t1.join();
t2.join();

std::cout << "Значение переменной: " << sharedVariable << std::endl;

return 0;
}
