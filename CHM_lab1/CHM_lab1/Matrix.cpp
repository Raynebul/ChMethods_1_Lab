#include "Matrix.h"


//void Matrix::Readfile()
//{
//   ifstream fin("input.txt");
//   if (!fin.is_open()) // если файл не открыт
//      cout << "‘айл не может быть открыт!\n"; // сообщить об этом
//   else
//   {
//      fin >> n >> m;
//      //Matrix.resize(n);
//      F.resize(n);
//      di.resize(n);
//      al.resize(n);
//      au.resize(n);
//
//      for (int i = 0; i < n; i++)
//      {
//         al[i].resize(m/2);
//         for (int j = 0; j < m / 2; j++)
//            fin >> al[i][j];
//      }
//      for (int i = 0; i < n; i++)
//      {
//         au[i].resize(m/2);
//         for (int j = 0; j < m / 2; j++)
//            fin >> au[i][j];
//      }
//      for (int i = 0; i < n; i++)
//         fin >> di[i];
//      for (int i = 0; i < n; i++)
//         fin >> F[i];
//      ht = (m - 1) / 2;
//   }
//}

int Matrix::Readfile1()
{
   FILE* file;
   fopen_s(&file, "input.txt", "r");
   fscanf_s(file, "%d", &n);
   fscanf_s(file, "%d", &ht);
   if (ht*2+1 > n)
   {
      flag = true;
      return 0;
   }
   //ht = (m - 1) / 2;
   F.resize(n);
   x.resize(n);
   y.resize(n);
   di.resize(n);
   al.resize(n);
   au.resize(n);
   if(!feof(file))
   {
      for (int i = 0; i < n; i++)
      {
         al[i].resize(ht);
         for (int j = 0; j < ht; j++)
            fscanf_s(file, SIRF, &al[i][j]);
      }
      for (int i = 0; i < n; i++)
      {
         au[i].resize(ht);
         for (int j = 0; j < ht; j++)
            fscanf_s(file, SIRF, &au[i][j]);
      }
      for (int i = 0; i < n; i++)
         fscanf_s(file, SIRF, &di[i]);
      for (int i = 0; i < n; i++)
         fscanf_s(file, SIRF, &x[i]);

   }
   fclose(file);
   return 0;
}

int Matrix::Readfile2()
{
   FILE* file;
   fopen_s(&file, "input.txt", "r");
   fscanf_s(file, "%d", &n);
   fscanf_s(file, "%d", &ht);
   if (ht * 2 + 1 > n)
   {
      flag = true;
      return 0;
   }
   //ht = (m - 1) / 2;
   F.resize(n);
   x.resize(n);
   y.resize(n);
   di.resize(n);
   al.resize(n);
   au.resize(n);
   if (!feof(file))
   {
      for (int i = 0; i < n; i++)
      {
         al[i].resize(ht);
         for (int j = 0; j < ht; j++)
            fscanf_s(file, SIRF, &al[i][j]);
      }
      for (int i = 0; i < n; i++)
      {
         au[i].resize(ht);
         for (int j = 0; j < ht; j++)
            fscanf_s(file, SIRF, &au[i][j]);
      }
      for (int i = 0; i < n; i++)
         fscanf_s(file, SIRF, &di[i]);
      for (int i = 0; i < n; i++)
         fscanf_s(file, SIRF, &F[i]);

   }
   fclose(file);
   return 0;
}

