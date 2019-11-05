#include <Rcpp.h>
using namespace Rcpp;
#include <iostream>
using namespace std;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
IntegerVector factorize_cpp(int x) {
  if (x < 4) {
    IntegerVector y(1, x);
    return y;
  }
  int n = floor(sqrt(x));
    for (int i=2; i<=n; i++) {
      if (x % i == 0) {
        IntegerVector fact = factorize_cpp(x/i);
        fact.push_front(i);
        return (fact);
      }
    }
    IntegerVector y(1, x);
    return y;
}

// [[Rcpp::export]]
NumericVector timesTwo(NumericVector x) {
  return x * 2;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
factorize_cpp(12)
*/
