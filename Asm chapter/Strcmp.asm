.486
.model flat, stdcall
option casemap :none

;;include \masm32\include\kernel32.inc
;;include \masm32\include\masm32.inc
;;includelib \masm32\lib\kernel32.lib
;;includelib \masm32\lib\masm32.lib

include \masm32\include\masm32rt.inc  

.data

str1 db "matan", 0
str2 db "matan", 0

.code

_start:

main:
	PUSH OFFSET str1
	PUSH OFFSET str2
	CALL Strcmp
	print str$(eax),13,10

	CALL end_prog


; if equal eax = 1
; if not equal eax = 0

Strcmp:
	PUSH ebp
	MOV ebp, esp

	MOV ebx, [ebp + 8]
	MOV esi, [ebp + 12]

	compare_loop:
		MOV dl, BYTE PTR[ebx]
		CMP BYTE PTR[esi], dl
		JNE not_equal
		CMP BYTE PTR[ebx], 0
		JE equal
		ADD esi, 1
		ADD ebx, 1
		JMP compare_loop

	not_equal:
		MOV eax, 0
		JMP end_Strcmp
	equal:
		MOV eax, 1

	end_Strcmp:
		POP ebp
		RET

Strlen:
	PUSH ebp
	MOV ebp, esp

	MOV ebx, [ebp + 8]
	MOV esi, 0

	MOV eax, 0

	count_loop:
		CMP BYTE PTR[ebx + esi], 0
		JE count_loop_out
		ADD eax, 1
		ADD esi, 1
		JMP count_loop
	count_loop_out:

	POP ebp
	RET




end_prog:
	call ExitProcess

end _start