int Matrix::Readfile3(vector<real> &vector)
{
   FILE* file;
  // ifstream file;
   //file.open("input.txt");
  fopen_s(&file, "input.txt", "r");
  fscanf_s(file, "%d", &n);
  // file >> n >> ht;
  fscanf_s(file, "%d", &ht);
   if (ht >= n)
   {
      flag = true;
      return 0;
   }
   //ht = (m - 1) / 2;
   F.resize(n);
   x.resize(n);
   y.resize(n);
   di.resize(n);
   al.resize(n);
   au.resize(n);
  if (!feof(file))
  {
      for (int i = 0; i < n; i++)
      {
         al[i].resize(ht);
         for (int j = 0; j < ht; j++)
                fscanf_s(file, SIRF, &al[i][j]);
           // file >> al[i][j];
      }
      for (int i = 0; i < n; i++)
      {
         au[i].resize(ht);
         for (int j = 0; j < ht; j++)
                 fscanf_s(file, SIRF, &au[i][j]);
           // file >> au[i][j];
      }
      //fscanf_s(file, SIRFPR, &di[0]);
      //fscanf_s(file, SIRFP, &di[0]);
      for (int i = 0; i < n; i++)
         //file >> di[i];
         fscanf_s(file, SIRF, &di[i]);
      //fscanf_s(file, SIRFPR, &vector[0]);
      //fscanf_s(file, SIRFP, &vector[0]);
      for (int i = 0; i < n; i++)
           fscanf_s(file, SIRF, &vector[i]);
         //file >> vector[i];

   }
   //file.close();
   fclose(file);
   return 0;
}


//void Matrix::Writefile()
//{
//   ofstream fout("output.txt");
//   for (int i = 0; i < n; i++)
//   {
//      for (int j = 0; j < n; j++)
//      {
//         if (i == j)
//            fout << di[i] << ' ';
//         if (i < j)
//            if (j - i <= m / 2)
//               fout << au[i][i - j + m / 2] << ' ';
//            else
//               fout << 0 << ' ';
//         if (i > j)
//            if (i - j <= m / 2)
//               fout << al[i][j - i + m / 2] << ' ';
//            else
//               fout << 0 << ' ';
//      }
//      fout << endl;
//   }
//   fout << endl;
//   for (int i = 0; i < n; i++)
//   {
//      fout << F[i] << ' ';
//   }
//   cout << endl;
//}

//дл€ 1 выбора в меню

void Matrix::Writefile1()
{
   FILE* file;
   fopen_s(&file, "output.txt", "w");
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i == j)
            fprintf(file, SIRF, di[i]);
         if (j > i)
         {
            if (j - i <= ht)
               if(j<ht)
                  fprintf(file, SIRF, au[j][ht-j+i]);
               else
                  fprintf(file, SIRF, au[j][ht-j+i]);
            else
               fprintf(file, "%d ", 0);
         }
         if (i > j)
         {
            if (i - j <= ht)
               if (i < ht)
                  fprintf(file, SIRF, al[i][ht-i+j]);
               else
                  fprintf(file, SIRF, al[i][ht-i+j]);
            else
               fprintf(file, "%d ", 0);
         }
      }
      fprintf(file, "\n");
   }
   fprintf(file, "\n");
  
   //
   fprintf(file, "заданный x - ");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRF, x[i]);
   }
   fprintf(file, "\n");
   fprintf(file, "y, полученный из x - ");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRF, y[i]);
   }
   fprintf(file, "\n");
   Uxy_Reverse();
   fprintf(file, "x, полученный из y - ");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRF, y[i]);
   }
   fprintf(file, "\n");
   Uxy_Direct();
   fprintf(file, "заданный y - ");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRF, y[i]);
   }
   fprintf(file, "\n");
   //Uxy();
   fprintf(file, "F, полученный из y - ");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRFP, F[i]);
   }
   LyF_Reverse();
   fprintf(file, "\n");
   fprintf(file, "y, полученный из F - ");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRF, F[i]);
   }
   fclose(file);
}

void Matrix::Writefile1_Scalar()
{
   FILE* file;
   fopen_s(&file, "output.txt", "w");
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i == j)
            fprintf(file, SIRF, di[i]);
         if (j > i)
         {
            if (j - i <= ht)
               if (j < ht)
                  fprintf(file, SIRF, au[j][ht - j + i]);
               else
                  fprintf(file, SIRF, au[j][ht - j + i]);
            else
               fprintf(file, "%d ", 0);
         }
         if (i > j)
         {
            if (i - j <= ht)
               if (i < ht)
                  fprintf(file, SIRF, al[i][ht - i + j]);
               else
                  fprintf(file, SIRF, al[i][ht - i + j]);
            else
               fprintf(file, "%d ", 0);
         }
      }
      fprintf(file, "\n");
   }
   fprintf(file, "\n");

   //
   //fprintf(file, "заданный x - ");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRFP, F[i]);
   }
}

