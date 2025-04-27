%ifdef CONFIG
{
  "RegData": {
    "MM6": ["0x8000000000000000", "0x4001"],
    "MM7": ["0xC000000000000000", "0x4000"]
  },
  "Mode": "32BIT"
}
%endif
org 10000h
bits 32

lea edx, [data]
fld tword [edx + 8 * 0]

lea edx, [data2]
fld tword [edx + 8 * 0]
faddp st1, st0

lea edx, [data3]
fld tword [edx + 8 * 0]

hlt

align 8
data:
  dt 2.0
  dq 0
data2:
  dt 1.0
  dq 0
data3:
  dt 4.0
  dq 0

