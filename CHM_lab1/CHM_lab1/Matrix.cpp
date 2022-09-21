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
         fscanf_s(file, SIRF, &F[i]);

   }
   fclose(file);
   return 0;
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
   for (int i = 0; i < n; i++)
   {
      fprintf(file, SIRF, F[i]);
   }
   fclose(file);
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
      int ki = ht-1;
      for (int k = 0; k<ht && k<i; k++) //i=j
      {
         if (i >= ht)
            di[i] -= al[i][k] * au[k+i-ht][ki]; //+++
         else
            di[i] -= al[i][ht-i+k] * au[k][i-k-1]; //+++
         ki--;
      }
      for (int j = 0; j < ht && n-i-j>1; j++)
      {
         ki = ht-1;
         for (int k = 0; k < i && k<ht-j-1; k++)
         {
            if (i >= ht)
               au[i][j] -= al[i][k+1+j] * au[k+i-ht+1+j][ki]; //++
            else
               au[i][j] -= al[i][ht-i+k] * au[k][i-k]; //++
            ki--;
         }
      }
      for (int j = 0; j < ht && n-i-j>1; j++)
      {
         ki = ht-2-j;
         for (int k = 0; k<ht-j-1 && k<i; k++)
         {
            if (i >= ht)
               al[j+i+1][ht-j-1] -= al[j+i+1][k] * au[i-ht+1+k+j][ki]; //++
            else
               al[j+i+1][ht-j-1] -= al[j+i+1][k+i-j] * au[k][i-k-1]; //++

            ki--;
         }
         al[j+i+1][ht-j-1] /= di[i];
      }
   }
}

void Matrix::LU2()
{
   for (int i = 0; i < n; i++)
   {
      //int ki = ht - 1;
      for (int k = 0; k < ht && k < i; k++) //i=j
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
         for (int k = 0; k < i && k < ht - j - 1; k++)
         {
            if (i >= ht-1 || i + j >= ht - 1)
               au[i+j+1][ht-j-1] -= al[i][k+j+1] * au[i+j+1][k];
            else
               au[i+j+1][ht-j-1] -= al[i][ht-i+k] * au[i+j+1][ht-i+k-j-1];
           // ki--;
         }
      }
      for (int j = 0; j < ht && n - i - j > 1; j++)
      {
         //ki = ht - 2 - j;
         for (int k = 0; k < ht - j - 1 && k < i; k++)
         {
            if (i >= ht-1 || i+j>=ht-1)
               al[j+i+1][ht-j-1] -= al[i+j+1][k] * au[i][k+j+1]; // добавим +1
            else
               al[j+i+1][ht-j-1] -= al[i+j+1][ht-i+k-1-j] * au[i][ht-i+k];
            ////ki--;
         }
         al[j+i+1][ht-j-1] /= di[i];
      }
   }
}

void Matrix::LyF()
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

void Matrix::Uxy()
{

   for (int i = n-1; i >= 0; i--)
   {
      //real sum = 0.0;
      for (int j = 0; j < ht && j<n-i-1; j++)
      {
            F[i] -= F[i + j + 1] * au[i+j+1][ht-1-j];
      }
      F[i] /= di[i];
   }
}

void Matrix::Multiplication()
{

}

void Matrix::SLAU()
{
   LU2();
   LyF();
   Uxy();
}