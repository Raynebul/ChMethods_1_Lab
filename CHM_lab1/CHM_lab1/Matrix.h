#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>

#define SIRF "%lf "

typedef float reals;
typedef double real;

using namespace std;

class Matrix
{
public:
   vector<vector<real>> al;
   vector<vector<real>> au;
   vector<real> di;
   vector<real> F;
   int n, m;
   int ht;
   void Readfile();
   void Readfile1();
   void Writefile();
   void Writefile1();
   void LU();
   void LU1();
   void LyF();
   void Uxy();
   void Multiplication();
   void SLAU();
};