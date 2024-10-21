#include "get_data.h"

double get_number(char **string) {
    char find_point = 0;
    char counter = 0;
    char *ptr = *string;
    double answer = 0;

    while ((!isnan(answer)) && ((('0' <= *ptr) && (*ptr <= '9')) || (*ptr == '.') || (*ptr == ','))) {
        if ((*ptr == '.') || (*ptr == ',')) {
            ptr++;
            if (find_point) answer = NAN;
            find_point = 1;
            counter = 0;
            continue;
        }

        if (find_point) counter++;
        answer *= 10;
        answer += *ptr++ - '0';
    }

    *string = ptr;
    double result;
    if (!isnan(answer))
        result = (double)(answer) / pow(10, counter);
    else
        result = answer;
    return result;
}

int get_function(char **string) {
    int result = 0;
    if (check_prefix(*string, "sin")) {
        (*string) += 3;
        result = SIN;
    } else if (check_prefix(*string, "cos")) {
        (*string) += 3;
        result = COS;
    } else if (check_prefix(*string, "tan")) {
        (*string) += 3;
        result = TG;
    } else if (check_prefix(*string, "ctg")) {
        (*string) += 3;
        result = CTG;
    } else if (check_prefix(*string, "ln")) {
        (*string) += 2;
        result = LN;
    } else if (check_prefix(*string, "sqrt")) {
        (*string) += 4;
        result = SQRT;
    }
    return result;
}

Element get_operator(char **string) {
    Element element;
    element.type = OPERATOR;

    if (**string == '+') {
        element.value = PLUS;
        element.priority = 0;
    }
    if (**string == '-') {
        element.value = MINUS;
        element.priority = 0;
    }
    if (**string == '*') {
        element.value = MULTIPLICATION;
        element.priority = 1;
    }
    if (**string == '/') {
        element.value = DIVISION;
        element.priority = 1;
    }
    (*string)++;

    element.real_value = 0.0;
    return element;
}

Element get_element(char **string) {
    Element element;

    if ((**string >= '0') && (**string <= '9')) {
        element.type = NUMBER;
        element.real_value = get_number(string);
        element.priority = 0;
        element.value = 0;
        if (isnan(element.real_value)) element.type = ERROR;
    } else if ((**string == '+') || (**string == '-') || (**string == '*') || (**string == '/')) {
        element = get_operator(string);
    } else if (**string == 'x') {
        element.type = VARIABLE;
        element.priority = 0;
        element.value = 0;
        (*string)++;
    } else if (**string == '(') {
        element.type = OPEN_PARENTHESIS;
        element.priority = -1;
        element.value = 0;
        (*string)++;
    } else if (**string == ')') {
        element.type = CLOSE_PARENTHESIS;
        element.priority = -1;
        element.value = 0;
        (*string)++;
    } else if (is_function(*string)) {
        element.type = FUNCTION;
        element.priority = 2;
        element.value = get_function(string);
    } else {
        element.type = ERROR;
        (*string)++;
    }

    return element;
}

char *get_string() {
    char c;
    char *string = (char *)malloc(START_LENGTH_LINE * sizeof(char));
    char *try_string;
    int size = 0;
    int real_size = START_LENGTH_LINE;

    while (((c = getchar()) != '\n') && (c != (int)EOF)) {
        if (size + 1 > real_size) {
            try_string = (char *)realloc(string, real_size * RESIZE_BUFFER_FACTOR * sizeof(char));
            if (try_string)
                string = try_string;
            else {
                free(string);
            }
            real_size *= RESIZE_BUFFER_FACTOR;
        }

        string[size++] = c;
    }

    if (size + 1 > real_size) {
        try_string = (char *)realloc(string, (real_size + 1) * sizeof(char));
        if (try_string)
            string = try_string;
        else {
            free(string);
        }
    }
    string[size] = '\0';

    return string;
}

int is_function(char *str) {
    int result = 0;
    if (check_prefix(str, "sin") || check_prefix(str, "cos") || check_prefix(str, "tan") ||
        check_prefix(str, "ctg") || check_prefix(str, "ln") || check_prefix(str, "sqrt"))
        result = 1;
    return result;
}
int check_prefix(char *string, char *prefix) {
    int check = 1;
    if (strlen(string) < strlen(prefix)) check = 0;
    if (check == 1) {
        for (int i = 0; i < (int)strlen(prefix); i++) {
            if (string[i] != prefix[i]) {
                check = 0;
                break;
            }
        }
    }

    return check;
}
List *string_to_list(char *string) {
    int error = 0;
    List *list = list_init();
    if (!list) error++;

    while (!error && (*string != '\0')) {
        if (*string == ' ') {
            string++;
            continue;
        } else {
            Element temp_element = get_element(&string);
            if ((temp_element.type == OPERATOR) && (temp_element.value == MINUS)) {
                Element previous_element = list_get(list, -1);
                if (!((previous_element.type == CLOSE_PARENTHESIS) || (previous_element.type == NUMBER) ||
                      (previous_element.type == VARIABLE))) {
                    temp_element.type = FUNCTION;
                    temp_element.priority = 2;
                    temp_element.value = UNARY_MINUS;
                }
            }
            list_add(list, temp_element);
            if (temp_element.type == ERROR) error++;
        }
    }

    return list;
}
