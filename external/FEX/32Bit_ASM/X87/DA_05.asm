%ifdef CONFIG
{
  "RegData": {
    "XMM0":  ["0x8000000000000000", "0x3FFF"],
    "XMM1":  ["0xC000000000000000", "0xC000"]
  },
  "Mode": "32BIT"
}
%endif
org 10000h
bits 32

lea edx, [.data]

fld qword [edx + 8 * 0]
fisubr dword [edx + 8 * 1]
fstp tword [rel data2]
movups xmm0, [rel data2]

; Test negative
lea edx, [.data_neg]

fld qword [edx + 8 * 0]
fisubr dword [edx + 8 * 1]
fstp tword [rel data2]
movups xmm1, [rel data2]

hlt

.data:
dq 0x3ff0000000000000
dq 2

.data_neg:
dq 0x3ff0000000000000
dq -2

data2:
dq 0
dq 0
