
/* You are not allowed to use <stdio.h> */
#include "io.h"


/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command 
 * interpreter as  specified in the handout.
 */
int
main()
{
  /*-----------------------------------------------------------------
   *TODO:  You need to implement the command line driver here as
   *       specified in the assignment handout.
   *
   * The following pseudo code describes what you need to do
   *  
   *  Declare the counter and the collection structure variables
   *
   *
   *  In a loop
   *    1) Read a command from standard in using read_char function
   *    2) If the command is not 'a', 'b', 'c': then break the loop
   *    3) Process the command as specified in the handout
   *  End loop
   *
   *  Print your collection of elements as specified in the handout
   *    as a comma delimited series of integers
   *-----------------------------------------------------------------*/

  int count = 0;
  char * prompt = "Press q then return to quit\n";

  write_string(prompt);

  char c;
  do {
      c = read_char();
      if(c < 0) {
          break;
      }
      if(c == 'a') {

      }
      if(c == 'b') {
          count++
      }
      if(c == 'c') {

      }

  } while(c != 'q');

    write_char('\n');
  if(c == 'q') {

      write_string("Count = ");
      write_int(count);
      write_char('\n');
      write_string("Collection: ");
      write_char('\n');
  }else {
      write_string("ERROR");
      write_char('\n');
      return 1;
  }

  return 0;
}
