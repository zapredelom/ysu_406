
#include <cstring>
#include <iostream>
void print_prefix(const char a[], const char b[]) {

    int sz = 0;

    while (a[sz] == b[sz] && sz < 80) {
        std::cout << a[sz];
        sz++;
    }
}

void get_prefix(const char a[], const char b[], char c[]) {
    int i = 0;
    while (i < 80 && a[i] == b[i]) {
        c[i] = a[i];
        i++;
    }
    c[i] = '\0';
}
char *get_prefix_2(char a[], char b[]) {
    int a_sz = 0;
    while (a[a_sz++] != '\0')
        ;
    int b_sz = 0;
    while (b[b_sz++] != '\0')
        ;
    int ret_sz = (a_sz > b_sz ? b_sz : b_sz) + 1;
    char *ret = new char[ret_sz];
    int i = 0;
    while (a[i] == b[i] && i < ret_sz - 1) {
        ret[i] = a[i];
        i++;
    }

    ret[i] = '\0';

    return ret;
}

int main() {
    print_prefix("test", "tessaract");
    std::cout << std::endl;
    char c[80];
    get_prefix("test", "tessaract", c);
    std::cout << c << std::endl;
    char *prf = get_prefix_2("test", "tessaract");
    std::cout << prf << std::endl;
    delete[] prf;
}
