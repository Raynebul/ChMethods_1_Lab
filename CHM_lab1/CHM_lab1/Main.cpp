
#include "Matrix.h"


using namespace std;


int main()
{
   setlocale(LC_CTYPE, "Russian");
   Matrix object;
   int flag = 0;
   int endnumber = 0;
   cout << "1 - ���������� LU � ���������� ������� F" << endl;
   cout << "2 - ���������� LU � ���������� ������� x" << endl;
   cout << "3 - ����� ������" << endl;
   cout << "4 - ����������� �������" << endl;
//   cout << "5 - ���������� LU � ���������� ������� x (���������)" << endl;
  // cout << "6 - ������������ �� k" << endl;
   cout << "5 - ����� �� ����" << endl;

   while (!endnumber)
   {
      cin >> flag;
      switch (flag)
      {
         case 1:
         {
            object.Readfile3(object.x);
            if (object.flag==true) {
               cout << "������: ������ ����� ������ ����� ������� ";
               return 0;
            }
            //
              // 
            //}
            object.SLAU1();
            //object.SLAU1_Scalar();
          //  cout << 1 << endl;
           object.Writefile1();
            //object.Writefile1_Scalar();
            break;
         }
         case 2:
         {
            object.Readfile3(object.F);
            if (object.flag == true) {
               cout << "������: ������ ����� ������ ����� ������� ";
               return 0;
            }
            //object.SLAU2();
            object.SLAU2_Scalar();
            object.Writefile2();
            break;

         }
         case 3:
         {
            object.Readfile3(object.F);
            if (object.flag == true) {
               cout << "������: ������ ����� ������ ����� ������� ";
               return 0;
            }
            object.TightMatrix();
            object.Gauss();
            //object.FindAReverse();
            object.Writefile3();
            break;
         }
         case 4:
         {
            //endnumber = 1;
            cout << "������� n" << endl;
            cin >> object.n;

            object.GilbertMatrix();
            break;
         }
         case 5:
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