//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include <vector>
#include <string>
#include "P1.h"

using namespace std;
template <typename T>
class symmetric_difference_t {
public:
    symmetric_difference_t(const std::vector<T>& v1, const std::vector<T>& v2) {
        // unimos los vectores y los ordenamos
        std::vector<T> merged = v1;
        merged.insert(merged.end(), v2.begin(), v2.end());
        std::sort(merged.begin(), merged.end());

        // encontramos los elementos que están solamente en uno de los vectores
        for (auto it = merged.begin(); it != merged.end();) {
            auto next_it = std::next(it);
            if (next_it != merged.end() && *it == *next_it) {
                // el elemento está en ambos vectores, lo eliminamos
                it = merged.erase(it, next_it + 1);
            } else {
                ++it;
            }
        }

        // asignamos el resultado a nuestro arreglo dinámico
        data_ = new T[merged.size()];
        std::copy(merged.begin(), merged.end(), data_);
        size_ = merged.size();
    }

    ~symmetric_difference_t() {
        delete[] data_;
    }

    // método que retorna el tamaño del arreglo dinámico
    size_t size() const {
        return size_;
    }

    // sobrecarga del operador de paréntesis para acceder al arreglo
    T* operator()() const {
        return data_;
    }

    // sobrecarga del operador de negación para invertir el orden del arreglo
    void operator!() {
        std::reverse(data_, data_ + size_);
    }

private:
    T* data_ = nullptr; // puntero al arreglo dinámico
    size_t size_ = 0; // tamaño del arreglo dinámico
};
//template<typename T>
//class symmetric_difference_t {
//public:
//    symmetric_difference_t(const std::vector<T>& v1, const std::vector<T>& v2) {
//        std::vector<T> tmp1(v1);
//        std::vector<T> tmp2(v2);
//        std::sort(tmp1.begin(), tmp1.end());
//        std::sort(tmp2.begin(), tmp2.end());
//        std::vector<T> result;
//        std::set_symmetric_difference(tmp1.begin(), tmp1.end(), tmp2.begin(), tmp2.end(), std::back_inserter(result));
//        data = std::make_shared<std::vector<T>>(result);
//    }
//
//    size_t size() const {
//        return data->size();
//    }
//
//    T* operator()() const {
//        return data->data();
//    }
//
//    T* operator!() const {
//        std::reverse(data->begin(), data->end());
//        return data->data();
//    }
//
//private:
//    std::shared_ptr<std::vector<T>> data;
//};
//template <class T>
//class symmetric_difference_t{
//    typedef T value_type;
//    typedef typename std::vector<T>::size_type size_type;
//    //Constructores
//    symmetric_difference_t();
//    symmetric_difference_t(initializer_list<T> il);
//
//    //Contador de elementos en sym...
//    size_type size() const {return data->size();}
//    bool empty() const {return data->empty();}
//
//    //Anadir/Remover elementos
//    void push_back(const T &t){data ->push_back(t);}
//    void push_back(T &&t){data ->push_back(move(t));} //mover
//    void pop_back();
//
//    //Acceso a elementos:
//    T& back();
//    T& operator[](size_type i);
//private:
//    shared_ptr< vector<T> > data;
//
//    void check(size_type i , const string &msg) const;
//};
//
//template <typename T>
//symmetric_difference_t<T>::symmetric_difference_t(): data(std::make_shared<std::vector<T>> ()) { };
//
//template <typename T>
//symmetric_difference_t<T>::symmetric_difference_t(std::initializer_list<T> il):
//        data(std::make_shared<std::vector<T>> (il)) { }
//
//
//
//void question_1(){
//
//}

int main() {
    symmetric_difference_t<int> sd1 ({1, 5, 3, 8, 2}, {4, 9, 7, 6, 10, 1});
    return 0;
}