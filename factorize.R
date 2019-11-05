factorize = function(x) {
  if (x < 4) {return (x)}
  n = floor(sqrt(x))
  for (i in 2:n) {
    if (x %% i == 0) {
      return (c(i, factorize(x/i)))
    }
  }
  return (x)
}

sourceCpp("factorize.cpp")

library(gmp)
library(bench)
library(ggbeeswarm)
x = 1073602561
result = bench::mark(factorize(x), factorize_cpp(x), as.numeric(gmp::factorize(x)))
print(result)
