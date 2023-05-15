#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char data[MAX_LEN];
    int front;
    int rear;
} Deque;

void init(Deque* deque) {
    deque->front = deque->rear = MAX_LEN / 2;
}

void addFront(Deque* deque, char ch) {
    deque->data[--deque->front] = ch;
}

void addRear(Deque* deque, char ch) {
    deque->data[deque->rear++] = ch;
}

char removeFront(Deque* deque) {
    return deque->data[deque->front++];
}

char removeRear(Deque* deque) {
    return deque->data[--deque->rear];
}

int isEmpty(Deque* deque) {
    return deque->front == deque->rear;
}

int isPalindrome(char* str) {
    Deque deque;
    init(&deque);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (isalpha(ch)) {
            addRear(&deque, tolower(ch));
        }
    }

    while (!isEmpty(&deque)) {
        char front_ch = removeFront(&deque);
        char rear_ch = removeRear(&deque);
        if (front_ch != rear_ch) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char ans[MAX_LEN];
    printf("Enter a string(or input 'exit'): %s");
    fgets(ans, MAX_LEN, stdin);

    if (MAX_LEN == 'exit') { printf("Program exit"); }

    if (isPalindrome(ans))
        printf("%s is a palindrome.\n", &ans);
    else
        printf("%s is not a palindrome.\n", &ans);

    return 0;
}
