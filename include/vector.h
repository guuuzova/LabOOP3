#pragma once

#include <cstddef>
#include <utility>

#include "figure.h"

namespace vector {

class Vector {
public:
    Vector();
    figure::Figure*& operator[](size_t pos);
    const figure::Figure* operator[](size_t pos) const;
    Vector(const Vector& other);
    Vector& operator=(const Vector& other) = delete;
    Vector(Vector&& other) noexcept;
    Vector& operator=(Vector&& other) noexcept;
    ~Vector();
    
    void PushBack(figure::Figure* val);
    void Erase(size_t ind);
    size_t Size() const noexcept;
    bool IsEmpty() const noexcept;
    void Clear();
    void Reserve(size_t new_cap);

private:
    figure::Figure** arr_;
    size_t sz_;
    size_t cap_;
};

} // namespace vector