//дл€ 2 выбора в меню

void Matrix::Writefile2()
{
   FILE* file;
   fopen_s(&file, "output.txt", "w");
   for (int i = 0; i < n; i++)
   {
      if (_finite(F[i]) == 0)
      {
         F[i] = 0;
      }
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i == j)
            fprintf(file, SIRF, di[i]);
         if (j > i)
         {
            if (j - i <= ht)
               if (j < ht)
                  fprintf(file, SIRF, au[j][ht - j + i]);
               else
                  fprintf(file, SIRF, au[j][ht - j + i]);
            else
               fprintf(file, "%d ", 0);
         }
         if (i > j)
         {
            if (i - j <= ht)
               if (i < ht)
                  fprintf(file, SIRF, al[i][ht - i + j]);
               else
                  fprintf(file, SIRF, al[i][ht - i + j]);
            else
               fprintf(file, "%d ", 0);
         }
      }
      fprintf(file, "\n");
   }
   fprintf(file, "\n");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRFPR, F[i]);
   }
}

//дл€ 3 выбора в меню с плотной матрицей

void Matrix::Writefile3()
{
   FILE* file;
   fopen_s(&file, "output.txt", "w");
   //TightMatrix();
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         fprintf(file, SIRFP, A[i][j]);
      }
      fprintf(file, "\n");
   }
   fprintf(file, "\n");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRFPR, F[i]);
   }
}

void Matrix::LU()
{
   for (int i = 0; i < n; i++)
   {
      //int ki = ht - 1;
      for (int k = 0; k < ht && k < i; k++) // диагональные элементы
      {
         if (i >= ht)
            di[i] -= al[i][k]*au[i][k];
         else
            di[i] -= al[i][ht-i+k]*au[i][ht-i+k]; //+++
        // ki--;
      }
      for (int j = 0; j<ht && n-i-j>1; j++)
      {
        // ki = ht - 1;
         for (int k = 0; k < i && k < ht - j - 1; k++) // элементы матрицы U
         {
            if (i >= ht-1 || i + j >= ht - 1)
               au[i+j+1][ht-j-1] -= al[i][k+j+1] * au[i+j+1][k];
            else
               au[i+j+1][ht-j-1] -= al[i][ht-i+k] * au[i+j+1][ht-i+k-j-1];
           // ki--;
         }

      }
      for (int j = 0; j < ht && n - i - j > 1; j++) // элементы матрицы L
      {
         //ki = ht - 2 - j;
         for (int k = 0; k < ht - j - 1 && k < i; k++)
         {
            if (i >= ht-1 || i+j>=ht-1)
               al[j+i+1][ht-j-1] -= al[i+j+1][k] * au[i][k+j+1];
            else
               al[j+i+1][ht-j-1] -= al[i+j+1][ht-i+k-1-j] * au[i][ht-i+k];
            ////ki--;
         }
         al[j+i+1][ht-j-1] /= di[i];
      }
   }

   for (int i = 0; i < n; i++)
   {
      if (_finite(di[i])==0)
      {
         di[i] = 0;
      }
      for (int j = 0; j < ht; j++)
      {
         if (_finite(au[i][j])==0)
            au[i][j] = 0;
         if (_finite(al[i][j])==0)
            al[i][j] = 0;
      }

   }
}

