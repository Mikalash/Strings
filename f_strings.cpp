/**
@file
моя строковая библиотека
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
\brief выводит строку и переходит на новую строку
\param s указатель на первый элемент выводимой строки
\return возвращает символ новой строки
*/
int f_puts(char s[]);

/**
\brief ищет заданный символ в строке
\param s указатель первого элемента строки для обработки
\param ch искомый символ
\return указатель на первое вхождение символа ch в строку s
*/
char* f_strchr(char s[], int ch);

/**
\brief ищет дилну строки
\param s указатель на первый элемент строки
\return длина строки без учёта нуль терминатора
*/
int f_strlen(char s[]);

/**
\brief копирует одну строку в другую
\param s1 указатель на первый элемент строки назначения
\param s2 указатель на первый элемент строки источника
\return указатель на первый элемент строки назначения
*/
char* f_strcpy(char s1[], char s2[]);

///копирует строку s2 в строку s1 до n элементов
/**
\brief копирует одну строку в другую с ограничением на количество элементов
\param s1 указатель на первый элемент строки назначения
\param s2 указатель на первый элемент строки источника
\param n ограничение на количество копируемых элементов
\return указатель на первый элемент строки назначения
*/
char* f_strncpy (char s1[], const char s2[], const int n);

/**
\brief добавляет одну строку в конец другой
\param s1 указатель на первый элемент строки назначения
\param s2 указатель на первый элемент строки источника
\return указатель на первый элемент строки назначения
*/
char* f_strcat(char s1[], char s2[]);

/**
\brief добавляет одну строку в конец другой с ограничением на количество элементов
\param s1 указатель на первый элемент строки назначения
\param s2 указатель на первый элемент строки источника
\param n ограничение на количество добавляемых элементов
\return указатель на первый элемент строки назначения
*/
char* f_strncat(char s1[], const char s2[], const int n);

/**
\brief считывает поток ввода с ограничением на символы
\param s указатель на первый элемент строки в которую запишуться данные
\param n ограничение по количеству считываемых символов
\param stream указатель на поток ввода
\return указатель на первый элемент строки в которую запишуться данные
*/
char* f_fgets(char s[], int n, FILE* stream);

/**
\brief дублирует строку
\param s указатель на первый элемент строки которую нужно продублировать
\return указатель на дубликат строки
*/
char* f_strdup(char s[]);

/**
\brief пока не встретиться символ новой строки или EOF или будет достигнуто ограничение по элементам записывает их в массив
\param s двойной указатель на первый элемент строки в которую запишуться данные
\param n указатель на ячейку памяти в которой храниться ограничение по количеству считываемых элементов
\param stream указатель на поток ввода
\return возвращает количество считанных жлементов
*/
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
