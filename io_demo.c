
#include "io.h"

/**
 * The main function uses the various read and write functions defined in io.h
 * as a demonstration to you on how to use it. 
 *
 * It reads in a char from stdin and prints in back out onto
 * stdout while incrementing a counter. Note that the shell will usually 
 * buffer IO until a newline is encountered.  So you may not see output 
 * until you press the return or enter key.
 *
 * Entering a 'q' character in the input will cause the function
 * to stop reading and return printing the value of the counter.
 */

int
main()
{
  /* Create a counter to count how many bytes we read in */
  int count = 0;

  char * prompt = "Press q then return to quit\n";  

  write_string(prompt);

  /* Next just read a char then write it.  Over and over again.
   * We will use the 'q' character as an indicator of when to
   * terminate.  */
  char c;
  do 
    {
      c = read_char();

      /* Perform error checking */
      if (c < 0) {
          /* There was an error.  Just break for now */
          break;
      }

      /* Write c to stdout and increment counter*/
      write_char(c);
      count++;
    }
  while (c != 'q'); /* quit when we see a q char */

  write_char('\n');
  if (c == 'q') {
    /* Write final counter value */
    write_string("count = ");
    write_int(count);
    write_char('\n');
  } else {
    write_string("ERROR");
    write_char('\n');
    return 1;
  }

  return 0;
}