void Matrix::LU_Scalar()
{
   for (int i = 0; i < n; i++)
   {
      //int ki = ht - 1;
      reals sum = 0.0;
      for (int k = 0; k < ht && k < i; k++) // диагональные элементы
      {
         if (i >= ht)
            sum += al[i][k] * au[i][k];
         // di[i] -= al[i][k] * au[i][k];
         else
            sum += al[i][ht - i + k] * au[i][ht - i + k];
           // di[i] -= al[i][ht - i + k] * au[i][ht - i + k]; //+++
         // ki--;
      }
      di[i] -= sum;
      sum = 0.0;
      for (int j = 0; j < ht && n - i - j>1; j++)
      {
         // ki = ht - 1;
         //reals sum = 0.0;
         for (int k = 0; k < i && k < ht - j - 1; k++) // элементы матрицы U
         {
            if (i >= ht - 1 || i + j >= ht - 1)
               sum+= al[i][k + j + 1] * au[i + j + 1][k];
               //au[i + j + 1][ht - j - 1] -= al[i][k + j + 1] * au[i + j + 1][k];
            else
               sum+= al[i][ht - i + k] * au[i + j + 1][ht - i + k - j - 1];
               //au[i + j + 1][ht - j - 1] -= al[i][ht - i + k] * au[i + j + 1][ht - i + k - j - 1];
            // ki--;
         }
         au[i + j + 1][ht - j - 1] -= sum;
         sum = 0.0;
      }
      sum = 0.0;
      for (int j = 0; j < ht && n - i - j > 1; j++) // элементы матрицы L
      {
         //ki = ht - 2 - j;
        // reals sum = 0.0;
         for (int k = 0; k < ht - j - 1 && k < i; k++)
         {
            if (i >= ht - 1 || i + j >= ht - 1)
               sum += al[i + j + 1][k] * au[i][k + j + 1];
               //al[j + i + 1][ht - j - 1] -= al[i + j + 1][k] * au[i][k + j + 1];
            else
               sum += al[i + j + 1][ht - i + k - 1 - j] * au[i][ht - i + k];
               //al[j + i + 1][ht - j - 1] -= al[i + j + 1][ht - i + k - 1 - j] * au[i][ht - i + k];
            ////ki--;
         }
         al[j + i + 1][ht - j - 1] -= sum;
         al[j + i + 1][ht - j - 1] /= di[i];
         sum = 0.0;
      }
   }

   for (int i = 0; i < n; i++)
   {
      if (_finite(di[i]) == 0)
      {
         di[i] = 0;
      }
      for (int j = 0; j < ht; j++)
      {
         if (_finite(au[i][j]) == 0)
            au[i][j] = 0;
         if (_finite(al[i][j]) == 0)
            al[i][j] = 0;
      }

   }
}

void Matrix::LyF_Reverse()
{
   for (int i = 0; i < n; i++)
   {
      //real sum = 0.0;
      for (int j = 0; j < ht && j<i; j++)
      {
         if (i < ht)
         {
            F[i] -= al[i][ht - i + j] * F[j];
         }
         else
         {
            F[i] -= al[i][j] * F[i - ht + j];
         }
      }
   }
}

void Matrix::Uxy_Reverse()
{

   for (int i = n-1; i >= 0; i--)
   {
      //real sum = 0.0;
      for (int j = 0; j < ht && j<n-i-1; j++)
      {
            y[i] -= y[i + j + 1] * au[i+j+1][ht-1-j];
      }
      y[i] /= di[i];
   }
}

void Matrix::Uxy1_Reverse()
{

   for (int i = n - 1; i >= 0; i--)
   {
      //real sum = 0.0;
      for (int j = 0; j < ht && j < n - i - 1; j++)
      {
         F[i] -= F[i + j + 1] * au[i + j + 1][ht - 1 - j];
      }
      F[i] /= di[i];
   }
}

void Matrix::Uxy_Direct() //найдем x
{
   for (int i = 0; i < n; i++)
   {
      y[i] = 0;
      y[i] += di[i] * x[i];
      for (int j = 0; j < ht && j<n-1-i; j++)
      {
         y[i] += au[i+j+1][ht-j-1] *x[i + j+1];
      }
   }
}

void Matrix::LyF_Direct()
{
   for (int i = 0; i < n; i++)
   {
      F[i] = 0;
      for (int j = 0; j < ht && j < i; j++)
      {
         if (i < ht)
         {
            F[i] += al[i][ht - i + j] * y[j];
         }
         else
         {
            F[i] += al[i][j] * y[i-ht + j];
         }
      }
      F[i] += y[i];
   }
}

