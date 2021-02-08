#include <iostream>
#include <string>
#include <regex>

using namespace std;

string convert_number(string number) {
    string convert_number;
    string number_of_uk = "44";
    smatch smatch;

    // numberが変換不要か判断する
    if (regex_match(number, smatch, regex("^\\+44\\d{10}$"))) {
        return number;
    } else {
        convert_number = regex_replace(number, regex("^0"), "");            // 国番号0はないので、先頭の0を除去
        convert_number = regex_replace(convert_number, regex("\\s"), "");   // 空白文字の除去
        if (regex_match(convert_number, regex("^\\+*(?!44)\\d.*$"))) {      // 国番号が存在しなければ、追加する
            convert_number = "44" + convert_number;
        }
        if (convert_number[0] != '+') { // 先頭に"+"が存在しなければ、追加する
            convert_number = "+" + convert_number;
        }

        return convert_number;
    }
}

int main() {
    string number_list[5] = {
        "07555 123456",
        "07555123456",
        "+44 7555 123456",
        "44 7555 123456",
        "7555 123456"
    };

    for (string number : number_list) {
        cout << convert_number(number) << endl;
    }

    return 0;
} 
