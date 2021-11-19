#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

///выводит строку и переходит на новую строку
int f_puts(char s[]);

///возвращает указатель на первое вхождение символа ch в строку s
char* f_strchr(char s[], int ch);

///возвращает длину строки оканчивающейся нулевым символом
int f_strlen(char s[]);

///копирует строку s2 в строку s1
char* f_strcpy(char s1[], char s2[]);

///копирует строку s2 в строку s1 до n элементов
char* f_strncpy (char s1[], const char s2[], const int n);

///добавляет строку s2 в конец строки s1
char* f_strcat(char s1[], char s2[]);

///добавляет строку s2 в конец строки s1 до n элементов
char* f_strncat(char s1[], const char s2[], const int n);

///считывает файл stream до n-1 символов
char* f_fgets(char s[], int n, FILE* stream);

///дублирует строку
char* f_strdup(char s[]);

///пока не встретиться символ новой строки или EOF и записывает их в массив s
int f_getline(char** s, int* n, FILE* stream);



int f_puts(char s[])
{
    assert(s != NULL);

    for (int i = 0; s[i] != '\0'; i++)
        putchar(s[i]);
    putchar('\n');

    return '\n';
}

char* f_strchr(char s[], int ch)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == ch)
            return &s[i];
}

int f_strlen(char s[])
{
    assert(&s[0] != NULL);

    int len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}

char* f_strcpy(char s1[], char s2[])
{
    assert(&s1[0] != NULL);
    assert(&s2[0] != NULL);
    assert(&s1[0] != &s2[0]);

    int i;
    for (i = 0; s2[i] != '\0'; i++)
        s1[i] = s2[i];

    s1[i] = '\0';

    return s1;
}

char* f_strncpy (char s1[], const char s2[], const int n)
{
    assert(&s1[0] != NULL);
    assert(&s2[0] != NULL);
    assert(&s1[0] != &s2[0]);

    int i;
    for (i = 0; s2[i] != '\0' && i  < n; i++)
        s1[i] = s2[i];
    s1[i] = '\0';

    return s1;
}

char* f_strcat(char s1[], char s2[])
{
    assert(&s1[0] != NULL);
    assert(&s2[0] != NULL);
    assert(&s1[0] != &s2[0]);

    int len_s1 = f_strlen(s1);

    for (int i = 0; s2[i] != '\0'; i++)
        s1[i + len_s1] = s2[i];

    return s1;
}

char* f_strncat(char s1[], const char s2[], const int n)
{
    assert(s1 != NULL);
    assert(s2 != NULL);
    assert(s1 != &s2[0]);

    int len_s1 = f_strlen(s1);

    int i;
    for (i = 0; s2[i] != '\0' && i < n; i++)
        s1[i + len_s1] = s2[i];
    s1[i + len_s1] = '\0';

    return s1;
}

char* f_fgets(char s[], int n, FILE* stream)
{
    assert(s != NULL);
    assert(stream != NULL);

    long long i;
    long long in;
    for (i = 0; i < n; i++)
    {
        in = getc(stream);
        if (in != '\n' && in != EOF)
            s[i] = in;
        else
            i = n;
    }
    s[i] = '\0';

    if (in == EOF)
        return NULL;
    return s;
}

char* f_strdup(char s[])
{
    assert(s != NULL);

    char* copy_s = NULL;
    int len_s = f_strlen(s);
    copy_s = (char*) malloc(len_s * sizeof(char));

    for (long long i = 0; i <= len_s; i++)
        copy_s[i] = s[i];

    return copy_s;
}

int f_getline(char** s, int* n, FILE* stream)
{
    assert(s != NULL);
    assert(n != NULL);

    if (*s == NULL);
        *s = (char*) malloc(*n * sizeof(char));

    int in = EOF;
    long long i;
    for (i = 0; in != '\n' && in != '\0'; i++)
    {
        if (i == *n)
        {
            *n = i + 1;
            *s = (char*) realloc(*s, (*n) * sizeof(char));
        }

        in = getc(stream);
        if (in == EOF)
            return EOF;
        (*s)[i] = in;
    }

    if ((*s)[i - 1] == '\n')
    {
        if (i == *n)
        {
            *n = i + 1;
            *s = (char*) realloc(*s, (*n) * sizeof(char));
        }
        (*s)[i] = '\0';
    }

    return i;
}
