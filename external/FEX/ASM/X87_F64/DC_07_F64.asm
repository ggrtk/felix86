%ifdef CONFIG
{
  "RegData": {
    "RAX":  "0x4010000000000000"
  },
  "Env": { "FEX_X87REDUCEDPRECISION" : "1" }
}
%endif
bits 64

mov rbx, 0xe0000000

lea rdx, [rel data]
fld tword [rdx + 8 * 0]

lea rdx, [rel data2]
fdivr qword [rdx + 8 * 0]

fst qword [rbx]
mov rax, [rbx]

hlt

align 8
data:
  dt 2.0
  dq 0
data2:
  dq 8.0
