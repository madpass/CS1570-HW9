//Programmer: Madison Passolano   ID: 12560375
//File: lunch.cpp                 Date: 04-16-2020
//Purpose: the lunch functions file 

#include "lunch.h"
#include "school.h"
#include "janitor.h"



Lunch::Lunch()
{
  set_x(-1); 
  set_y(-1);
}

void Lunch::place_me(School& s)
{
  int size, min, max, x, y;
  char val; 
  bool done = false;  

  size = s.get_size(); //gets size of the school 
  min = 1;             //minimum value 
  max = size -1;       //max value without hitting boarders 

  do
  {
    x = min + rand() % ((max + 1) - min);
    y = min + rand() % ((max + 1) - min);
    //random place in grid 

    val = s.get_value(x, y); 
    if(val == ' ')
    {
      s.set_lunch(x, y, get_lun_piece());
      done = true; 
    }

  }while(done == false);

  set_x(x); 
  set_y(y); 
  return; 
}

void Lunch::rand_walk(School& s)
{
  //look at the janitor one for reference 
  int dir, x, y, max, min; 
  char val;
  bool done = false;  
  x = get_x(); //get his location from janitor
  y = get_y(); 
  max = s.get_size() - 2; 
  min = 2; 

  do
  { 
    dir = rand() % 4;  
    if(dir == 0)
    { 
      if(x<max)
      {
        x++; 
        val = s.get_value(x, y);
        if(val == ' ')
        {
          set_x(x);
          done = true; 
        }
      }
    }

    else if(dir==1)
    {
      if(y<max)
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
    }
    
    else if(dir==2)
    {
      if(x>min)
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
    }
    else if(dir==3)
    {
      if(y>min)
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
    } 
  }while(done == false);
  s.set_lunch(x, y, get_lun_piece());
}











