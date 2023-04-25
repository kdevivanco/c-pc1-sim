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

//template<typename Container, typename Container::value_type, typename T>
//Container get_maximum_product_range(const T& cnt)
//{
//    typename Container::value_type result = {};
//    for (auto iter = cnt.cbegin(); iter < cnt.cend(); /*iter++*/)
//    {
//        if (*iter != 0) {
//            result.push_back(iter);
//            ++iter;
//        }
//    }
//
//    return result;
////}
//template <typename Container>
//Container get_maximum_product_range(const Container& input)
//{
//    Container output;
//
//    // logic to compute the maximum product range
//
//    return output;
//}

template<typename Container, typename T = typename Container::value_type>
Container get_maximum_product_range(const Container& input) {
    Container modified_input(input);

    modified_input.erase(std::remove(modified_input.begin(), modified_input.end(), T(0)), modified_input.end());

    int negative_count = 0;
    for (const auto& value : modified_input) {
        if (value < 0) {
            negative_count++;
        }
    }

   auto highest_negative = std::numeric_limits<T>::min();
    for (const auto& value : modified_input) {
        if (value < 0 && value > highest_negative) {
            highest_negative = value;
        }
    }

    return modified_input;
}

void question_2();

#endif //prog3_simulacro_PC1_v2023_1_P2_H
