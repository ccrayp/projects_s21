#ifndef ELEMENT_H
#define ELEMENT_H

#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4

#define SIN 1
#define COS 2
#define TG 3
#define CTG 4
#define LN 5
#define SQRT 6
#define UNARY_MINUS 7

typedef enum Element_code {
    NUMBER,
    OPERATOR,
    FUNCTION,
    VARIABLE,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS,
    ERROR
} Element_code;

typedef struct Element {
    Element_code type;
    int priority;
    int value;
    double real_value;
} Element;

#endif
