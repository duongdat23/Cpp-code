// 3.assignment_use_bitwise_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include<thread>
using namespace std;

#define PORTB 0x00


#define MARK_PORTB0 (1<<0) 
#define MARK_PORTB1 (1<<1)
#define MARK_PORTB2 (1<<2)
#define MARK_PORTB3 (1<<3)
#define MARK_PORTB4 (1<<4)
#define MARK_PORTB5 (1<<5)
#define MARK_PORTB6 (1<<6)
#define MARK_PORTB7 (1<<7)

// cách dài hơn nhưng chắc là giống với adurino hơn 
void set_portB1(int& port, int porti, int a[]);
void reset_portB1(int& port, int porti, int a[]);

// cách làm nhanh gọn hơn 
void set_portB(int& port, int porti, int a[]);
void reset_portB(int& port, int porti, int a[]);

void display_led(int a[]);

int main() {
    int ouput_led[8] = { 0 };

    int PORTB_copy = PORTB;
    while (1) {
        break; 
    }
    for (int i = 0; i < 8; i++) {
        set_portB1(PORTB_copy, i, ouput_led);
        display_led(ouput_led);
        this_thread::sleep_for( chrono::seconds(1));
        reset_portB1(PORTB_copy, i, ouput_led);
    }

}
void set_portB1(int& port, int porti, int a[]) {

    switch (porti)
    {
    case 0:
        port = port | MARK_PORTB0;
        break;
    case 1:
        port = port | MARK_PORTB1;
        break;
    case 2:
        port = port | MARK_PORTB2;
        break;
    case 3:
        port = port | MARK_PORTB3;
        break;
    case 4:
        port = port | MARK_PORTB4;
        break;
    case 5:
        port = port | MARK_PORTB5;
        break;
    case 6:
        port = port | MARK_PORTB6;
        break;
    case 7:
        port = port | MARK_PORTB7;
        break;

    }
    a[porti] = 1;
}
void reset_portB1(int& port, int porti, int a[]) {

    switch (porti)
    {
    case 0:
        port = port & ~MARK_PORTB0;
        break;
    case 1:
        port = port & ~MARK_PORTB1;
        break;
    case 2:
        port = port & ~MARK_PORTB2;
        break;
    case 3:
        port = port & ~MARK_PORTB3;
        break;
    case 4:
        port = port & ~MARK_PORTB4;
        break;
    case 5:
        port = port & ~MARK_PORTB5;
        break;
    case 6:
        port = port & ~MARK_PORTB6;
        break;
    case 7:
        port = port & ~MARK_PORTB7;
        break;

    }
    a[porti] = port;
}


void set_portB(int& port, int porti, int a[]) {
    port = port | 1 << porti;
    a[porti] = 1;
}
void reset_portB(int& port, int porti, int a[]) {
    port = port & ~(1 << porti);
    // Reset tất cả các phần tử trong mảng thành 0
    fill(a, a + 8, 0);
}

void display_led(int a[]) {
    copy(a, a + 8, ostream_iterator<int>(cout, " "));
    cout << endl;
}
