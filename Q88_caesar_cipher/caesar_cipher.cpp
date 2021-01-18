#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool check_input(string str, int shift_n);
string shift(string str, int shift_n);

int main() {
    int shift_n;
    string str, shifted;

    cout << "文字列とシフト数を受け付けます。文字列は大文字英字のみ。シフトは右シフトで、シフト数は正の整数のみ。" << endl;
    cout << "入力例: HOGEHOGE 15" << endl;
    cin >> str >> shift_n;

    if (!check_input(str, shift_n)) {   // 入力値の検証。
        cout << "入力が不適切です。" << endl;
        exit(0);
    } else {                            // 入力値の検証を通った場合はシフトを行う。
        shifted = shift(str, shift_n);
        cout << "シフト後の文字列: " << shifted << endl;
    }
}

bool check_input(string str, int shift_n) {
    smatch smatch;

    // 適切な入力か検証する。以下が適切な入力値。
    // strは大文字英字のみ。
    // shift_nは1以上。
    if (regex_match(str, smatch, regex("^[A-Z]+$"))) {
        if (0 < shift_n) {
            return true;
        }
    }
    return false;
}

string shift(string str, int shift_n) {
    const int n = shift_n % 26;
    int str_index[str.size()];
    string shifted; // シフト後の文字列
    const string map = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //cout << "size: " << sizeof(str_index) << endl;
    
    // 文字列中の各文字をmapと対応させる。そのために、各文字のindexを取得して配列str_indexに入れる。
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (str[i] == map[j]) {
                str_index[i] = j;
                break;
            }
        }
    }

    // 各文字のシフトを行う。
    for (int i = 0; i < str.size(); i++) {
        if (str_index[i] + n < 26) {   // シフトがオーバーフローしない場合
            shifted += map[str_index[i] + n];
        } else {            // シフトがオーバーフローする場合
            shifted += map[(str_index[i] + n) - 26];
        }
        //cout << "i: " << i << " " << "str: " << shifted << endl;
    }

    return shifted;
}