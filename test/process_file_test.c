#include <libturing/process_file.h>

#include <ctest.h>
#include <stdlib.h>
#include <string.h>

#define PATH_TEST "test/file_test.txt"

CTEST(suite_process_file, get_line)
{
    FILE* fin = fopen(PATH_TEST, "r");
    if (fin == NULL) {
        fprintf(stderr, "Error! Can't open `%s` ", PATH_TEST);
        ASSERT_NOT_NULL(fin);
    }

    char* line = get_line(fin);
    ASSERT_STR("   ", line);

    char* line2 = get_line(fin);
    ASSERT_STR("", line2);

    char* line3 = get_line(fin);
    ASSERT_STR("q1 a b l q2 ", line3);

    char* line4 = get_line(fin);
    ASSERT_STR(
            "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
            "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
            "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
            "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq3 a b r "
            "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
            "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
            "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
            "qqqqqqqqqqqqqqqqq4",
            line4);

    char* line5 = get_line(fin);
    ASSERT_NULL(line5);

    fclose(fin);
    free(line);
    free(line2);
    free(line3);
    free(line4);
    free(line5);
}

CTEST(suite_process_file, strip)
{
    char* line = calloc(32, sizeof(char));

    strcpy(line, "hello");
    line = strip(line);
    ASSERT_STR("hello", line);

    strcpy(line, " hello");
    line = strip(line);
    ASSERT_STR("hello", line);

    strcpy(line, "    ");
    line = strip(line);
    ASSERT_STR("", line);

    strcpy(line, "");
    line = strip(line);
    ASSERT_STR("", line);

    strcpy(line, "hello ");
    line = strip(line);
    ASSERT_STR("hello", line);

    strcpy(line, "hello\n\0");
    line = strip(line);
    ASSERT_STR("hello", line);

    strcpy(line, "hello\r\n");
    line = strip(line);
    ASSERT_STR("hello", line);

    free(line);
}

CTEST(suite_process_file, get_word)
{
    char* line = calloc(32, sizeof(char));

    strcpy(line, "hello\r\n");
    char* word = get_word(line);
    ASSERT_STR("hello", word);
    free(word);

    strcpy(line, strip("hello world "));
    word = get_word(line);
    ASSERT_STR("hello", word);
    free(word);

    strcpy(line, strip("   hello         "));
    word = get_word(line);
    ASSERT_STR("hello", word);
    free(word);

    strcpy(line, "");
    word = get_word(line);
    ASSERT_NULL(word);
    free(word);

    free(line);
}
