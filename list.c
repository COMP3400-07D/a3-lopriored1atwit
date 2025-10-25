#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * TODO: Describe what the function does
 * Takes and returns the last node from the list 
 * Returns null if there is nothing in the list
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if(head == NULL){
        return NULL;
    }

    struct ll_node *c = head;
    while(c -> next != NULL){
        c = c -> next;
    }
    return c;
}

/**
 * TODO: Describe what the function does
 * Takes the list and returns the number of elements inside
 * Returns 0 if the list contains nothing
 */
int ll_size(struct ll_node *head) {
  int i = 0;
  struct ll_node *c = head;
  while(c != NULL){
    i++;
    c = c -> next;
  }
  return i;
}

/**
 * TODO: Describe what the function does
 * Looks through the list for a node with the asking value
 * Returns null if there's nothing found
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
   struct ll_node *c = head;
   while (c != NULL)
   {
        if (c -> data == value)
        {
            return c;
        }
        c = c -> next;
   }
   return NULL;
}

/**
 * TODO: Describe what the function does
 * Takes the list and converts it into an integer array
 * If the list contains nothing it'll return null
 */
int *ll_toarray(struct ll_node *head) {
   int listSize = ll_size(head);
   if(listSize == 0){
    return NULL;
   }

   int *array = (int *) malloc(sizeof(int) * listSize);
   struct ll_node *c = head;
   for(int i = 0; i < listSize; i++){
        array[i] = c -> data;
        c = c -> next;
   }
   return array;
}

/**
 * TODO: Describe what the function does
 * This function creates a new list node with the given data
 */
struct ll_node *ll_create(int data) {
   struct ll_node *n = malloc(sizeof *n);
   if(n){
    n -> data = data;
    n -> next = NULL;
   }
   return n;
}

/**
 * TODO: Describe what the function does
 * "Destroys" all nodes inside the list
 * It frees the nodes
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *c = head;
    while(c != NULL){
        struct ll_node *next = c -> next;
        free(c);
        c = next;
    }
}

/**
 * TODO: Describe what the function does
 * Appends the node and sets to the tail end of the list
 * If the list contains nothing it'll return null
 */
void ll_append(struct ll_node *head, int data) {
    if (!head){
        return ;

    }
    struct ll_node *tail = ll_tail(head);
    tail -> next = ll_create(data);
}

/**
 * TODO: Describe what the function does
 * Makes a list from the array and returns the head of the new list
 * Returns nothing if the lens equals 0
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if(len == 0){
        return NULL;
    }

    struct ll_node *head = ll_create(data[0]);
    struct ll_node *tail = head;
    for(int i = 1; i < len; i++){
        tail -> next = ll_create(data[i]);
        tail = tail -> next;
    }
    return head;
}

/**
 * TODO: Describe what the function does
 * Takes the first node from the list and returns the head of the list
 * If there's nothing found it'll return the first head
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
     if (!head){
        return NULL;
    }
    
    if(head -> data == value){
        struct ll_node *nh = head -> next;
        free(head);
        return nh;
    }

    struct ll_node *c = head;
    while (c -> next != NULL){
        if(c -> next -> data == value){
            struct ll_node *del = c -> next;
            c -> next = del -> next;
            free(del);
            return head;
        }
        c = c -> next;
    }
    return head;
}

