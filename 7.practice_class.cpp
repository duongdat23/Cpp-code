// practice_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Khai báo một lớp quản lý mảng các số thực.
// Lớp này sẽ có thành viên là số lượng phần tử, và mảng lưu trữ được cấp phát động
// Lớp cần có hàm constructor đúng và destructor đúng.
// Lớp sẽ có toán tử + : cộng từng thành viên của 2 mảng
// Lớp có toán tử[] để truy cập 1 phần tử của mảng
// Lớp có toán tử() để tính tổng các phần tử của mảng
// Lớp có toán tử << để in ra tất cả các phần tử của mảng
// class MyArray a(10), b(10);
// class MyArray c = a + b;
// a[10] = >> báo lỗi return N / A;
// c[0] = a[0] + b[0];
// c[1] = a[1] + b[1];
// float sum = a(); /// sum = a[0]+a[1]+...a[9];
#include <iostream>
class F_array
{
private:
    int number_elements;
    float *array;

public:
    F_array(int n);
    ~F_array();
    float &operator[](int);
    float operator()();
    friend std::ostream &operator<<(std::ostream &os, const F_array &s);
};
std::ostream &operator<<(std::ostream &os, const F_array &s)
{
    for (int i = 0; i < s.number_elements; i++)
    {
        os << s.array[i] << ' ';
    }
    std::cout << std::endl;
}

float &F_array::operator[](int i)
{
    if (i > number_elements - 1)
        std::cout << "Erorr!\n";
    else
        return array[i];
}
float F_array ::operator()()
{
    float result = 0;
    for (size_t i = 0; i < number_elements; i++)
    {
        result += array[i];
    }
    return result;
}
F_array::F_array(int n)
{
    std::cout << "Default constructor : \n";
    number_elements = n;
    array = new float(n);
    memset(array, 0, sizeof(float));
}

F_array::~F_array()
{
    number_elements = 0;
    delete[] array;
}

int main()
{
    F_array a(4);
    a[3] = 10;
    std::cout << a();
}
