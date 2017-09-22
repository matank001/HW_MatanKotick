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
	PUSH 10 ; returns 55
	CALL Fibo

	print str$(eax),13,10

	CALL end_prog

Fibo:
	PUSH ebp
	MOV ebp, esp

	SUB esp, 12
	;fibo(1) = 1
	MOV ebx, [ebp + 8]
	CMP ebx, 1
	JE return_one
	;fibo(2) = 1
	MOV ebx, [ebp + 8]
	CMP ebx, 2
	JE return_one

	;fibo(n) = fibo(n-1) + fibo(n-2)
	MOV edx, ebx
	SUB edx, 1
	push edx
	CALL Fibo
	pop edx
	MOV [ebp - 4], eax

	SUB edx, 1
	push edx
	CALL Fibo
	pop edx
	MOV [ebp - 8], eax

	;return sum
	MOV eax, [ebp - 4]
	ADD eax, [ebp - 8]
	ADD esp, 12
	POP ebp
	RET

	return_one:
		MOV eax, 1
		ADD esp, 12
		POP ebp
		RET

end_prog:
	call ExitProcess

end _start
