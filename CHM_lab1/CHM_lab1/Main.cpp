#include <fstream>
#include "Matrix.h"


using namespace std;


int main()
{
   setlocale(LC_CTYPE, "Russian");
   Matrix object;
   int flag = 0;
   int endnumber = 0;
   cout << "1 - Разложение LU и нахождение вектора x" << endl;
   cout << "2 - Выход из меню" << endl;

   while (!endnumber)
   {
      cin >> flag;
      switch (flag)
      {
         case 1:
         {
            object.Readfile1();
            if (flag) {
               cout << "ОШИБКА: Ширина ленты больше самой матрицы ";
               return 0;
            }
            //
              // 
            //}
            object.SLAU();
            cout << 1 << endl;
            object.Writefile1();
            break;
         }
         case 2:
         {
            endnumber = 1;
            break;
         }
         default:
         {
            cout << "???";
            break;
         }
      }
   }

   return 0;
}