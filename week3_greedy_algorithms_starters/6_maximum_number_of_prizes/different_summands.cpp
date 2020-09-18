#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;
using std::greater; 

vector<int> optimal_summands(int n) {
  vector<int> summands;
  long long sum = 0;
  long long prevNum = 0;
  int newNumber = 0;
  while (sum < n){
    newNumber = prevNum+1;
    if((n-(newNumber+sum)) > newNumber){
      summands.push_back(newNumber);
      sum += newNumber;
      prevNum = newNumber;
      // cout<<newNumber<<endl;
    }else{
       summands.push_back(n-sum);
       sum += (n-sum);
      //  cout << "else newNumber "<<newNumber<<endl;
      //  cout << "else sum "<<sum<<endl;
      //  cout << "else "<<(n-sum)<<endl;
       break;
    }
  }
  return summands;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
