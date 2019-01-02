#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

void main() {
  struct ListNode a1;
  struct ListNode a2;

  int l1[] = {9, 9, 9};
  int l2[] = {9, 9, 9};

  int l1_size = sizeof(l1) / sizeof(l1[0]);
  struct ListNode* a1_ptr = &a1;
  int i = 0;
  for (; i < l1_size; ++i) {
    a1_ptr->val = l1[i];
    if (l1_size - 1 == i) {
      a1_ptr->next = NULL;
    } else {
      struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
      a1_ptr->next = temp;
      a1_ptr = a1_ptr->next;
    }
  }

  int l2_size = sizeof(l2) / sizeof(l2[0]);
  struct ListNode* a2_ptr = &a2;
  i = 0;
  for (; i < l2_size; ++i) {
    a2_ptr->val = l2[i];

    if (i == l2_size - 1) {
      a2_ptr->next = NULL;
    } else {
      struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
      a2_ptr->next = temp;
      a2_ptr = a2_ptr->next;
    }
  }

  struct ListNode* ret = addTwoNumbers(&a1, &a2);
  while (ret != NULL) {
    printf("%d ", ret->val);
    ret = ret->next;
  }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode *one = l1, *two = l2;
  struct ListNode* header = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* ptr = header;
  int pos = 0;

  for (; one != NULL && two != NULL; one = one->next, two = two->next) {
    ptr->val = one->val + two->val + pos;
    pos = 0;
    if (ptr->val >= 10) {
      ptr->val = ptr->val % 10;
      pos = 1;
    }

    if (one->next != NULL && two->next != NULL) {
      struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
      ptr->next = temp;
      ptr = ptr->next;
    }
  }

  // if link size is different
  if (one == NULL && two != NULL) {
    ptr->next = two;
  } else if (one != NULL && two == NULL) {
    ptr->next = one;
  } else if (one == NULL && two == NULL && pos >= 1) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->next = temp;
    temp->val = 0;
  }
  ptr = ptr->next;

  for (; pos >= 1; ptr = ptr->next) {
    if (ptr->val + pos >= 10) {
      ptr->val = (ptr->val + pos) % 10;
      pos = 1;
    } else {
      ptr->val += pos;
      pos = 0;
      break;
    }

    if (ptr->next == NULL && pos >= 1) {
      struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
      temp->val = 0;
      temp->next = NULL;
      ptr->next = temp;
    }
  }

  return header;
}