void Matrix::LyF_Reverse_Scalar()
{
   for (int i = 0; i < n; i++)
   {
      reals sum = 0.0;
      for (int j = 0; j < ht && j < i; j++)
      {
         if (i < ht)
         {
            //F[i] -= al[i][ht - i + j] * F[j];
            sum += al[i][ht - i + j] * F[j];
         }
         else
         {
            //F[i] -= al[i][j] * F[i - ht + j];
            sum += al[i][j] * F[i - ht + j];
         }
      }
      F[i] -= sum;
   }
}
void Matrix::Uxy_Reverse_Scalar()
{
   for (int i = n - 1; i >= 0; i--)
   {
      reals sum = 0.0;
      for (int j = 0; j < ht && j < n - i - 1; j++)
      {
         //y[i] -= y[i + j + 1] * au[i + j + 1][ht - 1 - j];
         sum+= y[i + j + 1] * au[i + j + 1][ht - 1 - j];
      }
      y[i] -= sum;
      y[i] /= di[i];
   }
}
void Matrix::Uxy1_Reverse_Scalar()
{
   for (int i = n - 1; i >= 0; i--)
   {
      real sum = 0.0;
      for (int j = 0; j < ht && j < n - i - 1; j++)
      {
         //F[i] -= F[i + j + 1] * au[i + j + 1][ht - 1 - j];
         sum += F[i + j + 1] * au[i + j + 1][ht - 1 - j];
      }
      F[i] -= sum;
      F[i] /= di[i];
   }
}
void Matrix::Uxy_Direct_Scalar()
{
   for (int i = 0; i < n; i++)
   {
      reals sum = 0.0;
      y[i] = 0;
      sum+= di[i] * x[i];
      //y[i] += di[i] * x[i];
      for (int j = 0; j < ht && j < n - 1 - i; j++)
      {
         //y[i] += au[i + j + 1][ht - j - 1] * x[i + j + 1];
         sum += au[i + j + 1][ht - j - 1] * x[i + j + 1];
      }
      y[i] = sum;
   }
}
void Matrix::LyF_Direct_Scalar()
{
   for (int i = 0; i < n; i++)
   {
      reals sum = 0.0;
      F[i] = 0;
      for (int j = 0; j < ht && j < i; j++)
      {
         if (i < ht)
         {
            //F[i] += al[i][ht - i + j] * y[j];
            sum += al[i][ht - i + j] * y[j];
         }
         else
         {
           // F[i] += al[i][j] * y[i - ht + j];
            sum += al[i][j] * y[i - ht + j];
         }
      }
      sum += y[i];
     // F[i] += y[i];
      F[i] = sum;
   }
}

void Matrix::SLAU1()
{
   LU();
   Uxy_Direct();

   Uxy_Reverse();
   /*for (int i = 0; i < n; i++)
   {
      cout << x[i] << ' ';
   }
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      cout << y[i] << ' ';
   }
   cout << endl;*/
   Uxy_Direct();
   LyF_Direct();
   LyF_Reverse();
   /*for (int i = 0; i < n; i++)
   {
      cout << y[i] << ' ';
   }
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      cout << F[i] << ' ';
   }
   cout << endl;*/
   LyF_Direct();
}

void Matrix::SLAU1_Scalar()
{
   LU_Scalar();
   Uxy_Direct();

   // Uxy_Reverse();
   /*for (int i = 0; i < n; i++)
   {
      cout << x[i] << ' ';
   }
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      cout << y[i] << ' ';
   }
   cout << endl;*/
   //  Uxy_Direct();
   LyF_Direct_Scalar();
   //LyF_Reverse();
   /*for (int i = 0; i < n; i++)
   {
      cout << y[i] << ' ';
   }
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      cout << F[i] << ' ';
   }
   cout << endl;*/
  // LyF_Direct();
}



void Matrix::SLAU2()
{
   LU();
   LyF_Reverse();
   Uxy1_Reverse();

}

