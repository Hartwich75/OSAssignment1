
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
  return EOF;
}
