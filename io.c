
#include <errno.h>
#include <unistd.h>

#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char() {
  char buf[1];
  int bytes_read = read(0, buf, 1);
  if (bytes_read <= 0) {
    return EOF;
  }
  return buf[0];
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
    if (write(1, &c, 1) == 1) {
        return 0;
    }
    char buff[1];
    int n = read(0, buff, 1);
    buff[n] = '\0';
    write(1, buff, n);
    return EOF;
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
    int i = 0;
    int result = 0;
    while (s[i] != '\0') {
        result = write_char(s[i]);
        if (result == EOF) {
            return EOF;
        }
        i++;
    }
        return 0;
    }




/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */
int
write_int(int n) {
    //convert int to string
    if (n == 0) {
        write_char('0');
        return 0;
    }
    char buffer[12];
    int i = 0;
    int start = 0;
    if (n < 0) {
        buffer[0] = '-';
        n = -n;
        i++;
        start = 1; // Start of the digit reversal for negative numbers
    }
    int rem = 0;
    while (n != 0) {
        rem = n % 10;
        buffer[i] = rem + '0';  // Convert digit to character
        n = n / 10;
        i++;
    }

    buffer[i] = '\0';  // Null-terminate the string

    // Reverse the digits in the buffer
    int end = i - 1;
    while (start < end) {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }

    write_string(buffer);

    return 0;
}

