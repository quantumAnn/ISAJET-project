// H. Ann Summy
// Wednesday, November 10, 2004
/* This is the header file containing the function calls for the 
    three methods of integration used in integrate.cc. */
    
    
/* 1.  Newton-Cotes Integrations, a.k.a., composite rectangle method rect()
  integrates f(x) using the midpoints from x=a to x=b using n bins. */
  
double rect(double(*f)(double x), double a, double b, int n);


/* 2.  Composite trapezoidal method trap() integrates f(x) using the two
  endpoints for a linear approximation from x=a to x=b using n bins. */
  
double trap(double(*f)(double xj), double a, double b, int n);


/* 3.  Three-point Simpson method simp() integrates f(x) using three points
  (start, mid, and end) for a quadratic approximation from x=a to x=b
  using n bins. */
  
double simp(double(*f)(double x), double a, double b, int n);
