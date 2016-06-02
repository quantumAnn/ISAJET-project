// H. Ann Summy
// Wednesdsay, November 10, 2004
/* This program integrates one-dimensional functions using the following
    three methods: Newton-Cotes, Trapezoidal, and 3-point Simpson. The
    three methods are listed as functions in a program named "integrate.cc"
    linked through a header file called "integrate.h". */
    
#include <iostream>
#include <cmath>
#include "integrate.h"


double fx(double x){
  return x;
}

double fxxx(double x){
  return x*x*x;
}

double fexpx(double x){
  return exp(x*x);
}


double firstrect, firsttrap, firstsimp;
double secondrect, secondtrap, secondsimp;
double thirdrect, thirdtrap, thirdsimp;
double fourthrect, fourthtrap, fourthsimp;

int main()
{
  firstrect= rect(fx,1,2,10);
  firsttrap= trap(fx,1,2,10);
  firstsimp= simp(fx,1,2,10);
  
  secondrect= rect(fxxx,0,2*M_PI,15);
  secondtrap= trap(fxxx,0,2*M_PI,15);
  secondsimp= simp(fxxx,0,2*M_PI,15);
  
  thirdrect= rect(fexpx,1,2,20);
  thirdtrap= trap(fexpx,1,2,20);
  thirdsimp= simp(fexpx,1,2,20);
  
  fourthrect= rect(fexpxx,-3,3,50);
  fourthtrap= trap(fexpxx,-3,3,50);
  fourthsimp= simp(fexpxx,-3,3,50);
  
  
  cout<<endl<<"The integral of xdx from x=1 to x=2 is"<<endl
      <<"Newton-Cotes method:  "<<firstrect<<endl
      <<"trapezoidal method:  "<<firsttrap<<endl
      <<"3-point Simpson method:  "<<firstsimp<<endl<<endl;
  cout<<"The integral of x^3 from x=0 to x=2*pi is"<<endl
      <<"Newton-Cotes method:  "<<secondrect<<endl
      <<"trapezoidal method:  "<<secondtrap<<endl
      <<"3-point Simpson method:  "<<secondsimp<<endl<<endl;
  cout<<"The integral of exp(x) from x=1 to x=2 is"<<endl
      <<"Newton-Cotes method:  "<<thirdrect<<endl
      <<"trapezoidal method:  "<<thirdtrap<<endl
      <<"3-point Simpson method:  "<<thirdsimp<<endl<<endl;
  cout<<"The integral of exp(x^2) from x=-3 to x=3 is"<<endl
      <<"Newton-Cotes method:  "<<fourthrect<<endl
      <<"trapezoidal method:  "<<fourthtrap<<endl
      <<"3-point Simpson method:  "<<fourthsimp<<endl<<endl;
      
  return 0;
}
