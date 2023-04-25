//
// Created by rudri on 10/11/2020.
//

#ifndef prog3_simulacro_PC1_v2023_1_P1_H
#define prog3_simulacro_PC1_v2023_1_P1_H



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <numeric>
#include <sstream>
#include "P1.h"

using namespace std;
template <typename T>
class symmetric_difference_t {
private:
    vector<T> res = {};
//    T* data_ = nullptr;
    //size_t size_ = 0;
public:
    symmetric_difference_t<T>(const std::vector<T>& v1,const std::vector<T>& v2) {
        // UNIR VECTORES
        //vector<T> merged = v1;
        vector<T> merged;
        for (int i = 0; i < v1.size(); i++) {
            bool found = false;
            for (int j = 0; j < v2.size(); j++) {
                if (v1[i] == v2[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                merged.push_back(v1[i]);
            }
        }
        for (int i = 0; i < v2.size(); i++) {
            bool found = false;
            for (int j = 0; j < v1.size(); j++) {
                if (v2[i] == v1[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                merged.push_back(v2[i]);
            }
        }
        merged;
        sort(merged.begin(), merged.end());
        //unique(merged.begin(),merged.end());
        res = merged;
        auto last = std::unique(res.begin(), res.end()); // Borra duplicados
        res.erase(last, res.end());

    }

//        merged.insert(merged.end(), v2.begin(), v2.end());
//        sort(merged.begin(), merged.end());
//
//        //Eliminar valores iguales
//        for (auto it = merged.begin(); it != merged.end();) {
//            auto next_it = std::next(it);
//            if (next_it != merged.end() && *it == *next_it) {
//                it = merged.erase(it, next_it + 1);
//            } else {
//                ++it;
//            }
//        }


//        // RESULTADO
//        data_ = new T[merged.size()];
//        std::copy(merged.begin(), merged.end(), data_);
        //res = merged;
    //}

//    ~symmetric_difference_t() {
//        delete[] res;
////    }
//    vector<T> removeDuplicates()
//    {
//        std::sort(res.begin(), res.end());
//        auto last = std::unique(res.begin(), res.end());
//        res.erase(last, res.end());
//        return res;
//    }

    size_t size()  {
        return res.size();
    }

    T* operator()()  {
        return res.data();
    }

    T* operator!() {
        std::reverse(res.begin(), res.end());
        return res.data();
    }


};



void question_1();

#endif //prog3_simulacro_PC1_v2023_1_P1_H
