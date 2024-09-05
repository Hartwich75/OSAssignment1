
#include <errno.h>
#include <unistd.h>

#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char() {
    char arr[1];
    int bytes_read = read(0,arr,1);
    if(bytes_read <= 0) {
        return EOF;
    }
  return arr[0];
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
    char arr[1] = {c};
    int bytes_written = write(1,arr,1);
    if(bytes_written <= 0) {
        return EOF;
    }
  return arr[0];
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
    int inital_buff = 100;
    char buffer[inital_buff];
    int index = 0;
    char c;

    while ((c = s[index]) != '\0' && index < inital_buff -1) {
        buffer[index] = c;
        index++;
    }
    buffer[index] = '\0';
    int bytes_written = write(1, buffer, index);
    if(bytes_written < index) return EOF;
  return 0;
}

/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */
int
write_int(int n) {
    char buffer[12];
    int i = 0;
    int isNegative = 0;

    if(n == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
    } else {
        if(n < 0) {
            isNegative = 1;
            n = -n;
        }

        while(n != 0) {
            int digit = n % 10;
            buffer[i++] = digit + '0';
            n = n / 10;
        }

        if(isNegative) {
            buffer[i++] = '-';
        }

        buffer[i] = '\0';

        int start = 0;
        int end = i - 1;
        while (start < end) {
            char temp = buffer[start];
            buffer[start] = buffer[end];
            buffer[end] = temp;
            start++;
            end--;
        }
    }
    int bytes_written = write(1, buffer, i);
    if(bytes_written < i) {
        return EOF;
    }
  return 0;
}
