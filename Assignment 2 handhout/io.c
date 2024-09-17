
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

#include "io.h"

/* 
 * This implementation cheats by using stdio
 * 
 */

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char() {
  return getchar();
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
  int r = putchar(c); 
  return (r > 0 ? 0 : EOF); 
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
  int r = puts(s); 
  return (r > 0 ? 0 : EOF); 
}

/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */
int
write_int(int n) {
  int r = printf("%d", n);
  return (r > 0 ? 0 : EOF); 
}
