#pragma once

#include <vector>
#include <fstream>
#include <iostream>



using namespace std;

class Matrix
{
public:
   vector<vector<float>> Matrix;

   vector<vector<double>> al;
   vector<vector<double>> au;
   vector<double> di;
   //vector<int> x;
   //vector<vector<float>> L;
   //vector<vector<float>> U;
   vector<double> F;
   int n;
   int m;
   void Readfile();
   void Writefile();
   void Writefile1();
   void LU();
   void LU1();
   void LyF();
   void Uxy();
   void Multiplication();
   void SLAU();


};