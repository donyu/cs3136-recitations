# Recitation 10 #

## Templates and the Standard Template Library (STL) ##

### What's a template? ###
Function templates are special functions that can operate with generic types.

This allows us to create a function template whose functionality can be adapted to 
more than one type or class without repeating the entire code for each type.

### Sample function template declaration ###
Remember how we wrote mergesort for a char array in lab 1?  What if we could write it for ANY kind of array?
