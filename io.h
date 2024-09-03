
#ifndef IO_H_
#define IO_H_
/**
 * These functions should provide simple reading and writing for 
 *  stdin and stdout respectively. They replace similar functions in 
 *  <stdio.h> which is not to be used.
 */

#define EOF (-1)

/* Reads next char from stdin. If no more characters, it returns EOF */
extern int
read_char();

/* Writes a character to stdout.  If no errors occur, it returns 0, otherwise EOF */
extern int
write_char(char c);

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
extern int
write_string(char* s);

/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */
extern int
write_int(int n);

#endif /* IO_H_ */
