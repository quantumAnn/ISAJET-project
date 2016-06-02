// H. Ann Summy
// Wednesday, November 17, 2004
/* This program evaluates the area under the unit circle and generates 
    a value for pi using the Monte Carlo sampling method. */
    
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

double Nf=0, N=1000;  //count of points under function and box
double x, y, f, xmax=1, ymax=1;
double drand48(void);
void srand48(long int seedval);
time_t t;
string file;


int main()
{
  cerr<< "Enter name of output file:  ";
  cin>>file;
/* ofstream file;
    file.open ("MCsampler.output", ios::out | ios::app | ios::binary); */
  ofstream ofile (file.c_str(), ios::out | ios::app | ios::binary);
  if (!ofile) {
    cerr<<"The output file could not be opened.";
    return -1;
  }
  
  ofile<< "# x      \ty       \t\tfunction"<<endl;
  ofile<< "# -      \t-       \t\t--------"<<endl;
  
  srand48(time(&t));
  for (int i=0; i<N; i++) {
    x= xmax*drand48();
    y= ymax*drand48();
    f= sqrt(1-pow(x,2));
    if (f>y) Nf++;
    
    ofile<<x<<" \t"<<y<<" \t"<<f<<endl;
  }

  ofile<< "# Number of points used is "<<N<<endl
       << "# pi = "<<4*(ymax*xmax)*(Nf/N)<<endl;
  ofile.close();

  cout<< "Number of points used is "<<N<<endl
      << "Pi by M.C. Sampling of hte unit circle = "
      << 4*(ymax*xmax)*(Nf/N)<<endl;
      
  return 0
}
