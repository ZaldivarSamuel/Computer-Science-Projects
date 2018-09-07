.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data

.code

main PROC

	mov eax, 5
	add eax, 6

	mov ebx, 7
	sub ebx, 2

INVOKE ExitProcess, 0

main ENDP
END main