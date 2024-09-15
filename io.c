
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
    char c;

    if (n < 0) {
        if (write(1, "-", 1) != 1) return EOF;
        n = -n;
    }

    if (n >= 10) {
        if (write_int(n / 10) == EOF) return EOF;
    }

    c = (n % 10) + '0';
    return (write(1, &c, 1) == 1) ? 0 : EOF;
}
