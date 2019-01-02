#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x);

typedef struct _dynamic_array_node {
  int value;
  struct _dynamic_array_node *prev;
  struct _dynamic_array_node *next;
} dynamic_array_node;

int main() {
  for (int i = 1010; i <= 12000; ++i) {
    if (isPalindrome(i)) {
      printf("Yes %d\n", i);
    }
  }
}

bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  } else if (x >= 0 && x <= 9) {
    return true;
  }

  bool ret = false;
  int array_len = 0;

  // allocate memory
  dynamic_array_node *head =
      (dynamic_array_node *)malloc(sizeof(dynamic_array_node));
  dynamic_array_node *tail = head;
  tail->prev = NULL;

  // iterate input
  while (x > 0) {
    tail->value = x % 10;
    x = x / 10;
    if (x != 0) {
      dynamic_array_node *node =
          (dynamic_array_node *)malloc(sizeof(dynamic_array_node));
      node->prev = tail;
      tail->next = node;
      tail = tail->next;
      tail->next = NULL;
      ++array_len;
    }
  }

  // compare left and right
  dynamic_array_node *front = head, *end = tail;
  for (int i = 0; i <= array_len / 2; ++i) {
    if (front->value == end->value) {
      front = front->next;
      end = end->prev;
      ret = true;
      continue;
    }
    ret = false;
    break;
  }

  // free memory
  while (tail->prev) {
    tail = tail->prev;
    free(tail->next);
  }
  free(head);

  return ret;
}