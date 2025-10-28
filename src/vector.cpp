#include "vector.h"

namespace vector {

Vector::Vector() :  arr_(nullptr), sz_(0), cap_(0){}

Vector::~Vector() {
    Clear();
    delete[] arr_;
}

Vector::Vector(Vector&& other) noexcept : arr_(nullptr), sz_(0), cap_(0) {
    std::swap(arr_, other.arr_);
    std::swap(sz_, other.sz_);
    std::swap(cap_, other.cap_);
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        Clear();
        delete[] arr_;
        arr_ = nullptr;
        sz_ = 0;
        cap_ = 0;
        std::swap(arr_, other.arr_);
        std::swap(sz_, other.sz_);
        std::swap(cap_, other.cap_);
    }
    return *this;
}

figure::Figure*& Vector::operator[](size_t pos) {
    if (pos >= sz_) {
        throw std::out_of_range("Vector index out of range");
    }
    return arr_[pos];
}

const figure::Figure* Vector::operator[](size_t pos) const {
    if (pos >= sz_) {
        throw std::out_of_range("Vector index out of range");
    }
    return arr_[pos];
}

void Vector::PushBack(figure::Figure* val) {
    if (cap_ == sz_) {
        size_t new_cap = (cap_ == 0) ? 1 : cap_ * 2;
        Reserve(new_cap);
    }
    arr_[sz_] = val;
    ++sz_;
}

void Vector::Erase(size_t ind) {
    if (ind >= sz_) {
        throw std::out_of_range("Erase index out of range");
    }  
    delete arr_[ind];
    for (size_t i = ind + 1; i < sz_; ++i) {
        arr_[i - 1] = arr_[i];
    }
    --sz_;
}

size_t Vector::Size() const noexcept {
    return sz_;
}

bool Vector::IsEmpty() const noexcept {
    return sz_ == 0;
}

void Vector::Clear() {
    for (size_t i = 0; i < sz_; ++i) {
        delete arr_[i];
        arr_[i] = nullptr;
    }
    sz_ = 0;
}

void Vector::Reserve(size_t new_cap) {
    if (new_cap <= cap_) {
        return;
    }
    figure::Figure** new_arr = new figure::Figure*[new_cap];
    for (size_t i = 0; i < sz_; ++i) {
        new_arr[i] = arr_[i];
    }
    delete[] arr_;
    arr_ = new_arr;
    cap_ = new_cap;
} 

} // namespace vector