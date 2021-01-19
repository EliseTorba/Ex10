// copyright 2021 Elizaveta D.
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>
#include <string>
#include <new>

template<class T>
class MyStack {
 private:
     T* stack;
     int size;
     int max_size;

 public:
     explicit MyStack(int n) {
         this->size = 0;
         this->max_size = n;
         this->stack = new T[n];
     }
     MyStack(const MyStack& Stack) {
         this->size = Stack.size;
         this->max_size = Stack.max_size;
         this->stack = new T[Stack.max_size];
         for (int i = 0; i < max_size; i++) {
             stack[i] = Stack.stack[i];
         }
     }
     ~MyStack() {
         delete[] stack;
         size = 0;
         max_size = 0;
     }
     T get() const {
         if (!isEmpty()) {
             return stack[size - 1];
         }
         return 0;
     }
     T pop() {
         if (!isEmpty()) {
             T result = stack[size - 1];
             size--;
             return result;
         }
         return 0;
     }
     void push(T symbol) {
         if (!isFull()) {
             stack[size] = symbol;
             size++;
         }
     }
     bool isFull() const {
         return (size == max_size);
     }
     bool isEmpty() const {
         return (size == 0);
     }
};

#endif  // INCLUDE_MYSTACK_H_
