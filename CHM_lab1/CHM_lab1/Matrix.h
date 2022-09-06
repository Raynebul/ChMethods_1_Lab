#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{
public:
   vector<vector<double>> al;
   vector<vector<double>> au;
   vector<double> di;
   vector<double> F;
   int n;
   int m;
   void Readfile();
   void Writefile();
   void LU();
   void LyF();
   void Uxy();
   void Multiplication();
   void SLAU();
};