void Matrix::SLAU2_Scalar()
{
   LU_Scalar();
   LyF_Reverse_Scalar();
   Uxy1_Reverse_Scalar();
}

void Matrix::SLAU3()
{
   LU();
   Uxy_Direct();
   LyF_Direct();
   cout << "¬ведите k:" << endl;
   int k = 0;
   real tenk = 1;
   cin >> k;
   for (int i = 0; i < k; i++)
   {
      tenk /= 10;
   }
   di[0] += tenk;
   F[0] += tenk;
   LyF_Reverse();
   Uxy1_Reverse();
}

void Matrix::TightMatrix()
{
   A.resize(n);
   for (int i = 0; i < n; i++)
      A[i].resize(n);

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i == j)
            A[i][j]= di[i];
         if (j > i)
         {
            if (j - i <= ht)
               if (j < ht)
                  A[i][j] = au[j][ht - j + i];
               else
                  A[i][j] = au[j][ht - j + i];
            else
               A[i][j] = 0;
         }
         if (i > j)
         {
            if (i - j <= ht)
               if (i < ht)
                  A[i][j] = al[i][ht - i + j];
               else
                  A[i][j] = al[i][ht - i + j];
            else
               A[i][j] = 0;
         }
      }
   }
}

void Matrix::Gauss()
{
   for (int i = 1; i < n; i++)
      for (int j = i; j < n; j++)
      {
         real m = A[j][i - 1] / A[i - 1][i - 1];
         for (int k = 0; k < n; k++)
            A[j][k] = A[j][k] - m * A[i - 1][k];
         F[j] = F[j] - m * F[i - 1];
      }
   for (int k = n - 1; k >= 0; k--)
   {
      real buf = 0;
      for (int j = k + 1; j < n; j++)
      {
         buf += A[k][j] * F[j];
      }
      F[k] = F[k] - buf;
      F[k] = F[k] / A[k][k];
   }
   FinddetA();
}

void Matrix::FinddetA()
{
   for (int i = 0; i < n; i++)
   {
      detA *= A[i][i];
   }
}

vector<real> Matrix::Multiplication(vector<vector<real>> &a, vector<real> &e, vector<real> &x)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         x[i] += A[i][j] * e[j];
      }
   }
   return x;
}

void Matrix::FindAReverse()
{
   TightMatrix();
   Areverse.resize(n);
   for (int i = 0; i < n; i++)
      Areverse[i].resize(n);
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         F[j] = 0;
      }
      F[i] = 1;
      Areverse[i] = Multiplication(A, F, x);
   }
}

void Matrix::GilbertMatrix()
{
   //cout << "¬ведите размерность матрицы";
   ht = n - 1;
   F.resize(n);
   x.resize(n);
   y.resize(n);
   di.resize(n);
   al.resize(n);
   au.resize(n);
   for (int i = 0; i < n; i++)
   {
      di[i] = 1.0 / ((i + 1) * 2 - 1);
   }
   for (int i = 0; i < n; i++)
   {
      al[i].resize(ht);
      au[i].resize(ht);
      for (int j = ht-i; j < ht; j++)
      {
         al[i][j] = 1.0/(i + (j-ht+i) + 1);
         au[i][j] = 1.0/(i + (j-ht+i) + 1);
      }
   }
   FILE* file;
   fopen_s(&file, "gilbert.txt", "w");
   fprintf(file, "%d ", n);
  // fprintf(file, "\n");
   fprintf(file, "%d ", ht);
   fprintf(file, "\n");

   for (int i = 0; i < n && ht!=0; i++)
   {
      for (int j = 0; j < ht; j++)
      {
         fprintf(file, SIRFP, al[i][j]);
      }
      fprintf(file, "\n");
   }
   for (int i = 0; i < n && ht != 0; i++)
   {
      for (int j = 0; j < ht; j++)
      {
         fprintf(file, SIRFP, au[i][j]);
      }
      fprintf(file, "\n");
   }
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRFP, di[i]);
   }
  // cout << "¬ведите F" << endl;
  // for (int i = 0; i < n; i++)
  // {
  //    cin >> F[i];
  // }
}