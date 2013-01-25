---
layout: post
title: "Using a 1D Array as a 2D Array in C"
date: 2013-01-24 18:21
comments: true
categories: 
---
Lately, I've been writing a lot of C code and using large multidimensional arrays. I've found that using a simple macro to map a 1D array to a 2(or more)D array has simplified my code and may make my code marginally faster.

### Macro:
    #define DATA(r, c) (data[(r)*width + (c)])
### Accessing the array:
    DATA(rowNdx, colNdx) = x;
### Why
- Only need to `malloc` and `free` once(`malloc(sizeof(char) * width * height)` instead of `malloc`ing for each row of the array
- Since the preprocessor handles the macro, there isn't any extra overhead of function calls
- Array access is terse and it's very clear what is going on - instead of `arr[x][y]`, you have `arr(x,y)`
