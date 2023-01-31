#include "types.h"

//void print(char *str);
//uint8_t getvale(uint8_t h);
void print32hex(uint32_t hex);

static void move_cursor();

static void scroll();
void monitor_put(char c);
void monitor_clear();
void monitor_write(char *c);
void  present_cursor();
void process_buf();
void new_line();
void clear_buff();
void monitor_write_hex(uint32_t n);

void monitor_write_dec(uint32_t n);



