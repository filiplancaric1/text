# Text
In this project I work with text in C language. This project was created as my assignemt for school 

## How to use
1.Open text.exe

2.Available commands<br>
I/O Commands:<br>
   in – load input<br>
   out op – print the entire current text<br>
   out range – print a selected range<br>
   out mem – print the memory block

Movement in text:<br>
   move {sp/ep} n – move the start pointer (sp) or end pointer (ep) by n characters<br>
   start {sp/ep} – set the start<br>
   end {sp/ep} – set the end<br>

Word detection:<br>
   first – select the first word<br>
   last – select the last word<br>
   prev – move to the previous word<br>
   next – move to the next word<br>

Operations with strings<br>
   del – delete the selected range<br>
   crop – keep only the selected range<br>
   copy – copy the selected range to memory<br>
   insert {n/mem} – insert either n spaces or the contents of memory at the current position<br>
   replace – replace the selected range with the contents of memory<br>

ERRORS:<br>
   ERR_OVERFLOW – This occurs when an operation (like in or insert) would exceed the capacity of the op array.<br>
   ERR_POSITION – This occurs when the sp pointer is positioned after the ep pointer (sp > ep), in commands like out range, del, crop, copy, insert, or replace.<br>
   ERR_OUT_OF_RANGE – This occurs when a move command attempts to shift the pointer (sp or ep) outside the valid range of the op string.<br>
   (After error program will automatically turn off)<br>

Termination of the program:<br>
   exit or quit<br>

Example:<br>


<img width="519" height="559" alt="image" src="https://github.com/user-attachments/assets/926f0a55-9268-4019-8534-a46e0cd9ca9f" />

