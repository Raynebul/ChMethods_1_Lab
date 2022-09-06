#include <fstream>
#include "Matrix.h"

using namespace std;


int main()
{
   Matrix object;
   object.Readfile();
   object.SLAU();
   object.Writefile();
   return 0;
}