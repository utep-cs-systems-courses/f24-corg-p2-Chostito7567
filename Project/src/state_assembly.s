    ; Assembly for statemachine.c functions
    ;   - void sm_fast_clock()
    ;   - void sm_slow_clock()	

    .arch msp430g2553
    .text
    .global sm_fast_clock
    .global sm_slow_clock

; sm_fast_clock: Increment pwmCount (0 to 3)
sm_fast_clock:
    mov &pwmCount, r12      ; Load pwmCount into register r12
    add #1, r12             ; Increment pwmCount
    and #3, r12             ; Ensure pwmCount stays within 0-3 range
    mov r12, &pwmCount      ; Store result back to pwmCount
    ret                     ; Return from function

; sm_slow_clock: Increment ledMode and cycle through 3 states (off, dim, bright)
sm_slow_clock:
    mov &ledMode, r13       ; Load ledMode into register r13
    add #1, r13             ; Increment ledMode
    mov #3, r14             ; Load 3 into r14 (modulus value)
    cmp r14, r13            ; Compare ledMode to 3
    jl  next_state          ; If ledMode < 3, jump to next_state
    mov #0, r13             ; Reset ledMode to 0 (off)
next_state:
    mov r13, &ledMode       ; Store result back to ledMode
    ret                     ; Return from function
