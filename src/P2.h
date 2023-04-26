//
// Created by rudri on 10/11/2020.
//
#include <iostream>
#include <numeric>
#include <vector>
#include <deque>
#include <list>
#ifndef prog3_simulacro_PC1_v2023_1_P2_H
#define prog3_simulacro_PC1_v2023_1_P2_H
using namespace std;



template <
        template<typename...> class Container = vector,
        template <typename...> class GenCont,
        typename T>
Container<Container<T>> get_maximum_product_range(GenCont<T> input) {
    Container<Container<T>> output;
    Container<T> initial;

    copy_if(initial.begin(), initial.end(), back_inserter(initial), [](T x){ return x; });

    //Ubica iteradores donde 0
    auto position_zero = remove(initial.begin(), initial.end(), 0);
    //Borra los 0
    initial.erase(position_zero, initial.end());

    vector<T> neg_cont;
    int negative_counter = 0;
    for (const T& value : input) {
        if (value < 0) {
            neg_cont.push_back(value);
            ++negative_counter;
        }
    }

    //Encuentra valor mas bajo:
    auto nmax = -100000000000;

    if (negative_counter % 2 != 0){
        //cout << "Es impar" << endl;
        for (const auto& value : neg_cont) {
            if (value > nmax) {
                nmax = value;
            }
        }
        for(const T& value : input){
            if (value != nmax && value != 0){
                Container<T> temp = {value};
                output.push_back(temp);
            }
        }
    }
    else
        for(const T& value : input){
            if (value != 0){
                Container<T> temp = {value};
                output.push_back(temp);
            }
        }



//    //Itera sobre initial y borra i
//    for (const auto& value : initial) {
//        if (value != max){
//            output.push_back(value);
//        }
//    }



    return output;
}

void question_2();

#endif //prog3_simulacro_PC1_v2023_1_P2_H
