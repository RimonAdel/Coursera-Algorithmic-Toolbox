#include <iostream>

int get_change(int m) {
  int counter = 0;
  int coins[] = {1, 5,10};
  while (m != 0){
    if (m >= 10){
      m -= 10;
      counter++;
    }else if (m >= 5){
      m -= 5;
      counter++;
    }else{
      m -= 1;
      counter++;
    }
  }
  //write your code here
  return counter;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
