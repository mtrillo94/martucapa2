#pragma once
#define port0 0
#define port1 1
#define port2 2
#define port3 3
#define port4 4
#define port5 5
#define port6 6
#define port7 7

#define LCD_E (1<<port0)
#define LCD_RS (1<<port1)
#define LCD_D4 (1<<port4)
#define LCD_D5 (1<<port5)
#define LCD_D6 (1<<port6)
#define LCD_D7 (1<<port7)

#define LCD_E_ON LCD_E
#define LCD_RS_ON LCD_RS
#define LCD_D4_ON LCD_D4
#define LCD_D5_ON LCD_D5
#define LCD_D6_ON LCD_D6
#define LCD_D7_ON LCD_D7

#define LCD_E_OFF (LCD_E^LCD_E)
#define LCD_RS_OFF (LCD_RS^LCD_RS)
#define LCD_D4_OFF (LCD_D4^LCD_D4)
#define LCD_D5_OFF (LCD_D5^LCD_D5)
#define LCD_D6_OFF (LCD_D6^LCD_D6)
#define LCD_D7_OFF (LCD_D7^LCD_D7)

#define FUNC_2LINE 0x28
#define FUNC_1LINE 0x20
#define CUR_SHIFT_R 0x14
#define CUR_SHIFT_L 0x10
#define DISP_SHIFT_R 0x1c
#define DISP_SHIFT_L 0x18
#define DISP_ON 0x0C
#define DISP_OFF 0x08
#define CURSOR_ON 0x0A
#define CURSOR_OFF 0X08
#define BLINKING_ON 0x09
#define BLINKING_OFF 0x08
#define DISPLAY_ALL_ON 0x0f
#define DISPLAY_ALL_OFF 0x00
#define ENTRY_MODE_SET_I 0x06
#define ENTRY_MODE_SET_D 0x04
#define RETURN_HOME 0x02
#define DISP_CLEAR 0x01

#define SET_ADDRESS(a,b) (0x80+(a)+(b)*0x40)

