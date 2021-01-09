#include "templateex.h"
int main()
{
 templateex<int>example1;
 templateex<char>example2;
 templateex<int>example3;
 
 bool Success;
 example1.Insert(5,Success);
 example1.Insert(6,Success);
 example1.Display();
 example2.Insert('a',Success);
 example2.Display();
 example3 = example1;
 example3.Display();
 cout<<"main exiting"<<endl;
}//end main
