;file ps.as
.entry LENGTH
.extern W
MAIN:   mov #40, LENGTH
LOOP:   prn #35
        cmp #15, #6
        sub r1, r4
        bne L3
L1:     inc K
        .entry LOOP
END:    stop
STR:    .string "abcdef"
LENGTH: .data 6,-9,15
K:      .data 22
        .extern L3