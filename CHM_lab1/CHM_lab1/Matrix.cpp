#include "Matrix.h"

void Matrix::Readfile()
{
   ifstream fin("input.txt");
   if (!fin.is_open()) // если файл не открыт
      cout << "Файл не может быть открыт!\n"; // сообщить об этом
   else
   {
      fin >> n >> m;
      //Matrix.resize(n);
      F.resize(n);
      di.resize(n);
      al.resize(n);
      au.resize(n);

      for (int i = 0; i < n; i++)
      {
         al[i].resize(m/2);
         for (int j = 0; j < m / 2; j++)
            fin >> al[i][j];
      }
      for (int i = 0; i < n; i++)
      {
         au[i].resize(m/2);
         for (int j = 0; j < m / 2; j++)
            fin >> au[i][j];
      }
      for (int i = 0; i < n; i++)
         fin >> di[i];
      for (int i = 0; i < n; i++)
         fin >> F[i];
   }
}

void Matrix::Writefile()
{
   ofstream fout("output.txt");
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i == j)
            fout << di[i] << ' ';
         if (i < j)
            if (j - i <= m / 2)
               fout << au[i][i - j + m / 2] << ' ';
            else
               fout << 0 << ' ';
         if (i > j)
            if (i - j <= m / 2)
               fout << al[i][j - i + m / 2] << ' ';
            else
               fout << 0 << ' ';
      }
      fout << endl;
   }
   fout << endl;
   for (int i = 0; i < n; i++)
   {
      fout << F[i] << ' ';
   }
}

void Matrix::LU()
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i == j)
         {
            int sum = 0;
            for (int k = 0; k < i; k++)
            {
               if (i - k <= m / 2 && j - k <= m / 2)
                  sum += al[i][k - i + m / 2] * au[k][k - j + m / 2];              
            }
            di[i] = di[i] - sum;
         }
         if (i < j)
         {
            int sum = 0;
            for (int k = 0; k < i; k++)
            {
               if (i - k <= m / 2 && j - k <= m / 2)
                  sum += al[i][k - i + m / 2] * au[k][k - j + m / 2];
            }
            if (j - i <= m / 2)
               au[i][i - j + m / 2] = au[i][i - j + m / 2] - sum;
         }
         if (i > j)
         {
            int sum = 0;
            for (int k = 0; k < j; k++)
            {
               if (i - k <= m / 2 && j - k <= m / 2)
                  sum += al[i][k - i + m / 2] * au[k][k - j + m / 2];
            }
            if (i - j <= m / 2)
               al[i][j - i + m / 2] = (al[i][j - i + m / 2] - sum) / di[j];
         }
      }
   }
}

void Matrix::LyF()
{
   for (int i = 0; i < n; i++)
   {
      cout << F[i] << ' ';
   }
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      double sum = 0.0;
      for (int j = 0; j < m/2; j++)
      {
         if(i+j>=m/2)
         {
            sum += F[i-m/2+j] * al[i][j];
         }
         F[i] = F[i] - sum;
      }
   }
   for (int i = 0; i < n; i++)
   {
      cout << F[i] << ' ';
   }
   cout << endl;
}

void Matrix::Uxy()
{

   for (int i = n-1; i > 0; i--)
   {
      double sum = 0.0;
      for (int j = 0; j < m/2; j++)
      {
         if (n-1-i-j > 0)
         {
            //sum += F[i+j+1] * au[i][j];
            F[i] -= F[i + j + 1] * au[i][j];
         }
         //F[i] = (F[i] - sum) / di[i];
         F[i] /= di[i];
      }
   }
   for (int i = 0; i < n; i++)
   {
      cout << F[i] << ' ';
   }
}

void Matrix::Multiplication()
{

}

void Matrix::SLAU()
{
   LU();
   LyF();
   Uxy();
}