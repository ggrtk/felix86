%ifdef CONFIG
{
  "RegData": {
    "RAX": "0x400",
    "MM7": ["0x8000000000000000", "0x3FFF"]
  },
  "Mode": "32BIT"
}
%endif
org 10000h
bits 32

lea edx, [.data]

fld dword [edx + 8 * 0]

fisttp dword [edx + 8 * 1]

fld1

mov eax, [edx + 8 * 1]

hlt

.data:
dq 0x44800000
dq 0
