%ifdef CONFIG
{
  "RegData": {
    "RAX": "0x12345607"
  },
  "Mode": "32BIT"
}
%endif
bits 32

mov eax, 0x1234561f
das
das
das
das
hlt
