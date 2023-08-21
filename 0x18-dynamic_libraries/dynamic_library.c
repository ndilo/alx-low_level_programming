#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>  // Include this header for the NULL macro

int _putchar(char c) {
    return write(1, &c, 1);
}

int _islower(int c) {
    return (c >= 'a' && c <= 'z');
}

int _isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

int _isalpha(int c) {
    return _islower(c) || _isupper(c);
}

int _abs(int n) {
    return (n < 0) ? -n : n;
}

int _isdigit(int c) {
    return (c >= '0' && c <= '9');
}

int _strlen(char *s) {
    int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}

void _puts(char *s) {
    while (*s != '\0') {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}

char *_strcpy(char *dest, char *src) {
    char *originalDest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return originalDest;
}

char *_strchr(char *s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        s++;
    }
    if (c == '\0') {
        return s; // Returning pointer to null terminator if c is null terminator
    }
    return NULL;
}

unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;
    while (*s != '\0' && _strchr(accept, *s) != NULL) {
        count++;
        s++;
    }
    return count;
}

char *_strpbrk(char *s, char *accept) {
    while (*s != '\0') {
        if (_strchr(accept, *s) != NULL) {
            return s;
        }
        s++;
    }
    return NULL;
}

char *_strstr(char *haystack, char *needle) {
    while (*haystack != '\0') {
        char *h = haystack;
        char *n = needle;
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            return haystack; // needle found in haystack
        }
        haystack++;
    }
    return NULL; // needle not found
}
