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
      ht = (m - 1) / 2;
   }
}

void Matrix::Readfile1()
{
   FILE* file;
   fopen_s(&file, "input.txt", "r");
   fscanf_s(file, "%d", &n);
   fscanf_s(file, "%d", &m);
   ht = (m - 1) / 2;
   F.resize(n);
   di.resize(n);
   al.resize(n);
   au.resize(n);
   while (!feof(file))
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
   cout << endl;
}

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
         if (i < j)
            if (j - i <= m / 2)
               fprintf(file, SIRF, au[i][i - j + m / 2]);
            else
               fprintf(file, "%d ", 0);
         if (i > j)
            if (i - j <= m / 2)
               fprintf(file, SIRF, al[i][j - i + m / 2]);
            else
               fprintf(file, "%d ", 0);
      }
      fprintf(file, "\n");
   }
   fprintf(file, "\n");
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRF, F[i]);
   }

}

void Matrix::LU()
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         real ki, kj;
         if (i <= j)
         {
            real sum = 0;
            for (int k = 0; k < i; k++)
            {
               ki = k - i + m / 2;
               kj = k - j + m / 2;
               //if (i - k <= m / 2 && j - k <= m / 2)
               if (ki >= 0 && kj >= 0)
                  sum += al[i][ki] * au[k][kj];
            }
            if(i==j)
              di[i] = di[i] - sum;
            else
               if (j - i <= m / 2)
                  au[i][i - j + m / 2] = au[i][i - j + m / 2] - sum;
         }
         else
         {
            real sum = 0;
            for (int k = 0; k < j; k++)
            {
               ki = k - i + m / 2;
               kj = k - j + m / 2;
               // if (i - k <= m / 2 && j - k <= m / 2)
               if (ki >=0 && kj>=0)
                  sum += al[i][ki] * au[k][kj];
            }
            if (i - j <= m / 2)
               al[i][j - i + m / 2] = (al[i][j - i + m / 2] - sum) / di[j];
         }
      }
   }
}

void Matrix::LU1()
{ 
   for (int i = 0; i < n; i++)
   {
      int ki = ht - 1;
      for (int k = 0; k<ht && k<i; k++)
      {
         di[i] -= al[i][k] * au[i-ki-1][ki];
         ki--;
      }
      for (int j = 0; j < ht; j++)
      {
         ki = ht-1-j;
         for (int k = 0; k < i && k<ht-1; k++)
         {
            au[i][j] -= al[i][k]*au[k][ki];
            ki--;
         }
      }
      for (int j = 0; j < ht && n-i-j>1; j++)
      {
         ki = ht-1-j;
         for (int k = 0; k < j && k<ht-1; i++)
         {
            al[j+i+1][ht-j-1] -= al[j+i+1][k] * au[i-j-1+k][ki];
            ki--;
         }
         al[j+i+1][ht-j-1] /= di[i];
      }
   }
}

void Matrix::LyF()
{
  /* for (int i = 0; i < n; i++)
   {
      cout << F[i] << ' ';
   }
   */
   //cout << endl;
   for (int i = 0; i < n; i++)
   {
      real sum = 0.0;
      for (int j = 0; j < m/2; j++)
      {
         if(i+j>=m/2)
         {
            sum += F[i-m/2+j] * al[i][j];
         }
         F[i] = F[i] - sum;
      }
   }
   /*for (int i = 0; i < n; i++)
   {
      cout << F[i] << ' ';
   }
   cout << endl; */
}

void Matrix::Uxy()
{

   for (int i = n-1; i >= 0; i--)
   {
      real sum = 0.0;
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
 /*  for (int i = 0; i < n; i++)
   {
      cout << F[i] << ' ';
   } */
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