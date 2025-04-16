%ifdef CONFIG
{
  "RegData": {
    "MM0": "0x0000000041424344",
    "MM1": "0x0000515253545556",
    "MM2": "0x0061626364656667",
    "MM3": "0x38B939BA3ABB3BBC"
  },
  "MemoryRegions": {
    "0x100000000": "4096"
  }
}
%endif
bits 64

mov rdx, 0xe0000000

mov rax, 0x4142434445464748
mov [rdx + 8 * 0], rax
mov rax, 0x5152535455565758
mov [rdx + 8 * 1], rax

mov rax, 0x6162636465666768
mov [rdx + 8 * 2], rax
mov rax, 0x7172737475767778
mov [rdx + 8 * 3], rax

movq mm0, [rdx]
movq mm1, [rdx + 8]
movq mm2, [rdx + 16]
movq mm3, [rdx + 24]

psrlq mm0, 32
psrlq mm1, 16
psrlq mm2, 8
psrlq mm3, 1

hlt
