%ifdef CONFIG
{
  "RegData": {
    "RAX": "0x12345a07"
  },
  "Mode": "32BIT"
}
%endif
bits 32

mov eax, 0x1234561f
aaa
aaa
aaa
aaa
hlt
