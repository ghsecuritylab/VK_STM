#include "../Inc/keyboard.h"
#define SHIFT 0x80
#define KSIZE 128
uint8_t const keymap[KSIZE]={
    0x00,             // NUL
    0x00,             // SOH
    0x00,             // STX
    0x00,             // ETX
    0x00,             // EOT
    0x00,             // ENQ
    0x00,             // ACK
    0x00,             // BEL
    0x2a,			// BS	Backspace
    0x2b,			// TAB	Tab
    0x28,			// LF	Enter
    0x00,             // VT
    0x00,             // FF
    0x00,             // CR
    0x00,             // SO
    0x00,             // SI
    0x00,             // DEL
    0x00,             // DC1
    0x00,             // DC2
    0x00,             // DC3
    0x00,             // DC4
    0x00,             // NAK
    0x00,             // SYN
    0x00,             // ETB
    0x00,             // CAN
    0x00,             // EM
    0x00,             // SUB
    0x00,             // ESC
    0x00,             // FS
    0x00,             // GS
    0x00,             // RS
    0x00,             // US

    0x2c,		   //  ' '
    0x1e|SHIFT,	   // !
    0x34|SHIFT,	   // "
    0x20|SHIFT,    // #
    0x21|SHIFT,    // $
    0x22|SHIFT,    // %
    0x24|SHIFT,    // &
    0x34,          // '
    0x26|SHIFT,    // (
    0x27|SHIFT,    // )
    0x25|SHIFT,    // *
    0x2e|SHIFT,    // +
    0x36,          // ,
    0x2d,          // -
    0x37,          // .
    0x38,          // /
    0x27,          // 0
    0x1e,          // 1
    0x1f,          // 2
    0x20,          // 3
    0x21,          // 4
    0x22,          // 5
    0x23,          // 6
    0x24,          // 7
    0x25,          // 8
    0x26,          // 9
    0x33|SHIFT,      // :
    0x33,          // ;
    0x36|SHIFT,      // <
    0x2e,          // =
    0x37|SHIFT,      // >
    0x38|SHIFT,      // ?
    0x1f|SHIFT,      // @
    0x04|SHIFT,      // A
    0x05|SHIFT,      // B
    0x06|SHIFT,      // C
    0x07|SHIFT,      // D
    0x08|SHIFT,      // E
    0x09|SHIFT,      // F
    0x0a|SHIFT,      // G
    0x0b|SHIFT,      // H
    0x0c|SHIFT,      // I
    0x0d|SHIFT,      // J
    0x0e|SHIFT,      // K
    0x0f|SHIFT,      // L
    0x10|SHIFT,      // M
    0x11|SHIFT,      // N
    0x12|SHIFT,      // O
    0x13|SHIFT,      // P
    0x14|SHIFT,      // Q
    0x15|SHIFT,      // R
    0x16|SHIFT,      // S
    0x17|SHIFT,      // T
    0x18|SHIFT,      // U
    0x19|SHIFT,      // V
    0x1a|SHIFT,      // W
    0x1b|SHIFT,      // X
    0x1c|SHIFT,      // Y
    0x1d|SHIFT,      // Z
    0x2f,          // [
    0x31,          // bslash
    0x30,          // ]
    0x23|SHIFT,    // ^
    0x2d|SHIFT,    // _
    0x35,          // `
    0x04,          // a
    0x05,          // b
    0x06,          // c
    0x07,          // d
    0x08,          // e
    0x09,          // f
    0x0a,          // g
    0x0b,          // h
    0x0c,          // i
    0x0d,          // j
    0x0e,          // k
    0x0f,          // l
    0x10,          // m
    0x11,          // n
    0x12,          // o
    0x13,          // p
    0x14,          // q
    0x15,          // r
    0x16,          // s
    0x17,          // t
    0x18,          // u
    0x19,          // v
    0x1a,          // w
    0x1b,          // x
    0x1c,          // y
    0x1d,          // z
    0x2f|SHIFT,    // {
    0x31|SHIFT,    // |
    0x30|SHIFT,    // }
    0x35|SHIFT,    // ~
    0	// DEL
};

KeyReport keyReport;
inline void initKeyboard()
{
	keyReport.id=1;
}
inline size_t keyboardPress(uint8_t k)
{
	keyReport.id=1;
	if(isNonPrintable(k)) //non printable
	{
		k=k-136;
	}
	else if (isAModifier(k)) {	// modifier
		keyReport.modifiers |= (1<<(k-128));
		k = 0;
	}
	else {	// printable
		k = keymap[k];
		if (isPrintableReachedWithShift(k)) {// character reached with shift
			keyReport.modifiers |= 0x02;	// the left shift modifier
			k = stripModifiers(k); //limit to ascii(get rid of a modifier)
			}
	}
	keyboardSendReport(addToReport(k));
	return k;
}

inline void keyboardReleaseAll(void)
{
	keyReport.id =1;
	keyReport.modifiers=0;
	for(int i=0;i<NR_OF_KEYS;++i)
	{
		keyReport.keys[i]=0;
	}
	keyboardSendReport(&keyReport);
}
inline size_t keyboardRelease(uint8_t k){
	if(isNonPrintable(k))
	{
		k=k-136;
	}
	else if (isAModifier(k)) {	// modifier
		keyReport.modifiers &= ~(1<<(k-128));
		k = 0;
	}
	else {	// printable
		k = keymap[k];
		if(!k)
			return 0;
		if (isPrintableReachedWithShift(k)) {// character reached with shift
			keyReport.modifiers &= ~(0x02);	// the left shift modifier
			k = stripModifiers(k); //limit to ascii(get rid of a modifier)
			}
	}
	keyboardSendReport(subtractFromReport(k));
	return k;
}
inline size_t keyboardWrite(uint8_t k){
	keyReport.id=1;
	uint8_t result = keyboardPress(k);
	//HAL_Delay(30);//meadmeadmd
	keyboardRelease(k);
	//HAL_Delay(30);//there has to be delay between changes
	return result;
}
//private
inline uint8_t keyboardSendReport(KeyReport* keys){
	 HAL_Delay(30);
	 return USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t *)keys, sizeof(KeyReport));
}

KeyReport *addToReport(uint8_t k)
{
	//check if k is in already pressed
	for(int i =0; i<NR_OF_KEYS;++i){
		if(keyReport.keys[i]==k)
			return &keyReport;
	}
	//add to the first empty
	for(int i =0;i<NR_OF_KEYS;++i)
	{
		if(keyReport.keys[i]==0x00){
			keyReport.keys[i]=k;
			break;
		}
	}
	return &keyReport;
}
KeyReport* subtractFromReport(uint8_t k){
	for(int i =0; i<NR_OF_KEYS;++i){
		if(keyReport.keys[i]==k)
			keyReport.keys[i]=0x00;
	}
	return &keyReport;
}
inline uint8_t isAModifier(uint8_t k){
	return k>=128;
}
inline uint8_t isNonPrintable(uint8_t k){
	return k>=136;
}
inline uint8_t isPrintableReachedWithShift(uint8_t k){
	return (k & SHIFT);
}
inline uint8_t stripModifiers(uint8_t k)
{
	uint8_t p = k;
	p &= 0x7F;
	return p;
}

