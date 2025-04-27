%ifdef CONFIG
{
  "RegData": {
    "RAX": "0x3F800000",
    "MM7": ["0x8000000000000000", "0x4000"]
  },
  "Mode": "32BIT"
}
%endif
org 10000h
bits 32

lea edx, [.data]

fld dword [edx + 8 * 0]
fstp dword [edx + 8 * 2]
fld dword [edx + 8 * 1]

mov eax, [edx + 8 * 2]

hlt

.data:
dq 0x3f800000
dq 0x40000000
dq 0
