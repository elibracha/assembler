;file ps.as

.entry LENGTH
.extern W

MAIN:   mov r1, r6
        prn #35
LOOP:   cmp #45, #23
        inc K
T:      .data 100, 213,213, 123, 123
        .entry LOOP
END:    stop
STR:    .string "abcdef"
LENGTH: .data 6,9,15
K:      .data 22
        .extern L3
P:      .struct 6, "32422a"