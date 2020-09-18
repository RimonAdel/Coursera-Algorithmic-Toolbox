#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;
using std::greater; 

bool isGreaterOrEqual(string s1, string s2){
  return ((s2+s1) < (s1+s2));
}

string largest_number(vector<string> a) {
  std::stringstream ret;
  int maxIndex = 0;
  while(a.size()>1){
    string maxString = a[0] ;
    maxIndex = 0;
    // cout << "yes" <<endl;
    for (size_t i = 1; i < a.size(); i++){
      // cout<< "maxString " << maxString << " a["<< i <<"] "  << a[i]<< " isGreaterOrEqual("<< a[i] <<","<< maxString <<")"  << isGreaterOrEqual(a[i], maxString) <<" size = "<< a.size() <<endl;
      if (isGreaterOrEqual(a[i], maxString)){
        maxString = a[i];
        maxIndex = i;
      }
    }
    // cout << maxString <<endl;
    a.erase(a.begin() + maxIndex );
    ret << maxString;
  }
  ret << a[0];
  // for (size_t i = 0; i < a.size(); i++) {
  //   cout << a[i].length() << endl;
  // }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
