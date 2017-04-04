STACK_SEG = 0x4000    #��ջ�ε���ʼλ�ã�Ԥ����

VGA_SEG = 0xb800         #����Э��
SCREEN_SIZE = 4000       #25*80*2 ÿ���ַ������ֽڣ����Ժ�����
WHITE = 0x7              #�ɲ�vga�ֲᣬ��ɫΪ0x7

.code16      #16λ

.section ".bsdata","a"
hello_message:
	.ascii "hello,JL16110020"     #Ҫ��ʾ���ַ�
	.byte 0               #����Ӹ����ַ�
               
.section ".signature","a"
.globl sig
sig:  .word 0xAA55       #offset 512
     �������ļ�ĩβΪaa55���ſ�����Ϊ�����������룬��һ������Ϊ512�ֽ�

.section ".bstext","ax"
.globl bootsect_start
bootsect_start:
	jmp begin



	.p2align 4           #�߽����
begin:
	cli               #���ж�
	movw %cs,%ax           #���ô����λ��
	movw %ax,%ds               
	movw %ax,%es

	movw $STACK_SEG,%ax       #���ö�ջ��λ��
	movw %ax,%ss            

	xorw %sp,%sp         #����
	cld                   #���ж�

clear:                           #����
	movw $VGA_SEG,%ax        #����
	movw %ax,%es
	xorw %di,%di
	movw $0000,%ax           #��ʼλ��
	movw $SCREEN_SIZE,%cx      #��С
	rep stosb           #�ظ�ִ��

print_hello:
	movw $hello_message,%si     #�����ַ���
	movb $WHITE,%ah           #������ɫ
	movl $(11*80),%edx           #���ش�С
	call print            #�����������
dead: jmp dead                #��ѭ��

print:
	movw $VGA_SEG,%bx          
	movw %bx,%es
loop:
	lodsb            #��ȡ��һ���ַ�
	andb %al,%al
	jz end      #�����־�Ĵ���z������0 ����ת   
	movw %ax,%es:0(,%edx,2)      
	incl %edx   #����1        
	jmp loop
end:
	ret         #�������÷���
