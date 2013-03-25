#include <stdio.h>

void print_array(int nums[], int n) {
  int i;
  for(i = 0; i < n; i++) {
    printf("%d ", nums[i]);
  }

  fflush(stdout);
}

void overwrite_array(int orig[], int orig_size, int copy[], int copy_size) {
  int i = 0;
  while(i < orig_size) {
    orig[i++] = copy[i++];
  }
}

int main() {
  int orig[] = {1, 2, 3, 4, 5};
  int copy[] = {6, 7, 8, 9, 10};
  printf("orig: ");
  print_array(orig, 5);
  printf("\n");
  printf("copy: ");
  print_array(copy, 5);
  printf("\n");

  overwrite_array(orig, 5, copy, 5);
  printf("over: ");
  print_array(orig, 5);
  printf("%lu\n", sizeof(orig));
  printf("\n");

  return 0;
}
