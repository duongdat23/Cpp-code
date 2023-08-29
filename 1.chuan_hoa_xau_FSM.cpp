#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "  DuonG  dinh  DAT      ";


    for (int i = 0; i < s.length(); i++) {
        if (s[0] == 32) {
            s.erase(0, 1);// xóa kí tự đầu 
            i--; 
            continue;
        }
        else if (i == 0) {
            s[i] = toupper(s[i]);
        }
        else if (s[i - 1] == 32) {
            if (s[i] == 32) {
                s.erase(i, 1);
                i--;
            }
            else if (s[i] != 32) {
                s[i] = toupper(s[i]);
            }
        }
        else if (s[i - 1] != 32) {
            s[i] = tolower(s[i]);
            if (i == s.length() - 1) {
                s.erase(s.length() - 1 , 1); // Loại bỏ các ký tự dư thừa sau ký tự dấu cách cuối cùng của chuỗi 
                break; 
            }
        }
    }

    cout << s;

    return 0;
}
