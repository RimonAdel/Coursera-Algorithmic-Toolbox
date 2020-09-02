#include <algorithm>
#include <iostream>
#include <vector>
#include<bits/stdc++.h> 


using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::greater; 

int MaxPairwiseProduct(const vector<int>& numbers) {
  int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

long long int FasterMaxPairwiseProductIn_N(const vector<int>& numbers) {
  int n = numbers.size();
  int max = 0;
  int sec_max = 0;

  for (int i=0; i<numbers.size();i++){
      if (max < numbers[i]){
        sec_max = max;
        max = numbers[i];
      }else{
        if(sec_max < numbers[i]){
          sec_max = numbers[i];
        }
      }
  }
  return (long long int)max*sec_max;
}

//   long long int FasterMaxPairwiseProductIn_NLogN(vector<int>& numbers) {

//   sort(numbers.begin(),numbers.end(),greater<>());

//   return (long long int) numbers[0]*numbers[1];
// }

// int FasterMaxPairwiseProduct_1_5_n(const vector<int>& numbers) {
//   int result = 0;
//   int n = numbers.size();
//   int max = 0;
//   int sec_max = 0;
//   for(int i = 2 ; i < n-2 ; i++){
//     if (numbers[i] > numbers[i+1]){
//       if(max < numbers[i+1]){
//         sec_max = numbers[i+1];
//       }else{
//         sec_max = max;
//       }
//       if (max < numbers[i]){
//         max = numbers[i];
//       }
//     }else{
//       if(max < numbers[i]){
//         sec_max = numbers[i];
//       }else{
//         sec_max = max;
//       }
//       if (max < numbers[i+1]){
//         max = numbers[i+1];
//       }
//     }
//   }
//   if (numbers.size()%2 != 0){
//     if(max < numbers[numbers.size()-1]){

//     }
//   }
//   return result;
// }

// int FasterMaxPairwiseProductNPlusLogN(const vector<int>& numbers) {
//   int result = 0;
//   int n = numbers.size();
//   sort(numbers.begin(),numbers.end(), greater<>());
//   return result;
// }


int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long int result = FasterMaxPairwiseProductIn_N(numbers);
    cout << (long long int) result << "\n";
    return 0;
}
