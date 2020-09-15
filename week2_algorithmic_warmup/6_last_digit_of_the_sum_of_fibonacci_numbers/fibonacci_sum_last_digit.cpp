/*
 *
 *  Created on: Sep 30, 2019
 *      Author: rimon
 */
#include <iostream>
#include <vector>
#define LOG(x) std::cout << x << " ";
using std::vector;

long long fibonacci_sum_fast(long long n, int m) {
    vector<int> g1;
    g1.push_back(0);
    g1.push_back(1); 
    g1.push_back(1);
    n += 2;
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

    if (g1[n%(length-2)] == 0){
        return g1[n%(length-2)-1];
    }
    return g1[n%(length-2)]-1;
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 1000;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << "\n\n" <<fibonacci_sum_fast(n,100);
}
