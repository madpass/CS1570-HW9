//Programmer: Madison Passolano  ID: 12560375
//File: main_hw9.cpp             Date: 04-16-2020
//Purpose: what controls the whole program 

#include "lunch.h"
#include "school.h"
#include "janitor.h"

char Janitor::m_jan_piece = 'J'; 
char Lunch::m_lun_piece = 'L';
//using static member variables so you have to declare them in main 

int main()
{
  srand(time(NULL)); 
  //seeds the time 

  School sch1(10);          //default school 
  Janitor jan1;             //default janitor 
  Janitor jan2("Willie");   //specified janitor 
  Lunch lun1;               //default lunch 

  cout<<"\nJanitors: "<<endl; 
  jan1.print();   //prints the stats of the janitor
  jan2.print(); 
    
  cout<<"Start: "<<endl; 
  jan1.place_me(sch1);   //places the J in the middle of the grid
  lun1.place_me(sch1);   //places the L in a random cell of the grid 
  sch1.print_whole();    //print 

  for(int i=0; i<5; i++)
  {
    sch1.build_arr();       //builds the array kinda clears it 
    jan1.rand_walk(sch1);   //places the J in a new location 
    lun1.rand_walk(sch1);   //places the L in a new location 
  }
  cout<<"\nEnd: "<<endl; 
  sch1.print_whole();   //prints entire grid in proper format

  return 0; 
}