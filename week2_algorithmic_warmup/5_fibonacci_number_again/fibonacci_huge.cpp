/*
 *
 *  Created on: Sep 30, 2019
 *      Author: rimon
 */
#include <iostream>
#include <vector>
#define LOG(x) std::cout << x << " ";
using std::vector;

long long get_fibonacci_huge_fast(long long n, int m) {
    vector<int> g1;
    g1.push_back(0);
    g1.push_back(1); 
    g1.push_back(1); 
    if (n <= 1)
    {
        return n;
    }
    long int prev_1 = 1, prev_2 = 0 ,result = 0;
    int length = 3 , j =2;
    while(true){
        j++;
        prev_1 = 1, prev_2 = 0 ,result = 0;
        for (int i = 0 ; i < j-1; i++){
            result = prev_1 + prev_2;
            prev_2 = prev_1 % m;
            prev_1 = result % m;
        }
        if((result%m) == 1 && g1[length-1] == 1 && g1[length-2]==0){
            break;
        }
       
        g1.push_back((result%m));
        length++;
    }
    // LOG(length-2)
    // LOG(g1[n%(length-2)])

    // std::cout << "Output of begin and end: "; 
    // for (auto i = g1.begin(); i != g1.end(); ++i) 
    //     std::cout << *i << " "; 
    return g1[n%(length-2)];
}

int main(){
    long long n, m;
    std::cin >> n >> m;
    LOG(get_fibonacci_huge_fast(n, m));
    return 0;
}