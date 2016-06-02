// H. Ann Summy
// Wednesday, November 10, 2004
/* This program integrates one-dimensional functions using the 
    following three methods: Newton-Cotes, Trapezoidal, and 
    3-point Simpson. The three methods are listed as functions 
    in a program named "integrate.cc" linked by a header file 
    called "integrate.h". */
    
  #include <iostream>
  #include <cmath>
  
  
/* 1.  Newton-Cotes Integration, a.k.a., composite rectangle method rect() 
  integrates f(x) using the midpoints from x=a to x=b using n bins. */
  
double rect(double(*f)(double x), double a, double b, int n) {
  double w=(b-a)/((double) n);
  double sum=0;
  for (int i=0; i<n; i++)
    sum += (*f)(a + (i+0.5)*w)*w;
  return sum;
}


/* 2.  Composite trapezoidal method trap() integrates f(x) using the two 
  endpoints for a linear approximation from x=a to x=b using n bins. */
  
double trap(double(*f)(double x), double a, double b, int n) {
  double w=(b-a)/((double) n);
  double sum=0;
  for (int i=0; i<n; i++)
    sum += ((*f)(a + i*w)+(*f)(a + (i+1)*w))*(w/2);
  return sum;
}


/* 3.  Three-point Simpson method simp() integrates f(x) using three points 
  (start, mid, and end) for a quadratic approximation from x=a to x=b 
  using n bins. */
  
double simp(double(*f)(double x), double a, double b, int n) {
  double w=(b-a)/((double) n);
  double sum=0;
  for (int i=0; i<n; i++)
    sum += ((*f)(a +i*w) + 4*(*f)(a + w*(i+0.5)) + (*f)(a + (i+1)*w))*(w/6);
  return sum;
}
