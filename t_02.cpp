#include<iostream>
#include<cstring>

class String {
    char* str;

public:
    String(const char* input) {
        std::cout << str<< std::endl;
        str = new char[strlen(input) + 1];
        std::cout << str<< std::endl;
        strcpy(str, input);
        std::cout << str<< std::endl;
    }
    
    char* join(const String& s) {
        if(str == NULL || s.str == NULL) {
            return NULL;
        }
        
        int index = 0, length = strlen(str);
        int sIndex = 0;
        
        while(s.str[sIndex] != '\0') {
            str[length] = s.str[sIndex];
            length++;
            index++;
            sIndex++;
        }
        
        str[length] = '\0';
        return str;
    }
    
    ~String() {
        delete[] str;
    }
};

int main() {
    String str1("Engineers are");
    String str2(" Creatures of logic");
    char* str3 = str1.join(str2);
    
    if (str3 != NULL) {
        std::cout << str3 << std::endl;
        delete[] str3;
    } else {
        std::cout << "Strings are NULL" << std::endl;
    }
    
    return 0;
}
