


        .text
         
        # 1. Carrega constante para $r0
        li 0,0
        lb $r0,$t0
         
        # 2. Inicia tamanho do vetor em $r1
        li 0,5
        mov $t0,$r1
         
        # 3. Inicia variavel de contagem do laco
        li 0,0
        mov $t0,$r2
         
        # 4. Laço principal
         
        inc 00,0,$r2
        lb $r3,$r2
        mul 00,0,$r3,$r0
        sb $r2,$r3
        mov $r2,$t0
        div 00,0,$t0,$r1
        jz -7
         
        halt
         
        .data
         
        .byte 8
        .byte 1
        .byte 2
        .byte 3
        .byte 4
        .byte 5
         

