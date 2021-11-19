#include "f_strings.cpp"

int main()
{
    //tests

    char s[100];
    int n = 100;
    char* a = s;
    f_getline(&a, &n, stdin);

    printf("%s", a);
    return 0;
}
