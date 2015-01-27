#include <Rcpp.h>
#include <stdint.h>

using namespace Rcpp;

bool umult32(uint32_t a,uint32_t b,uint32_t* c) {
  unsigned long long x=(unsigned long long)a*b;
  if (x>0xffffffff) return false;
  *c=x&0xffffffff;
  return true;
}

uint32_t factorial(uint32_t n)
{ 
  uint32_t fac=1;
  for(uint32_t i=2;i<=n;++i)      
    if(!umult32(fac, i, &fac))
      return 0;
        
  return fac;
}

//' @title permutations function
//' @description Task:
//' Write an Rcpp function perms() to generate all the possible permutations of the set {1, 2, . . . , n}
//' (for some given n). The function should return a matrix with n! rows and n columns
//'
//' @param n integer
//' @return matrix with n! rows and n columns with permutations
//' @export
// [[Rcpp::export]]
NumericMatrix perms (int n)
{
  if(n<0)
    stop("n has to be greater equal 0");
  if(n==0)
    return NumericMatrix(0,0);
  
  uint32_t rows=factorial(n);
  if(rows==0)
    stop("n is too big!");
    
  NumericMatrix M(rows,n);
  IntegerVector perm=seq_len(n);
  
  for(uint32_t i=0;i<rows;++i)
  {
    M.row(i)=perm;
    std::next_permutation(perm.begin(), perm.end());
  }
  
  return M;
}
