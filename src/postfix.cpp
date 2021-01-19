// copyright 2021 Elizaveta D.
#include "postfix.h"

int operation_priority(char a) {
    switch (a) {
    case '(':
        return 0;
        break;
    case ')':
        return 1;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 3;
        break;
    default:
        return -1;
    }
}

bool check(char symbol) {
    return (symbol == '.' || symbol >= '0' && symbol <= '9');
}

std::string infix2postfix(std::string infix) {
    MyStack<char> stack(500);
    std::string result = "";
    std::string dop_stroka = "";
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ') {
            if (dop_stroka != "") {
                result = result + dop_stroka + " ";
                dop_stroka = "";
            }
            continue;
        }
        if (check(infix[i])) {
            dop_stroka += infix[i];
        }
        if (operation_priority(infix[i]) == 0) {
            stack.push(infix[i]);
        }
        if (operation_priority(infix[i]) == 1) {
            if (dop_stroka != "") {
                result = result + dop_stroka + " ";
                dop_stroka = "";
            }
            while (stack.get() != '(') {
                result = result + stack.pop() + " ";
            }
            stack.pop();
        }
        if (operation_priority(infix[i]) == 2 
            || operation_priority(infix[i]) == 3) {
            if (stack.isEmpty() ||
                operation_priority(stack.get()) 
                < operation_priority(infix[i])) {
                stack.push(infix[i]);
            } else {
                result = result + stack.pop() + " ";
                stack.push(infix[i]);
            }
        }
    }
    if (dop_stroka != "") {
        result = result + dop_stroka + " ";
    }
    while (!stack.isEmpty()) {
        result = result + stack.pop() + " ";
    }
    result.pop_back();
    return result;
}
