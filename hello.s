STACK_SEG = 0x4000    #堆栈段的起始位置，预处理

VGA_SEG = 0xb800         #根据协议
SCREEN_SIZE = 4000       #25*80*2 每个字符两个字节，属性和内容
WHITE = 0x7              #可查vga手册，白色为0x7

.code16      #16位

.section ".bsdata","a"
hello_message:
	.ascii "hello,JL16110020"     #要显示的字符
	.byte 0               #后面加个空字符
               
.section ".signature","a"
.globl sig
sig:  .word 0xAA55       #offset 512
     二进制文件末尾为aa55，才可以作为引导扇区代码，第一个扇区为512字节

.section ".bstext","ax"
.globl bootsect_start
bootsect_start:
	jmp begin



	.p2align 4           #边界对齐
begin:
	cli               #关中断
	movw %cs,%ax           #设置代码段位置
	movw %ax,%ds               
	movw %ax,%es

	movw $STACK_SEG,%ax       #设置堆栈段位置
	movw %ax,%ss            

	xorw %sp,%sp         #清零
	cld                   #开中断

clear:                           #清屏
	movw $VGA_SEG,%ax        #加载
	movw %ax,%es
	xorw %di,%di
	movw $0000,%ax           #初始位置
	movw $SCREEN_SIZE,%cx      #大小
	rep stosb           #重复执行

print_hello:
	movw $hello_message,%si     #加载字符串
	movb $WHITE,%ah           #加载颜色
	movl $(11*80),%edx           #加载大小
	call print            #调用输出函数
dead: jmp dead                #死循环

print:
	movw $VGA_SEG,%bx          
	movw %bx,%es
loop:
	lodsb            #读取第一个字符
	andb %al,%al
	jz end      #如果标志寄存器z里面是0 则跳转   
	movw %ax,%es:0(,%edx,2)      
	incl %edx   #自增1        
	jmp loop
end:
	ret         #函数调用返回
