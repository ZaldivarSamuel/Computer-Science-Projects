.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
array DWORD 1,2,3

.code
main PROC

mov eax, array
xchg eax, [array + 4]

xchg eax, [array + 8]

xchg eax, [array]

	INVOKE ExitProcess, 0
main ENDP
END main