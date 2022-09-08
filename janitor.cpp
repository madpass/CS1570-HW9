//Programmer: Madison Passolano   ID: 12560375
//File: janitor.cpp               Date: 04-16-2020
//Purpose: the janitor functions file  

#include "lunch.h"
#include "school.h"
#include "janitor.h"

 

/*---------------------------JANITOR---------------------------------------*/

Janitor::Janitor()
{
  set_name("name"); 
  set_state("sober");
  set_bac(0.05); 
  set_bruises(0); 
  set_x(-1); 
  set_y(-1); 
}

Janitor::Janitor(const string name)
{
  set_name(name); 
  set_state("sober"); 
  set_bac(0.05);
  set_bruises(0);
  set_x(-1);
  set_y(-1);
}

void Janitor::place_me(School& s)
{
  //initialize placeholders 
  int val, j; 
  
  //this finds the middle point of the array (it should)
  val = s.get_size()/2;  

  //set the new location in janitor within janitor 
  set_x(val); 
  set_y(val); 

  //gets the 'J' value for the janitor to put into the array
  j = get_piece();

  //this sends it to the School object that was used as the parameter 
  s.set_jan(val, val, j); 

  return; 
 
}

void Janitor::rand_walk(School& s)
{
  int dir, x, y;         //place holder for the direction value, and the x and y coord
  char val;              //hold the value returned from the school array 
  bool done = false;     //determines whether the do while loop is done 
  x = get_x();           //get his location from janitor
  y = get_y(); 

  do
  { 
    dir = rand() % 4;  
    if(dir == 0)
    { 
      x++;
      val = s.get_value(x, y);
      if(val == ' ')
      { 
        set_x(x);
        done = true; 
      }
      else 
      {
        x--;
      }
    }
    else if(dir==1)
    {
      y++;
      val = s.get_value(x, y);
      if(val == ' ')
      { 
        set_y(y);
        done = true; 
      }
      else 
      {
        y--;
      } 
    }
    else if(dir==2)
    {
      x--;
      val = s.get_value(x, y); 
      if(val == ' ')
      {
        set_x(x); 
        done = true; 
      }
      else
      {
        x++;
      }
    }
    else if(dir==3)
    {
      y--; 
      val = s.get_value(x, y); 
      if(val == ' ')
      { 
        set_y(y);
        done = true; 
      } 
      else
      {
        y++;
      }
    }
  }while(done == false);

  s.set_jan(x, y, get_piece());
  //sends the new x and y coord and character representation of janitor back to school 
}

void Janitor::print()
{
  cout<<"\nJanitor Name: "<<m_name<<endl;
  cout<<"Blood alcohol Content: "<<m_bac<<endl;
  cout<<"Number of bruises: "<<m_bruises<<endl;
  cout<<"Janitor State: "<<m_state<<endl; 
}
















