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



template<typename Container = std::vector<int>, typename T = typename Container::value_type, typename GenCont = vector<T>> //, typename T = typename Container::value_type>
Container get_maximum_product_range(const GenCont& input) {
    //Container modified_input(input);
    Container output;
    Container neg_cont;

    int negative_counter = 0;
    for (const auto& value : input) {
        if (value > 0) {
            output.push_back(value);
        }
        else if(value<0){
            ++negative_counter;
            neg_cont.push_back(value);
        }
    }
    //valor mas bajo:

    if (negative_counter % 2 != 0){
        auto max = -10000000;
        for (const auto& value : neg_cont) {
            if (value > max){
                    max = value;
                }
            }
        for (const auto& value : neg_cont) {
            if (value != max){
                output.push_back(value);
            }
        }

        }


    return output;
}


void question_2();

#endif //prog3_simulacro_PC1_v2023_1_P2_H
