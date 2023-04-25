//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>
#include <array>
#include <forward_list>
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
    std::deque<int> f1 = get_maximum_product_range<deque<int>>(lst1);
    for (const auto& value : f1) {
        std::cout << value << " ";
    }

    cout<<'\n';
    std::forward_list<int> flst1 = {1, 2, -3, 0, 0, -3, -2, 5, -1, -5};
    std::vector<int> f2 = get_maximum_product_range(flst1); // En este caso sera vector
    for (const auto& value : f2) {
        std::cout << value << " ";
    }

}

//
//
int main(){
    question_2();
//
}