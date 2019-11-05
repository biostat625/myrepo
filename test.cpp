
#include <Rcpp.h>
#include<vector>
using namespace Rcpp;
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
std::vector<int> factorize_cpp(int x){
  std::vector<int> primevec;
  while (x % 2 == 0){
    primevec.push_back(2);
    x = x / 2;
  }
  int start = 3;
  while (x != 1){
    while (x % start == 0){
      primevec.push_back(start);
      x = x / start;
    }
    start += 2;
  }
  return primevec;
}
// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

  