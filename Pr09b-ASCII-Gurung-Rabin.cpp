/*
School  : Contra Costa College 
Term    : 2017 Spring
Course  : Comp-251-2384
          Fundamentals of Computer Science with C++

Chapter : 9
Program : Pr08a-Patient-Gurung-Rabin.cpp
Author  : Gurung, Rabin
Date    : Mar. 28, 2017

Sample
Purpose : Learn about the some of the ways in which 
          a computer represents stored data. These 
          ways include the:

          -- binary representation of integers
  
          -- hexadecimal shorthand for binary 
 
          -- American Standard Code for Information 
             Interchange to represent character

Sample 
Problem : To the console, output a table of ASCII
          characters, along with their equivalent 
          binary, decimal, and hexadecimal values.
     
          Prompt the user to input a beginning and
          ending character value for which to
          produce such table. Validate the 
          values. Type cast them to integers.
          
          Output a table with 4 columns, one each 
          for character, decimal, binary and 
          hexadecimal.
  
          Return to the operating system the count 
          of records processed, where a batch file
          should output the count as its error level.

Submit : Two files simultaneously, both with the
         same name, except for the extension:
         -- source (.cpp) file
         -- batch  (.bat) file
        
            
Sample
Output : Pr09b-ASCII.jpg

web    : http://www.asciitable.com/
*/ 

//+++++++++++++++++++++++++++++++++++++++
//Preprocessor Directives
//_______________________________________

#include <bitset>
#include <iomanip>
#include <iostream>

using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++
//Function Prototypes
//-------------------------------------------

void putHead();
char getBeg ();
char getEnd (char);
int  putTab (char, char);

//==============================================
//Main Routine
//**********************************************

int main ()
{
  //Declare variables
  
  char beg;  //Beginning value
  char end;  //Ending    value
 
  int count; //Count of records processed
 
  //To the console, output the program heading

  putHead();

  //From the console, input beginning and
  //ending values
 
  beg = getBeg();     //Input beginning value
  
  end = getEnd(beg);  //Input ending    value
 
  //To the console, output the table, and return 
  //count to the operating system

  count = putTab(beg, end);

  return count;
  
}

//============================================
//Level 1 Function
//********************************************

void putHead()
{
  cout <<                                       endl; 
  cout <<"ASCII Program"                     << endl;
  cout <<                                       endl; 
  cout <<"This program outputs part of an"   << endl; 
  cout <<"American Standard Code for "       << endl; 
  cout <<"Information Interchange table"     << endl;
  cout <<                                       endl; 
  cout <<"Enter a beginning value between"   << endl;
  cout <<"! and ~, and an ending value"      << endl; 
  cout <<"between the beginning value and ~" << endl; 
  cout <<                                       endl;
}

char getBeg()
{
  //Input and validate a beginning value
 
  //Declare variables
 
  char beg; 

  //At the console, input and validate the value 
  
  while (true)
 
  {
   
    cout << "Beg? ";
    cin  >>  beg;
 
    if (beg < '!' || beg > '~')
      cout << "Invalid \a\n";
  
    else
      break;
   }
    
   return beg;
}

char getEnd(char beg)
{
 
  //Input and validate a ending value
 
  //Declare variables
 
  char end; 

  //At the console, input and validate the value 
  
  cout << endl;

  while (true)
 
  {
   
    cout << "End? ";
    cin  >>  end;
 
    if (end < beg || end > '~')
      cout << "Invalid \a\n";
  
    else
      break;
  }
   
    return end;
}

int putTab (char beg, char end)
{
  //Output part of an ASCII table
 
  //Declare the variables

  char c;    //Loop index
  
  int count; //Count of records processed

  //Initialize variables
  
  count = 0;

  //To the console, output column heading
  
  cout <<                               endl;
  cout << "Char  Dec       Bin  Hex" << endl;
  cout << "----  ---  --------  ---" << endl; 
  cout <<                               endl;
  
  //Ton the console, output the table
  
  for (c = beg; c <= end; c++)
  {
    cout << setw (4)            <<      c;
    cout << setw (5)  << dec    << int(c); //Typecasting
    cout << setw (10) << bitset<8>(int(c));
    cout << setw (5)  << hex    << int(c) << endl;
    
    count++;
  }
   return count;
}