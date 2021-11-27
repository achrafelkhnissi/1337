#include <stdio.h>
#include <stdlib.h>

char **split_whitespaces(const char *str);
char *strdup_w(const char *str, int *index);
int word_count(const char *str);
int iswhitespace(char c);

int main(void) {
    const char *str = "This is just a test!";
    char **arr_str;
    int i;

    arr_str = split_whitespaces(str);
    if (arr_str) {
        printf("\nOutside the function:\n");
        i = 0;
        while (arr_str[i]) {
            printf("arr_str[%d] = %s\n", i, arr_str[i]);
            i++;
        }
        while (i --> 0) {
            free(arr_str[i]);
        }
        free(arr_str);
    }
    return 0;
}

char **split_whitespaces(const char *str) {
    char **arr_str;
    int i;
    int words;
    int w_i;

    i = 0;
    w_i = 0;
    words = word_count(str);
    arr_str = malloc(sizeof(*arr_str) * (words + 1));
    if (!arr_str)
        return NULL;
    printf("Inside the function:\n");
    while (w_i < words) {
        while (iswhitespace(str[i]))
            i++;
        arr_str[w_i] = strdup_w(str, &i);
        if (!arr_str[w_i])
            break;
        printf("arr_str[%d] = %s\n", w_i, arr_str[w_i]);
        w_i++;
    }
    arr_str[words] = NULL;
    return arr_str;
}

char *strdup_w(const char *str, int *index) {
    char *word;
    int len;
    int start;
    int i;

    i = *index;
    start = i;
    while (str[i] && !iswhitespace(str[i])) {
        i++;
    }
    *index = i;
    len = i - start;
    word = malloc(len + 1);
    if (!word)
        return NULL;
    i = 0;
    while (i < len) {
        word[i] = str[start + i];
        i++;
    }
    word[i] = '\0';
    return word;
}

int word_count(const char *str) {
    int i;
    int w_count;
    int state;

    i = 0;
    w_count = 0;
    state = 0;
    while (str[i]) {
        if (!iswhitespace(str[i])) {
            if (!state)
                w_count++;
            state = 1;
        } else {
            state = 0;
        }
        i++;
    }
    return w_count;
}

int iswhitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}
