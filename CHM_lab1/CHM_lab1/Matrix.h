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
   vector<real> x, y;
   bool flag = false;
   int n, m;
   int ht;
   void Readfile();
   int Readfile1();
   void Writefile();
   void Writefile1();
   void LU();
   void LU1();
   void LU2();
   void LyF();
   void Uxy();
   void MultiplicationXY();
   void MultiplicationYF();
   void SLAU();
};