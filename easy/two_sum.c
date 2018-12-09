#include <stdio.h>
#include <stdlib.h>

static int *two_sum(int *nums, int num_size, int target);

int main() {
  int nums[5] = {5, 3, 0, 12, 6};
  int *ret = two_sum(nums, 5, 9);
  printf("%d %d\n", *ret, *(ret + 1));
  free(ret);
}

int *two_sum(int *nums, int num_size, int target) {
  int *ret = (int *)malloc(sizeof(int) * 2);
  for (int i = 0; i < num_size; ++i) {
    for (int j = i + 1; j < num_size; ++j) {
      if (*(nums + i) + *(nums + j) == target) {
        *ret = i;
        *(ret + 1) = j;
        goto re;
      }
    }
  }
re:
  return ret;
}