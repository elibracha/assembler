;file ps.as
.entry LENGTH
.extern W
MAIN:   mov #40, LENGTH
        prn #35
RUN:    cmp #15, #6
LOOP:   cmp #45, #23
IN:     cmp #230, #34
L1:     inc K
        .entry LOOP
END:    stop
STR:    .string "abcdef"
LENGTH: .data 6,-9,15
K:      .data 22
        .extern L3