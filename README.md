# RP2040_polling_rotary_encoder_ISR
Interrupt example for Christer Janson's CCJencode class--RP2040 port

For details please see the blog post here:
https://audiodiwhy.blogspot.com/2024/08/debouncing-rotary-encoder-revisted.html

Chister Janson's C++ wrapper of Marco Pinterec's "rotary encoder" polling algorith

I have ported this to work with the RP2040 C/C++ SDK

It still uses an infinite loop in main, same as polling class, but to free up CPU time the reads only occur when a GPIO interrupt is thrown.

Main.c has a working example for the interrupt class; the port of Christer's code is in the C++ .h file.

If you want the "polling only" version of this (no ISR), please go to repo "RP2040_polling_rotary_encoder".
