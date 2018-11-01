org 100h
jp .loop

.loop:
    ; main loop code
    ld a,1
    jp .loop
    
halt
