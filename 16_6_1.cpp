#include <iostream>

bool is_capital_letter(char c){
    return 65 <= c && c <= 90;
}

bool is_small_letter(char c){
    return 97 <= c && c <= 122;
}

char transform(char c, int delta){
    if(is_capital_letter(c)){
        c-=65;
        c+=delta;
        if(c < 0){
            c += 26;
        } else if( c > 25){
            c -= 26;
        }
        c+=65;
    } else if (is_small_letter(c)){
        c-=97;
        c+=delta;
        if(c < 0){
            c += 26;
        } else if( c > 25){
            c -= 26;
        }
        c+=97;
    }
    return c;
}

std::string encrypt_caesar(std::string text, int delta){
    for(int i = 0; i < text.length(); i++){
        text[i] = transform(text[i], delta);
    }
    return text;
}

std::string decrypt_caesar(std::string text, int delta){
    return(encrypt_caesar(text, -delta));
}

int main() {
    std::string str;
    std::cout << "Input the string: ";
    std::getline(std::cin, str);
    std::cout << std::endl;

    int delta;
    std::cout << "Input delta:";
    std::cin >> delta;
    std::cout << std::endl;

    bool function;
    std::cout<<"Chose the function encrypt(text 1) or decrypt(text 0): ";
    std::cin >> function;
    std::cout << "Your output: " << (function ? encrypt_caesar(str, delta) : decrypt_caesar(str, delta)) << std::endl;
}