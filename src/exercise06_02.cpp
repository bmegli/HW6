#include <Rcpp.h>

using namespace Rcpp;

//' @title simplifies list of numeric vectors to array if possibles
//' @description Task:
//' Write your own implementation of the simplify2array() function. Your function should
//' expect a list of numeric vectors on input.
//'
//' @param L list of numeric vectors
//' @return vector, array or list
//' @export
// [[Rcpp::export]]
SEXP simplify2array(List L)
{  
  if(L.size()==0)
    return NumericVector(0);
  if(!(Rf_isReal(L[0])  || Rf_isInteger(L[0]))) //just the first for now, we will check the rest as we go
    stop("L has to be list of numeric vectors");
  if(L.size()==1)
    return L[0];
    
  int len1=NumericVector(L[0]).size();
  bool shared_size=true;
    
  for(int i=0;i<L.size();++i)
  {
    if(!(Rf_isReal(L[i]) || Rf_isInteger(L[i])  ))
      stop("L has to be list of numeric vectors");
    shared_size &= (NumericVector(L[i]).size()==len1);
  }
  
  if(!shared_size)
    return L;
    
  NumericMatrix M(len1, L.size());
  for(int i=0;i<L.size();++i)
    M.column(i)=NumericVector(L[i]);
  
  return M;
}
