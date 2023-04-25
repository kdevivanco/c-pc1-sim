//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>
#include <array>
#include "P2.h"

using namespace std;





//template<typename T, typename res_cont>
//res_cont get_maximum_product_range(T cnt){
//    for (auto iter = cnt.cbegin(); iter < cnt.cend(); /*iter++*/)
//    {
//        if (*iter == 0)
//        {
//            iter = cnt.erase(iter);
//        }
//        else
//        {
//            ++iter;
//        }
//    }
//    return cnt;
//
//}
void question_2(){
    std::list<int> lst1 = {3, 3, -3, 5, 4, -4, 0, -4, -4, -5};
    std::deque f1 = get_maximum_product_range<std::deque>(lst1);
    for (const auto& row: f1) {
       for(const auto& value: row)
           std::cout << value << " ";
       std::cout << std::endl;
   }

}

//
//
int main(){
    question_2();
//
}