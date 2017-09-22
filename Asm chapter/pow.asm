.486
.model flat, stdcall
option casemap :none

;;include \masm32\include\kernel32.inc
;;include \masm32\include\masm32.inc
;;includelib \masm32\lib\kernel32.lib
;;includelib \masm32\lib\masm32.lib

include \masm32\include\masm32rt.inc  

.data

.code

_start:

main:
	MOV eax, 2
	MOV ecx, 4

	PUSH eax
	PUSH ecx

	call pow
	print str$(eax),13,10

	call end_prog

pow:
	PUSH ebp
	MOV ebp, esp

	MOV ecx, [ebp + 8]

	MOV ebx, [ebp + 12]
	MOV eax, [ebp + 12]

	pow_loop:
		MUL ebx
		LOOP pow_loop

	POP ebp
	RET


end_prog:
	call ExitProcess

end _start
