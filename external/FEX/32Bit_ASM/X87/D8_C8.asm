%ifdef CONFIG
{
  "RegData": {
    "MM7":  ["0x8000000000000000", "0x4001"]
  },
  "Mode": "32BIT"
}
%endif
bits 32

lea edx, [.data]

fld qword [edx + 8 * 0]
fmul st0, st0
hlt

.data:
dq 0x4000000000000000
