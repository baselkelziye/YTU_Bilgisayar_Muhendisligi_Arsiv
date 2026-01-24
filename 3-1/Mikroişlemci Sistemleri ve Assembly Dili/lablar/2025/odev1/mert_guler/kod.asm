; matmul.asm

.386
.model flat, c
.code

PUBLIC matmul_asm

matmul_asm PROC NEAR
    push ebp
    mov ebp, esp

    push eax
    push ebx
    push ecx
    push edx
    push edi

    ; Dongu Degiskenleri
    ; [ebp-24] = i
    ; [ebp-28] = j
    ; [ebp-32] = k
    sub esp, 12

    ; C Parametreleri 
    ; [ebp+8] = *A (int *)
    ; [ebp+12] = *B (int *)
    ; [ebp+16] = *C (int *)
    ; [ebp+20] = A_rows (int)
    ; [ebp+24] = A_cols (int)
    ; [ebp+28] = B_cols (int)

    ; i = 0
    mov DWORD PTR [ebp-24], 0
loop_i: ; for (i = 0; i < A_rows; i++)
    mov eax, [ebp-24]  ; eax = i
    cmp eax, [ebp+20] 
    jge finish  ; i >= A_rows ise bitir

    ; j = 0
    mov DWORD PTR [ebp-28], 0
loop_j: ; for (j = 0; j < B_cols; j++)
    mov eax, [ebp-28] ; eax = j
    cmp eax, [ebp+28]
    jge next_i ; j >= B_cols ise i++ yap dis donguyu devam ettir

    ; C[i * B_cols + j] adresini hesapla. Sonuc adresi EDI'de.
    mov eax, [ebp-24] ; eax = i
    mov ecx, [ebp+28] ; ecx = B_cols
    imul ecx ; eax = i * B_cols
    add eax, [ebp-28]  ; eax = i * B_cols + j
    shl eax, 2 ; *4 (adres icin int'e yani DWORD'a cevir)
    mov ecx, [ebp+16] ; ecx = *C
    lea edi, [ecx + eax] ; edi = &C[i * B_cols + j]

    ; k = 0
    mov DWORD PTR [ebp-32], 0
loop_k: ; for (k = 0; k < A_cols; k++)
    mov eax, [ebp-32] ; eax = k
    cmp eax, [ebp+24]  
    jge next_j ; k >= A_cols ise ic donguyu bitir

    ; A[i * A_cols + k] degerini oku
    mov eax, [ebp-24] ; eax = i
    mov ecx, [ebp+24] ; ecx = A_cols
    imul ecx ; eax = i * A_cols
    add eax, [ebp-32]  ; eax = i * A_cols + k
    shl eax, 2 ; *4 (adres icin int'e yani DWORD'a cevir)
    mov ecx, [ebp+8] ; ecx = *A 
    mov eax, [ecx + eax] ; eax = A[i * A_cols + k]

    ; B[k * B_cols + j] degerini oku
    mov edx, [ebp-32] ; edx = k
    mov ecx, [ebp+28] ; ecx = B_cols
    mov ebx, eax
    mov eax, edx
    imul ecx  ; edx = k * B_cols
    mov edx, eax
    mov eax, ebx
    add edx, [ebp-28] ; edx = k * B_cols + j
    shl edx, 2  ; *4 (adres icin int'e yani DWORD'a cevir)
    mov ecx, [ebp+12]  ; ecx = *B 
    mov edx, [ecx + edx]    ; edx = B[k * B_cols + j]

    ; eax = A[i * A_cols + k] * B[k * B_cols + j]
    imul edx  

    ; edi = C[i * B_cols + j]
    ; Sonuca ekle
    mov ecx, [edi] 
    add ecx, eax
    mov [edi], ecx  

    ; k++
    inc DWORD PTR [ebp-32]
    jmp loop_k
next_j:
    ; j++
    inc DWORD PTR [ebp-28]
    jmp loop_j
next_i:
    ; i++
    inc DWORD PTR [ebp-24]
    jmp loop_i
finish:
    ; Dongu degiskenlerini temizle
    add esp, 12

    pop edi
    pop edx
    pop ecx
    pop ebx
    pop eax
    pop ebp
    ret
matmul_asm ENDP
END
