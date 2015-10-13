# GWI
A cross platform c really lightweight GUI for responsive APPs

## Why this library ?
This library aims to reproduce the idea of Canvas used by javascript to 
implement a cross platform gui library.
After creating the Canvas API, this library will try to recrete the idea of 
a material design like GUI using that API.

## How does a piece of code looks like
```c

  gwi_handle *h = gwi_window();
  gwi_graphics *g = gwi_get_graphics(h);
  // code starts here...
  
```