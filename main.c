
/* You are not allowed to use <stdio.h> */
#include "io.h"
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct List {
    Node *head;
    Node *tail;
    int Count;
}List;

void freeList (List* list) {
    Node *currentNode;
    while(list->head != NULL) {
        currentNode = list->head;
        list->head = list->head->next;
        free(currentNode);
    }
    free(list);
}

Node* initNode(int value) {
    Node* tempNode = (Node*) malloc(sizeof(Node*));
    tempNode->value = value;
    tempNode->next = NULL;
    tempNode->prev = NULL;
}

void insertNodeAtEnd(Node** head, int value) {
    Node* newNode = initNode(value);
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        write_int(temp->value);
        if(temp->next != NULL) write_char(',');
        temp = temp->next;
    }
    write_char(';');
}

/**
 *
 * @param head head of a doubly linked list
 * @return the new head
 */
void deleteFromEnd (Node** head) {
    if (*head == NULL) return;
    while ((*head)->next != NULL) head = (*head)->next;
    head = (*head)->prev;
    (*head)->next = NULL;
}

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
  Node *head = NULL;
  char * prompt = "Press q then return to quit\n";

  write_string(prompt);

  char c;
  do {
      c = read_char();
      if(c < 0) {
          break;
      }
      if(c == 'a') {
          insertNodeAtEnd(&head, count);
          count++;
      }
      if(c == 'b') {
          count++;
      }
      if(c == 'c') {
          deleteFromEnd(head);
          count++;
      }
  } while(c != 'q');

  if(c == 'q') {

      write_string("Collection: ");
      printList(head);
      write_char('\n');
  }else {
      write_string("ERROR");
      write_char('\n');
      return 1;
  }

  return 0;
}
