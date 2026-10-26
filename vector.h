#ifndef vector_h
#define vector_h
#include<bits/stdc++.h>
template<typename T>
class vectorcuatoi{
    private:
        T* data;
        size_t dem;
        size_t dungluong; 
        void reallocate(size_t x){
            T* y=new T[x];
            for(size_t i=0;i<dem;i++) y[i]=data[i];
            delete[] data;
            data=y;
            dungluong=x;
        }
    public:
        vectorcuatoi(){
            data=nullptr;
            dem=0;
            dungluong=0;
        }
        vectorcuatoi(const vectorcuatoi& x){
            data=nullptr;
            dem=0;
            dungluong=0;
            reallocate(x.dungluong==0?1:x.dungluong);
            for(size_t i=0;i<x.dem;i++) data[i]=x.data[i];
            dem=x.dem;
        }
        vectorcuatoi& operator = (const vectorcuatoi& a){
            if(this==&a) return *this;
            delete[] data;
            data=nullptr;
            dem=0;
            dungluong=0;
            reallocate(a.dungluong==0?1:a.dungluong);
            for(size_t i=0;i<a.dem;i++) data[i]=a.data[i];
            dem=a.dem;
            return *this;
        }
        ~vectorcuatoi(){
            delete[] data;
        }
        void push_back(const T& a){
            if(dem==dungluong) reallocate(dungluong==0?1:dungluong*2);
            data[dem++]=a;
        }
        void pop_back(){
            if(dem==0) throw std::out_of_range("vector rong");
            dem--;
        }
        T& operator [] (size_t a){
            if(a>=dem) throw std::out_of_range("ngoai pham vi vector");
            return data[a];
        }
        const T& operator [] (size_t a) const{
            if(a>=dem) throw std::out_of_range("ngoai pham vi vector");
            return data[a];
        }
        size_t size() const{
            return dem;
        }
        bool empty() const{
            return dem==0;
        }
        void clear(){
            dem=0;
        }
        //Bo lap xuoi (iterator)
        class iterator{
            private:
                T* ptr;
            public:
                explicit iterator(T* p) {
                    ptr=p;
                }
                T& operator * () const {
                    return *ptr;
                }
                T* operator -> () const{
                    return ptr;
                }
                iterator& operator ++ (){
                    ptr++;
                    return *this;
                }
                iterator operator ++(int){
                    iterator temp=*this;
                    ptr++;
                    return temp;
                }
                iterator& operator -- (){
                    ptr--;
                    return *this;
                }
                iterator operator --(int){
                    iterator temp=*this;
                    ptr--;
                    return temp;
                }
                bool operator == (const iterator& a) const{
                    return ptr==a.ptr;
                }
                bool operator != (const iterator& a) const{
                    return ptr!=a.ptr;
                }
        };
        iterator begin(){
            return iterator(data);
        }
        iterator end(){
            return iterator(data+dem);
        }
        //bo lap nguoc (reverse iterator)
        class reverse_iterator{
            private:
                T* ptr;
            public:
                explicit reverse_iterator(T* p){
                    ptr=p;
                }
                T& operator * () const{
                    return *ptr;
                }
                T* operator -> () const{
                    return ptr;
                }
                reverse_iterator& operator ++ (){
                    ptr--;
                    return *this;
                }
                reverse_iterator operator ++ (int){
                    reverse_iterator temp=*this;
                    ptr--;
                    return temp;
                }
                reverse_iterator& operator -- (){
                    ptr++;
                    return *this;
                }
                reverse_iterator operator -- (int){
                    reverse_iterator temp=*this;
                    ptr++;
                    return temp;
                }
                bool operator == (const reverse_iterator& a) const{
                    return ptr==a.ptr;
                }
                bool operator != (const reverse_iterator& a) const{
                    return ptr!=a.ptr;
                }
        };
        reverse_iterator rbegin(){
            return reverse_iterator(data+dem-1);
        }
        reverse_iterator rend(){
            return reverse_iterator(data-1);
        }
};
#endif