#include "types.h"
#include "screen.h"
#include "file.h"

/*
void clear()
{
	int i=0;
	uint16_t *screen=(uint16_t *)0xb8000;

	for(i=0;i<150;i++){
	
	screen[i]=0x0200|' ';

	}
}




void print(char *str)
{
	static int i=0,j;
	static uint16_t *screen=(uint16_t *)0xb8000;

	for(j=0;str[j]!='\0';j++){
		screen[i++]=0x0200|str[j];
		
	}
	if(i==150){
		clear();
	}
	
}

	*/


uint8_t getvale(uint8_t h)
{
	if(h==0x00)
	{
		return 0x30;
	}
	if(h==0x01)
	{
		return 0x31;
	}
	if(h==0x02)
	{
		return 0x32;
	}
	if(h==0x03)
	{
		return 0x33;

	}
	if(h==0x04)
	{
		return 0x34;
	}
	if(h==0x05)
	{
		return 0x35;
	}
	if(h==0x06)
	{
		return 0x36;
	}
	if(h==0x07)
	{
		return 0x37;
	}
	if(h==0x08)
	{
		return 0x38;
	}
	if(h==0x09)
	{
		return 0x39;
	}
	if(h==0x0A)
	{
		return 0x61;
	}
	if(h==0x0B)
	{
		return 0x62;
	}
	if(h==0x0C)
	{
		return 0x63;
	}
	if(h==0x0D)
	{
		return 0x64;
	}
	if(h==0x0E)
	{
		return 0x65;
	}
	if(h==0x0F)
	{
		return 0x66;
	}
	return 0;
}	


void print32hex(uint32_t hex)
{
	
		
	

}



// The VGA framebuffer starts at 0xB8000.
uint16_t *video_memory = (uint16_t *)0xB80A0;
uint8_t line_buff[80];
uint8_t z=0;

// Stores the cursor position.
uint8_t cursor_x = 0;
uint8_t cursor_y = 0;
	

static void move_cursor()
{
	// The screen is 80 characters wide...
	uint16_t cursorLocation = cursor_y * 80 + cursor_x;
	outb(0x3D4, 14);                  // Tell the VGA board we are setting the high cursor byte.
	outb(0x3D5, cursorLocation >> 8); // Send the high cursor byte.
	outb(0x3D4, 15);                  // Tell the VGA board we are setting the low cursor byte.
	outb(0x3D5, cursorLocation);      // Send the low cursor byte.
}

static void scroll()
{

	// Get a space character with the default colour attributes.
	uint8_t attributeByte = (0 /*black*/ << 4) | (15 /*white*/ & 0x0F);
	uint16_t blank = 0x20 /* space */ | (attributeByte << 8);

	// Row 25 is the end, this means we need to scroll up
	if(cursor_y >= 25)
	{
		// Move the current text chunk that makes up the screen
		// back in the buffer by a line
		int i;
		for (i = 0*80; i < 24*80; i++)
		{
			video_memory[i] = video_memory[i+80];
		}

		// The last line should now be blank. Do this by writing
		// 80 spaces to it.
		for (i = 24*80; i < 25*80; i++)
		{
			video_memory[i] = blank;
		}
		// The cursor should now be on the last line.
		cursor_y = 24;
	}
}


void monitor_put(char c)
{
	line_buff[z++]=c;
	


	// The background colour is black (0), the foreground is white (15).
	uint8_t backColour = 0;
	uint8_t foreColour = 15;

	// The attribute byte is made up of two nibbles - the lower being the
	// foreground colour, and the upper the background colour.
	uint8_t  attributeByte = (backColour << 4) | (foreColour & 0x0F);
	// The attribute byte is the top 8 bits of the word we have to send to the
	// VGA board.
	uint16_t attribute = attributeByte << 8;
	uint16_t *location;

	// Handle a backspace, by moving the cursor back one space
	if (c == 0x08 && cursor_x)
	{
		cursor_x--;
	}

	// Handle a tab by increasing the cursor's X, but only to a point
	// where it is divisible by 8.
	else if (c == 0x09)
	{
		cursor_x = (cursor_x+8) & ~(8-1);
	}

	// Handle carriage return
	else if (c == '\r')
	{
		cursor_x = 0;
	}

	// Handle newline by moving cursor back to left and increasing the row
	else if (c == '\n')
	{
		cursor_x = 0;
		cursor_y++;
		//monitor_write("Os->");

	}
	// Handle any other printable character.
	else if(c >= ' ')
	{
		location = video_memory + (cursor_y*80 + cursor_x);
		*location = c | attribute;
		cursor_x++;
	}

	// Check if we need to insert a new line because we have reached the end
	// of the screen.
	if (cursor_x >= 80)
	{
		cursor_x = 0;
		cursor_y ++;
	}

	// Scroll the screen if needed.
	scroll();
	// Move the hardware cursor.
	move_cursor();
}

