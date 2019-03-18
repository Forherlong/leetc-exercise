#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define FAILED 1

char* toLowerCase(char* str);
bool is_upper_case(char oneChar);
char mapping_lower_case(char oneChar);

int main() {
        char str[] = "Hello, World.";
        toLowerCase(str);
        return SUCCESS;
}

bool is_upper_case(char oneChar) {
        if(oneChar >= 65 && oneChar <= 90) {
                return true;
        }
        return false;
}

char mapping_lower_case(char oneChar) {
        if(oneChar <= 90 && oneChar >= 65) {
                oneChar = oneChar + 32;
                return oneChar;
        }
        return oneChar;
}
char* toLowerCase(char* str) {
        int str_index = 0;
        while(str[str_index] != '\0') {
                if(is_upper_case(str[str_index])) {
                        str[str_index] = mapping_lower_case(str[str_index]);
                }
                str_index++;
        }
        printf("toLowerCase: %s\n", str);
        return str;
}
