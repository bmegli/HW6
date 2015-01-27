#include <Rcpp.h>
#include <map>
using namespace Rcpp;
//' @title mode function
//' @description Task:
//' Write a function mode() to determine the most frequently occurring value in an integer
//' vector (mode). If the mode is ambiguous (e.g. for 1, 2, 2, 2, 3, 3, 1, 3), return any mode
//'
//' @param v IntegerVector 
//' @return integer vector of length 1 with mode or length 0 
//' @export
// [[Rcpp::export]]
IntegerVector mode (const IntegerVector v)
{
  std::map<int, int> counts;
  std::map<int,int>::iterator found;
  
  int max=0;
  int max_val=0;
  
  const int n=v.size();
  
  for(int i=0;i<n;++i)
    if( !IntegerVector::is_na(v[i]) )
      ++counts[v[i]];
  
  for(found=counts.begin();found!=counts.end();++found)
    if(found->second>max)
    {
      max=found->second;
      max_val=found->first;
    }
  
  if(max==0)
    return IntegerVector(0);
  else
    return IntegerVector::create(max_val);
}
