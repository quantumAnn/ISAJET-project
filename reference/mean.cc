// H. Ann Summy
// Wednesday, November 17, 2004
/* This program evaluates the integral of sin(2xy)dxdy from 
x,y=0 to x,y=pi using the Monte Carlo mean value technique. */


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>


double Nf=0; N;  //count of points under function and box
double x, y, f, xmax=M_PI, ymax=M_PI;
double sum; //container for function values
double drand48(void);
void srand48(long int seedval);
time_t t;
long int seed;


int main()
{
  cerr << "Enter the number of total points to use:  ";
  cin >> N;
  cout<<"# N \tlog(N) \t\tIntegral Value"<<endl
      <<"# - \t------ \t\t--------------"<<endl;
      
  for (int j=0; j<10; j++) {
    //srand48(time(&t));
    seed= abs(time(&t)*(j+5));
    //cout<<seed<<"  \t";
    srand48(seed);
    sum=0;
    
    for (int i=0; i<N; i++) {
     x= xmax*drand48();
      y= ymax*drand48();
      f= sin(2*x*y);
      if (f>y) Nf++;
      sum += f;
    }
    
    cout<< N<<" \t"<<log10(N)<<" \t\t"<<xmax*(sum/N)<<endl;
    cerr<< "Integration of sin(2xy) by M.C. Mean Value method = "
        << xmax*(sum/N)<<endl;
  }
  return 0;
}
  
  
  
