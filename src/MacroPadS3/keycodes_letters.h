// --- keycodes_letters.h ---
#ifndef KEYCODES_LETTERS_H
#define KEYCODES_LETTERS_H

// Letras A–Z según el estándar HID
#define KEY_A (0x04 + 136)
#define KEY_B (0x05 + 136)
#define KEY_C (0x06 + 136)
#define KEY_D (0x07 + 136)
#define KEY_E (0x08 + 136)
#define KEY_F (0x09 + 136)
#define KEY_G (0x0A + 136)
#define KEY_H (0x0B + 136)
#define KEY_I (0x0C + 136)
#define KEY_J (0x0D + 136)
#define KEY_K (0x0E + 136)
#define KEY_L (0x0F + 136)
#define KEY_M (0x10 + 136)
#define KEY_N (0x11 + 136)
#define KEY_O (0x12 + 136)
#define KEY_P (0x13 + 136)
#define KEY_Q (0x14 + 136)
#define KEY_R (0x15 + 136)
#define KEY_S (0x16 + 136)
#define KEY_T (0x17 + 136)
#define KEY_U (0x18 + 136)
#define KEY_V (0x19 + 136)
#define KEY_W (0x1A + 136)
#define KEY_X (0x1B + 136)
#define KEY_Y (0x1C + 136)
#define KEY_Z (0x1D + 136)

// Números 1–9 y 0 (parte superior del teclado)
#define KEY_1 (0x1E + 136)
#define KEY_2 (0x1F + 136)
#define KEY_3 (0x20 + 136)
#define KEY_4 (0x21 + 136)
#define KEY_5 (0x22 + 136)
#define KEY_6 (0x23 + 136)
#define KEY_7 (0x24 + 136)
#define KEY_8 (0x25 + 136)
#define KEY_9 (0x26 + 136)
#define KEY_0 (0x27 + 136)

// Símbolos comunes (requieren Shift para algunos)
#define KEY_ENTER     (0x28 + 136)
#define KEY_ESC       (0x29 + 136)
#define KEY_BACKSPACE (0x2A + 136)
#define KEY_TAB       (0x2B + 136)
#define KEY_SPACE     (0x2C + 136)
#define KEY_MINUS     (0x2D + 136)  // - _
#define KEY_EQUAL     (0x2E + 136)  // = +
#define KEY_LEFT_BRACE  (0x2F + 136)  // [ {
#define KEY_RIGHT_BRACE (0x30 + 136)  // ] }
#define KEY_BACKSLASH   (0x31 + 136)  // \ |
#define KEY_SEMICOLON   (0x33 + 136)  // ; :
#define KEY_APOSTROPHE  (0x34 + 136)  // ' "
#define KEY_GRAVE       (0x35 + 136)  // ` ~
#define KEY_COMMA       (0x36 + 136)  // , <
#define KEY_PERIOD      (0x37 + 136)  // . >
#define KEY_SLASH       (0x38 + 136)  // / ?

// Símbolos extendidos (requieren Shift)
#define KEY_EXCLAMATION_MARK ((char)(0x1E + 136)) // Shift + 1
#define KEY_AT_SYMBOL        ((char)(0x1F + 136)) // Shift + 2
#define KEY_HASH             ((char)(0x20 + 136)) // Shift + 3
#define KEY_DOLLAR           ((char)(0x21 + 136)) // Shift + 4
#define KEY_PERCENT          ((char)(0x22 + 136)) // Shift + 5
#define KEY_CARET            ((char)(0x23 + 136)) // Shift + 6
#define KEY_AMPERSAND        ((char)(0x24 + 136)) // Shift + 7
#define KEY_ASTERISK         ((char)(0x25 + 136)) // Shift + 8
#define KEY_LEFT_PAREN       ((char)(0x26 + 136)) // Shift + 9
#define KEY_RIGHT_PAREN      ((char)(0x27 + 136)) // Shift + 0

#endif // KEYCODES_LETTERS_H
