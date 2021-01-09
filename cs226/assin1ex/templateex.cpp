#include <stddef.h>
#include <assert.h>

template<class T>
templateex<T>::templateex()
{
cout<<"Constructor Executing"<<endl;

noValidEntries=0;
}
template<class T>
templateex<T>::~templateex()
{

cout<<"Destructor Executing"<<endl;
makeEmpty();
}//end destructor

template<class T>
void templateex<T>::makeEmpty()
{


for (int i=0;i<noValidEntries;i++)
{
  //loop to remove all entries
}          
}//end make empty

template <class T>
void templateex<T>::Insert(T NewItem, bool& Success)
{   // create a new node
    //properly insert into its proper position
   //increment noValidEntries     
           
     if (noValidEntries==SIZE)
     {

        Success=false;
     }
     else
     {
       Success=true;
       example[noValidEntries]=NewItem;
       noValidEntries++;
     }
} // end insert
template <class T>
void templateex<T>::Display()
{
  for (int i=0;i<noValidEntries;i++)
  {
   cout<<"next = "<<example[i]<<endl;
  }//end for
}//end Display

  

template <class T>
templateex<T>& templateex<T>::operator = (const templateex <T>&Rhs)
{

  cout<<"equal uwu\n";
//check for assignment to self
//Remember what has to be returned for chaining
}//end of =


//end of implementation file
