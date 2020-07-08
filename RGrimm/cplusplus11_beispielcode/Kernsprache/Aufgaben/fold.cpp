#include <iostream>

template <int  i, int j>
struct addMe{
  static const int value= i+j;
};

template <int  i, int j>
struct multMe{
  static const int value= i*j;
};

template <int  i, int j>
struct minMe{
  static const int value= (i<j)? i :j;
};

template <int  i, int j>
struct maxMe{
  static const int value= (i>j)? i :j;
};

template<template<int, int> class, int, int ...> struct
fold;

template<template<int, int> class f, int init> struct
fold<f, init> {
    static const int value = init;
};

template<template<int, int> class f, int init, int head, int ...tail> struct
fold<f, init, head, tail...> {
    static const int value = f<head, fold<f, init, tail...>::value>::value;
};


int main(){


  std::cout << std::endl;
  std::cout << "fold<addMe,0>: " << fold<addMe,0>::value <<std::endl;
  std::cout << "fold<addMe,1,2,3,4,5>::value: " << fold<addMe,1,2,3,4,5>::value << std::endl;
  std::cout << "fold<addMe,-20,-10,10,20>::value: " << fold<addMe,-20,-10,10,20>::value << std::endl;

  std::cout << std::endl;

  std::cout << "fold<multMe,1>: " << fold<multMe,1>::value <<std::endl;
  std::cout << "fold<multMe,1,2,3,4,5>::value: " << fold<multMe,1,2,3,4,5>::value << std::endl;
  std::cout << "fold<multMe,-20,-10,10,20>::value: " << fold<multMe,-20,-10,10,20>::value << std::endl;

  std::cout << std::endl;

  std::cout << "fold<minMe,1000,13,12,-43,43,5>::value: " << fold<minMe,1000,13,12,-43,43,5>::value << std::endl;

  std::cout << std::endl;

  std::cout << "fold<maxMe,0,41,32,3,-4,-55>::value :" << fold<maxMe,0,41,32,3,-4,-55>::value << std::endl;

  std::cout << std::endl;
}

