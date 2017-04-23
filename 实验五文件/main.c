#define VGA_BASE 0xb8000
#define WHITE 0x7

unsigned short VGA_rows = 25;
unsigned short VGA_cols = 80;

void fun3(void) {          //清屏
	int row, col;
	unsigned short *ptr = (unsigned short *)VGA_BASE;
	for(row=0; row< VGA_rows; row++) {
	    for (col=0; col< VGA_cols; col++) {
		(*ptr++) = 0;
	    }
	}
}

void fun4(char c, char color, int row, int col) {  //存一个字符到VGA缓存中
	unsigned char *ptr = (unsigned char *)VGA_BASE;
	//unsigned short value;

	ptr[(row*80+col)*2] = c;
	ptr[(row*80+col)*2+1] = color;	
}

void fun5(char *msg, char color, int *_row, int *_col){  //存一个字符串到内存中，其实原理就是循环调用fun4
	char *ptr=msg;
	char c;
	int row, col;
	
	row = *_row;	col = *_col;
	c = *ptr;
	while (c!='\0'){
	    if ( col==80 ) {	col = 0;	row ++;	}
	    if ( row==25 ) row = 0;

	    fun4(c, color, row, col++);	    
	    c = *(++ptr);
	}
	
}

int myMain(void){
	char *message1 = "********************************\0";
	char *message2 = "*        HELLO JL16110020!          *\0";
	int row=0,col=0;
	
	fun3();

	row=1; col=4; fun5(message1,WHITE,&row,&col);
	row++; col=4; fun5(message2,WHITE,&row,&col);
	row++; col=4; fun5(message1,WHITE,&row,&col);	

	return 0;
}
