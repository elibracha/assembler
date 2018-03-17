;file ps.as

.entry LENGTH
.extern W

MAIN:   mov #40, LENGTH
        prn #35
LOOP:   cmp #45, #23
        inc K
        .entry LOOP
END:    stop
STR:    .string "abcdef"
LENGTH: .data 6,9,15
K:      .data 22
        .extern L3
P:      .struct 6, "3242"