#include <errno.h>
#include <unistd.h>

#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char() {
    char c;
    return (read(0, &c, 1) <= 0) ? EOF : c;
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
    return (write(1, &c, 1) <= 0) ? EOF : 0;
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return (write(1, s, len) < len) ? EOF : 0;
}

/* Writes n to stdout (without any formatting).
 * If no errors occur, it returns 0, otherwise EOF
 */
int
write_int(int n) {
    char buffer[12];
    int i = 0, isNegative = 0;

    if (n == 0) {
        buffer[i++] = '0';
    } else {
        if (n < 0) {
            isNegative = 1;
            n = -n;
        }

        while (n != 0) {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }

        if (isNegative) {
            buffer[i++] = '-';
        }

        for (int start = 0, end = i - 1; start < end; start++, end--) {
            char temp = buffer[start];
            buffer[start] = buffer[end];
            buffer[end] = temp;
        }
    }

    return (write(1, buffer, i) < i) ? EOF : 0;
}
