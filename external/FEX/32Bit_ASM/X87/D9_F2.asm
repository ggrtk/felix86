%ifdef CONFIG
{
  "RegData": {
    "MM6":  ["0x8000000000000000", "0x3FFF"],
    "MM7":  ["0xC75922E5F71D2DC6", "0x3FFF"]
  },
  "Mode": "32BIT"
}
%endif
bits 32

lea edx, [data]
fld tword [edx + 8 * 0]

fptan

hlt

align 8
data:
  dt 1.0
  dq 0
