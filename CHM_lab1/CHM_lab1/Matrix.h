#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cmath>

#define SIRF "%f "
//#define SIRFP "%.1f"
#define SIRFPR "%.8lf\n"
#define SIRFP "%.8f "

typedef float real;
typedef double reals;

using namespace std;

class Matrix
{
public:
   vector<vector<real>> al;
   vector<vector<real>> au;
   vector<vector<real>> A;
   vector<vector<real>> Areverse;
   vector<real> di;
   vector<real> F;
   vector<real> x, y;
   real detA=1;
   bool flag = false;
   int n, m;
   int ht;
   //void Readfile();
   int Readfile1();
   int Readfile2();
   int Readfile3(vector<real> &vector);
  // void Writefile();
   void Writefile1();
   void Writefile1_Scalar();
   void Writefile2();
   void Writefile3();
   void LU();
   void LU_Scalar();
   void LyF_Reverse();
   void Uxy_Reverse();
   void Uxy1_Reverse();
   void Uxy_Direct();
   void LyF_Direct();
   void LyF_Reverse_Scalar();
   void Uxy_Reverse_Scalar();
   void Uxy1_Reverse_Scalar();
   void Uxy_Direct_Scalar();
   void LyF_Direct_Scalar();
   void SLAU1();
   void SLAU2();
   void SLAU3();
   void SLAU1_Scalar();
   void SLAU2_Scalar();
   void TightMatrix();
   void Gauss();
   void FinddetA();
   void FindAReverse();
   vector<real> Multiplication(vector<vector<real>> &a, vector<real> &e, vector<real> &x);
   void GilbertMatrix();
};