void monitor_clear()
{
	// Make an attribute byte for the default colours
	uint8_t attributeByte = (0 /*black*/ << 4) | (15 /*white*/ & 0x0F);
	uint16_t blank = 0x20 /* space */ | (attributeByte << 8);

	int i;
	for (i = 0; i < 80*25; i++)
	{
		video_memory[i] = blank;
	}

	// Move the hardware cursor back to the start.
	cursor_x = 0;
	cursor_y = 0;
	move_cursor();
	//monitor_write("Os->");

}


void goback()
{
	uint8_t backColour = 0;
	uint8_t foreColour = 15;

	uint16_t *location;
	uint8_t  attributeByte = (backColour << 4) | (foreColour & 0x0F);
	uint16_t attribute = attributeByte << 8;


	location = video_memory + (cursor_y*80 + cursor_x);
	*location = ' '  | attribute;


	location--;


	*location = ' '  | attribute;
	cursor_x--;


	move_cursor();




}

// Outputs a null-terminated ASCII string to the monitor.
void monitor_write(char *c)
{

	int i = 0;
	if(*c==8)
	{
		goback();
		return;
	}
	while (c[i])
	{
		monitor_put(c[i++]);
	}
}

void  present_cursor(){
	uint8_t backColour = 15;
	uint8_t foreColour = 15;

	uint16_t *location;
	uint8_t  attributeByte = (backColour << 4) | (foreColour & 0x0F);


	location = video_memory + (cursor_y*80 + cursor_x);
	uint16_t attribute = attributeByte << 8;

	*location = ' '  | attribute;


}


void process_buf()
{
	int i=0,c_flag=0,t_flag=0;
	char *clear="clear";
	char *touch="touch";
	char *ls="ls";

	for(i=0;i<z;i++)
	{
		if((clear[i]==line_buff[i])&&(i==(z-1))){
			//continue;
			monitor_clear();
			//monitor_write("Os->");
		
			clear_buff();
				z=0;

			return;

		}else if(clear[i]==line_buff[i]){
			continue;
		}else if((touch[i]==line_buff[i] )&&(i==(z-1))){
		

			file_create("shashank");
				clear_buff();

			z=0;
		
			return;
		}else if(touch[i]==line_buff[i]){
			continue;
		}else if(ls[i]==line_buff[i]&&(i==(z-1))){
				new_line();
				file_list();
				clear_buff();
				z=0;
				new_line();
				//monitor_write("Os->");
				return ;
			
		}
		else if(ls[i]==line_buff[i]){
			continue;
		}


		else{
			break;
			c_flag=1;

		}

	}



	

	if(i==z){
		
	}else
	{
			new_line();	
			monitor_write(":command not found");
				new_line();	



	}

	clear_buff();
	


	z=0;
}

void new_line(){
	cursor_x = 0;
			cursor_y ++;
			move_cursor();	

}

void clear_buff()
{
	int i;
	for(i=0;i<=z;i++){
		line_buff[i]=0;
	}


}


void monitor_write_hex(uint32_t n)
{
    int32_t tmp;

   // monitor_write("0x");

    char noZeroes = 1;

    int i;
    for (i = 28; i > 0; i -= 4)
    {
        tmp = (n >> i) & 0xF;
        if (tmp == 0 && noZeroes != 0)
        {
            continue;
        }
    
        if (tmp >= 0xA)
        {
            noZeroes = 0;
            monitor_put (tmp-0xA+'a' );
        }
        else
        {
            noZeroes = 0;
            monitor_put( tmp+'0' );
        }
    }
  
    tmp = n & 0xF;
    if (tmp >= 0xA)
    {
        monitor_put (tmp-0xA+'a');
    }
    else
    {
        monitor_put (tmp+'0');
    }

}

void monitor_write_dec(uint32_t n)
{

    if (n == 0)
    {
        monitor_put('0');
        return;
    }

    int32_t acc = n;
    char c[32];
    int i = 0;
    while (acc > 0)
    {
        c[i] = '0' + acc%10;
        acc /= 10;
        i++;
    }
    c[i] = 0;

    char c2[32];
    c2[i--] = 0;
    int j = 0;
    while(i >= 0)
    {
        c2[i--] = c[j++];
        
    }
    monitor_write(c2);

}
