# Recitation 10 #

## Templates and the Standard Template Library (STL) ##

### What's a template? ###
Function templates are special functions that can operate with generic types.

This allows us to create a function template whose functionality can be adapted to 
more than one type or class without repeating the entire code for each type.

### Sample function template: Merge Sort ###
Remember how we wrote mergesort for a char array in lab 1?  What if we could write it for ANY kind of array?
```c
template <typename T>
void merge_sort(T a[], int n)
{
  /* 
   * BASIS: if a has only 1 element, there is nothing to do.
   */
  if (n <= 1)
    return;
  
  
  /*
   * INDUCTION: merge_sort the 1st half and merge_sort the 2nd half
   * so that we have 2 half-size sorted arrays, and then merge them
   * into a single sorted array
   */
  int m = n / 2;
  
  /*
   * merge_sort the 1st m elements of a
   */
  merge_sort(a, m);
  
  /*
   * merge_sort the remaining n - m elements of the array "a + m",
   * which is a way to take a sub-array of "a" where a[m] is the new 
   * 0th element (i.e., (a+m)[0] is the same as a[m]).
   */
  merge_sort(a + m, n - m);

  /*
   * allocated a temporary array into which the merge function will
   * put the merged array.
   */
  T temp[n];

  /*
   * merge a (for which we are looking at only the 1st m elements)
   * and a+m (which has n-m elements from (a+m)[0] to (a+m)[n-m-1],
   *          which are really the same as a[m] to a[n-1])
   * into the temp array.
   */
  merge(a, m, a + m, n - m, temp);
  
  /*
   * copy the temp array back into a
   */
  for (int i = 0; i < n; i++)
    a[i] = temp[i];
}

template <typename T>
void merge(T a1[], int n1, T a2[], int n2, T output[])
{
  int i1 = 0;
  int i2 = 0;
  int j = 0;
  
  /*
   * go through the elements of a1 and a2,
   * copying the smaller one into the output array
   * until we reach the end of either a1 or a2.
   */
  while (i1 < n1 && i2 < n2) {
    /*
     * note that we take a1 if the two elements are the same.
     */
    if (a1[i1] <= a2[i2]) {
      output[j++] = a1[i1++];
    } else {
      output[j++] = a2[i2++];
    }
  }
  
  /*
   * copy over the remaining elements of a1, if any.
   */
  while (i1 < n1)
    output[j++] = a1[i1++];
  
  /*
   * copy over the remaining elements of a2, if any.
   */
  while (i2 < n2) 
    output[j++] = a2[i2++];
}
```
