/*
 *
 *  Created on: Sep 30, 2019
 *      Author: rimon
 */
#include <iostream>
#define LOG(x) std::cout << x << std::endl

int GCD(int number_1, int number_2){
    int f_number_1, f_number_2, remainder, result;
    
    if(number_1 > number_2){
        f_number_1 = number_1;
        f_number_2 = number_2;
    }
    else{
        f_number_1 = number_2;
        f_number_2 = number_1;
    }


    remainder = ( f_number_1 % f_number_2 );
    result = f_number_2;
    while (remainder != 0){
        f_number_1 = f_number_2;
        f_number_2 = remainder;
        remainder = ( f_number_1 % f_number_2 );
        result = f_number_2;
    }
    return result;
}

unsigned long long LCM(int number_1, int number_2){
    // LOG(GCD(number_1, number_2));
    return  (unsigned long long) number_1*number_2/GCD(number_1,number_2);
}


int main(){
    int number_1, number_2, result; 
    std::cin >> number_1 >> number_2;

    result = LCM(number_1, number_2);
    LOG((unsigned long long) LCM(number_1, number_2));
    return 0;
}