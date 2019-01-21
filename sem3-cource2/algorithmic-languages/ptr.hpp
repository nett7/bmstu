////
////  shred_ptr.hpp
////  shd_ptr
////
////  Created by Игорь on 10.12.2018.
////  Copyright © 2018 Игорь. All rights reserved.
////
//
//#ifndef shred_ptr_hpp
//#define shred_ptr_hpp
//
//#include <stdio.h>
//#include <atomic>
//#include <algorithm>    // std::swap
//
//
//template <typename T>
//class SharedPtr {
//public:
//    SharedPtr();
//    SharedPtr(const SharedPtr& r){
//        swap(r);
//    }
//    SharedPtr(SharedPtr&& r){
//        swap(r);
//    }
//
//    SharedPtr& opeartor=(const SharedPtr& r)
//    {
//        if (*this == r) {
//            return *this;
//        }
//        SharedPtr<T>{r}.swap(*this);
//        return *this;
//    }
//
//    SharedPtr opeartor=(SharedPtr&& r) {
//        assert(r.data == nullptr);
//        swap(r);
//        return *this;
//    }
//
//    // проверяет, указывает ли указатель на объект
//    operator bool() const;
//    auto operator*() const -> T&;
//    auto operator->() const -> T*;
//
//    auto get() -> T*{
//        return data;
//    }
//    void reset() {
//        data=nullptr;
//    }
//    void reset(T* ptr){
////        assert(ptr == nullptr);
////        data=ptr;
//        reset();
//        ptr = ptr;
//    }
//
//    void swap(SharedPtr& r) {
//        std::swap(data, r.data);
//        std::swap(count, r.count);
//    }
//    // возвращает количество объектов SharedPtr, которые ссылаются на тот же управляемый объект
//    auto use_count() const -> size_t
//    {
//        size_t out = 0;
//        if (nullptr != count)
//        {
//            out = *count;
//        }
//        return out;
//    }
//private:
//    std::atomic_uint * count;
//    T * data;
//};
//
//#endif /* shred_ptr_hpp */

#ifndef shred_ptr_hpp
#define shred_ptr_hpp

#include <iostream>
#include <atomic>
#include <utility>

template <typename T>
class SharedPtr {
    std::atomic<unsigned int> count;
    T* data_ptr;

public:
    SharedPtr()
    {
        data_ptr = nullptr;
        count = 1;
    }

    explicit SharedPtr(T* p)
    {
        data_ptr = p;
        count = 1;
    }

    SharedPtr(const SharedPtr& r)
    {
        data_ptr = r.data_ptr;
        // Object of type 'std::__1::atomic<int>' cannot
        // be assigned because its copy assignment operator
        // is implicitly deleted
        unsigned int temp = r.count;
        count = temp;
        count++;
    }

    SharedPtr(const SharedPtr&& r)
    {
        swap(r);
    }

    bool operator==(const SharedPtr& r)
    {
        return (data_ptr == r.data_ptr && count == r.count);
    }
    SharedPtr& operator=(const SharedPtr& r)
    {
        if (*this == r) {
            return *this;
        }
        SharedPtr<T>{ r }.swap(*this);
        return *this;
    }

    ~SharedPtr()
    {
        if (count - 1 == 0) {
            data_ptr = nullptr;
            count = 0;
        }
        else {
            count -= 1;
        }
    }

    void reset()
    {
        data_ptr = nullptr;
        count = 0;
    }

    void reset(T* something)
    {
        reset();
        data_ptr = something;
    }

    void swap(SharedPtr& another)
    {
        std::swap(another.data_ptr, data_ptr);
        std::swap(another.count, count);
    }

    T* get()
    {
        return data_ptr;
    }

    T& operator*() const
    {
        if (*this) {
            return *(this->data_ptr);
        }

        return std::runtime_error("pointer was nullptr");
    }

    T* operator->() const
    {
        return data_ptr;
    }

    size_t use_count() const
    {
        return count;
    }
};
#endif /* shred_ptr_hpp */
