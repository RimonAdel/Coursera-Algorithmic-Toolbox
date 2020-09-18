#include <iostream>
#include <vector>
#include <map>
#include<bits/stdc++.h> 

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;
using std::greater; 

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  int weight = 0;
  double value = 0;
  double weightDifference;
  int size = -1;
  vector< pair <double,int> > valueWeightVec;

  for (int i = 0; i < values.size(); i++){
    valueWeightVec.push_back(make_pair(values[i]*1.0/weights[i]*1.0, weights[i]));
  }

  sort(valueWeightVec.begin(), valueWeightVec.end());

  while (capacity > weight && size != 0){
    size = valueWeightVec.size()-1;
    weightDifference = capacity - weight;
    // cout<<"weight = "<< weight<<"capacity = "<< capacity <<endl;
    if (weightDifference >= valueWeightVec[size].second){
      value += (double)valueWeightVec[size].second * (valueWeightVec[size].first*1.0);
      weight += valueWeightVec[size].second;
      // cout<<"weight = "<< weight <<endl;
      // cout<<"value of item = "<< valueWeightVec[size].second *valueWeightVec[size].first <<" value = "<< value <<endl;
    }else{
      value += weightDifference * (valueWeightVec[size].first*1.0);
      weight += weightDifference;
      // cout<<"weight = "<< weight <<endl;
      // cout<<"weightDifference = "<< weightDifference <<"value = "<< valueWeightVec[size].first <<endl;

      // cout<<"value of item = "<< weightDifference *valueWeightVec[size].first <<"value = "<< value <<endl;
    }
    valueWeightVec.pop_back();
  }

  return (double)value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(9);
  std::cout << optimal_value << std::endl;
  return 0;
}
