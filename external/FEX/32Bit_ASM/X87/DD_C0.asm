%ifdef CONFIG
{
  "Mode": "32BIT"
}
%endif
org 10000h
bits 32

; Just to ensure execution
ffree st0
ffree st1
ffree st2
ffree st3
ffree st4
ffree st5
ffree st6
ffree st7
hlt
