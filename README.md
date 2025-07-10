# Text
In this project I work with text in C language. This project was created as my assignemt for school 

## How to use
1.Open text.exe

2.Available commands
I/O Commands:
   in – load input
   out op – print the entire current text
   out range – print a selected range
   out mem – print the memory block

Movement in text:
   move {sp/ep} n – posuň sp (start pointer) alebo ep (end pointer) o n slov
   start {sp/ep} – nastav začiatok
   end {sp/ep} – nastav koniec

Word detection:
   first – select the first word
   last – select the last word
   prev – move to the previous word
   next – move to the next word

Operations with strings
   del – delete the selected range
   crop – keep only the selected range
   copy – copy the selected range to memory
   insert {n/mem} – insert either n spaces or the contents of memory at the current position
   replace – replace the selected range with the contents of memory

ERRORS:
   ERR_OVERFLOW – This occurs when an operation (like in or insert) would exceed the capacity of the op array.
   ERR_POSITION – This occurs when the sp pointer is positioned after the ep pointer (sp > ep), in commands like out range, del, crop, copy, insert, or replace.
   ERR_OUT_OF_RANGE – This occurs when a move command attempts to shift the pointer (sp or ep) outside the valid range of the op string.

Termination of the program:
   exit or quit

Example:


<img width="519" height="559" alt="image" src="https://github.com/user-attachments/assets/926f0a55-9268-4019-8534-a46e0cd9ca9f" />

