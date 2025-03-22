
%ifdef CONFIG
{
  "RegData": {
    "RSP": "0xE0000040"
  },
  "Mode": "32BIT"
}
%endif
bits 32

mov esp, 0xe0000040
mov eax, 0

push eax
push eax
push eax
push eax
push eax

push ax
push ax
push ax
push ax
push ax

; Only pops the segments
; Doesn't check for a correct segment value
; Just ensures we are popping the correct amount of data
pop ss
pop ds
pop es
pop fs
pop gs

o16 pop ss
o16 pop ds
o16 pop es
o16 pop fs
o16 pop gs

hlt
