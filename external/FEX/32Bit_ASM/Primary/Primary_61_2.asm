%ifdef CONFIG
{
  "RegData": {
    "RAX": "0xFF0006",
    "RCX": "0x5",
    "RDX": "0x4",
    "RSP": "0xE0000020",
    "RBX": "0x3",
    "RBP": "0x2",
    "RSI": "0x1",
    "RDI": "0x0"
  },
  "Mode": "32BIT"
}
%endif
org 10000h
bits 32

mov esp, 0xe0000020

mov eax, 0xFF0000
mov ecx, 0xFF
mov edx, 0xFF
mov ebx, 0xFF
mov ebp, 0xFF
mov esi, 0xFF
mov edi, 0xFF

push word 0x6
push word 0x5
push word 0x4
push word 0x3
push word 0x4142 ; Skipped
push word 0x2
push word 0x1
push word 0x0

o16 popa

hlt
