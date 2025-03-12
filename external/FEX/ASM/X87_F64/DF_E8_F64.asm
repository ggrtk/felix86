%ifdef CONFIG
{
  "RegData": {
    "RBX": "0x0",
    "RCX": "0x1",
    "RDI": "0x40",
    "RSI": "0x45",
    "RBP": "0x45"
  }
}
%endif
bits 64

lea rdx, [rel one]
fld tword [rdx + 8 * 0]

lea rdx, [rel two]
fld tword [rdx + 8 * 0]

; Mask for CF, PF, ZF flags
mov rax, 0b1000101

; st(0) > st(i)
fucomip st1
pushfq
pop rbx
and rbx, rax

lea rdx, [rel minus_one]
fld tword [rdx + 8 * 0]

; st(0) < st(i)
fucomip st1
pushfq
pop rcx
and rcx, rax

lea rdx, [rel one]
fld tword [rdx + 8 * 0]

; st(0) == st(i)
fucomip st1
pushfq
pop rdi
and rdi, rax

lea rdx, [rel qnan]
fld tword [rdx + 8 * 0]

; st(0) == NaN
fucomip st1
pushfq
pop rsi
and rsi, rax

lea rdx, [rel qnan]
fld tword [rdx + 8 * 0]

lea rdx, [rel one]
fld tword [rdx + 8 * 0]

; st(i) == NaN
fucomip st1
pushfq
pop rbp
and rbp, rax

hlt

align 8
one:
  dt 1.0

align 8
two:
  dt 2.0

align 8
minus_one:
  dt -1.0

align 8
qnan:
  dq 0xC000000000000001
  dw 0x7FFF