#include "Matrix.h"

void Matrix::Readfile()
{
   ifstream fin("input.txt");
   if (!fin.is_open()) // если файл не открыт
      cout << "Файл не может быть открыт!\n"; // сообщить об этом
   else
   {
      fin >> n >> m;
      Matrix.resize(n);
      F.resize(n);
      di.resize(n);
      al.resize(n);
      au.resize(n);
      //U.resize(n);
      //L.resize(n);

      for (int i = 0; i < n; i++)
      {
         al[i].resize(m/2);
         for (int j = 0; j < m / 2; j++)
         {
            fin >> al[i][j];
         }
      }
      for (int i = 0; i < n; i++)
      {
         au[i].resize(m/2);
         for (int j = 0; j < m / 2; j++)
         {
            fin >> au[i][j];
         }
      }
      for (int i = 0; i < n; i++)
         fin >> di[i];
      for (int i = 0; i < n; i++)
         fin >> F[i];
   }
}

//void Matrix::Writefile()
//{
//   ofstream fout;
//   for (int i = 0; i < n; i++)
//   {
//      for (int j = 0; j < n; j++)
//      {
//         cout << L[i][j] << ' ';
//      }
//      cout << endl;
//   }
//   cout << endl;
//   for (int i = 0; i < n; i++)
//   {
//      for (int j = 0; j < n; j++)
//      {
//         cout << U[i][j] << ' ';
//      }
//      cout << endl;
//   }
//}

void Matrix::Writefile1()
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (i == j)
            cout << di[i] << ' ';
         if (i < j)
            if (j - i <= m / 2)
               cout << au[i][i - j + m / 2] << ' ';
            else
               cout << 0 << ' ';
         if (i > j)
            if (i - j <= m / 2)
               cout << al[i][j - i + m / 2] << ' ';
            else
               cout << 0 << ' ';
      }
      cout << endl;
   }
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      cout << F[i] << ' ';
   }
}

//void Matrix::LU()
//{
//   for (int i = 0; i < n; i++)
//   {
//      for (int j = 0; j < n; j++)
//      {
//         U[i].resize(n);
//         L[i].resize(n);
//         if (i == j)
//         {
//            L[i][j] = 1;
//            int sum = 0;
//            for (int k = 0; k < i; k++)
//            {
//               sum += L[i][k] * U[k][j];
//            }
//            U[i][j] = di[i] - sum;
//         }
//         if (i < j)
//         {
//            int sum = 0;
//            for (int k = 0; k < i; k++)
//            {
//               sum += L[i][k] * U[k][j];
//            }
//            if (j-i > m/2)
//               U[i][j] = 0 + sum;
//            else
//               U[i][j] = au[i][i-j+m/2] - sum;
//         }
//         if (i > j)
//         {
//            int sum = 0;
//            for (int k = 0; k < j; k++)
//            {
//               sum += L[i][k] * U[k][j];
//            }
//            if (i-j > m/2)
//               L[i][j] = (0 + sum)/U[j][j];
//            else
//               L[i][j] = (al[i][j-i+m/2] - sum)/U[j][j];
//         }
//      }
//   }
//}

void Matrix::LU1()
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
               if (i - k > m / 2 || j - k > m / 2)
                  sum += 0;
               else
                  sum += al[i][k-i+m/2] * au[k][k-j+m/2];
            }
            di[i] = di[i] - sum;
         }
         if (i < j)
         {
            int sum = 0;
            for (int k = 0; k < i; k++)
            {
               if (i - k > m / 2 || j - k > m / 2)
                  sum += 0;
               else
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
               if (i - k > m / 2 || j - k > m / 2)
                  sum += 0;
               else
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
      double sum = 0.0;
      for (int j = 0; j < m/2; j++)
      {
         if(i+j>=m/2)
         {
            sum += F[j] * al[i][j];
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
         if (n-1-i+j >= m / 2)
         {
            sum += F[j] * au[i][j];
         }
         F[i] = (F[i] - sum) / di[i];
      }
   }
}

void Matrix::Multiplication()
{

}

void Matrix::SLAU()
{
   LU1();
   LyF();
   Uxy();
}