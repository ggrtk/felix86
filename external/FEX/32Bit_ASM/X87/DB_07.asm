%ifdef CONFIG
{
  "RegData": {
    "MM7":  ["0x8000000000000000", "0x4000"]
  },
  "Mode": "32BIT"
}
%endif
bits 32

lea edx, [data]
fld tword [edx + 8 * 0]

lea edx, [data2]
fstp tword [edx + 8 * 0]
fld tword [edx + 8 * 0]

hlt

align 8
data:
  dt 2.0
  dq 0
data2:
  dt 0.0
  dq 0
