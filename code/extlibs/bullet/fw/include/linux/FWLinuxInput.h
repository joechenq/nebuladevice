/* SCE CONFIDENTIAL
* $PSLibId$
* Copyright (C) 2006 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
//-----------------------------------------------------------------------------
//                             Sample Framework
//
// Linux Input
//
// $File: //nextgendev/Framework_080/include/linux/FWLinuxInput.h $
// $Author: asidwell $
// $Date: 2006/01/06 $
// $Revision: #1 $
//
// Copyright (C) 2006 Sony Computer Entertainment.
// All Rights Reserved.
//
//-----------------------------------------------------------------------------

#ifndef __FW_LINUXINPUT_H__
#define __FW_LINUXINPUT_H__

// platform specific mouse info
class FWLinuxMouseInfo
{
public:
	// last x position
	int		mLastX;
	// last y position
	int		mLastY;
	// whether initialized
	bool	mInit;
};

// mapping to X keyboard values
static unsigned char sKeyboardMap[256] =
{
	XK_A,			//Channel_Key_A,
	XK_B,			//Channel_Key_B,
	XK_C,			//Channel_Key_C,
	XK_D,			//Channel_Key_D,
	XK_E,			//Channel_Key_E,
	XK_F,			//Channel_Key_F,
	XK_G,			//Channel_Key_G,
	XK_H,			//Channel_Key_H,
	XK_I,			//Channel_Key_I,
	XK_J,			//Channel_Key_J,
	XK_K,			//Channel_Key_K,
	XK_L,			//Channel_Key_L,
	XK_M,			//Channel_Key_M,
	XK_N,			//Channel_Key_N,
	XK_O,			//Channel_Key_O,
	XK_P,			//Channel_Key_P,
	XK_Q,			//Channel_Key_Q,
	XK_R,			//Channel_Key_R,
	XK_S,			//Channel_Key_S,
	XK_T,			//Channel_Key_T,
	XK_U,			//Channel_Key_U,
	XK_V,			//Channel_Key_V,
	XK_W,			//Channel_Key_W,
	XK_X,			//Channel_Key_X,
	XK_Y,			//Channel_Key_Y,
	XK_Z,			//Channel_Key_Z,
	XK_1,			//Channel_Key_1,
	XK_2,			//Channel_Key_2,
	XK_3,			//Channel_Key_3,
	XK_4,			//Channel_Key_4,
	XK_5,			//Channel_Key_5,
	XK_6,			//Channel_Key_6,
	XK_7,			//Channel_Key_7,
	XK_8,			//Channel_Key_8,
	XK_9,			//Channel_Key_9,
	XK_0,			//Channel_Key_0,
	XK_Escape,		//Channel_Key_Escape,
	XK_F1,			//Channel_Key_F1,
	XK_F2,			//Channel_Key_F2,
	XK_F3,			//Channel_Key_F3,
	XK_F4,			//Channel_Key_F4,
	XK_F5,			//Channel_Key_F5,
	XK_F6,			//Channel_Key_F6,
	XK_F7,			//Channel_Key_F7,
	XK_F8,			//Channel_Key_F8,
	XK_F9,			//Channel_Key_F9,
	XK_F10,			//Channel_Key_F10,
	XK_F11,			//Channel_Key_F11,
	XK_F12,			//Channel_Key_F12,
	XK_Return,		//Channel_Key_Enter,
	XK_BackSpace,	//Channel_Key_Backspace,
	XK_Tab,			//Channel_Key_Tab,
	XK_space,		//Channel_Key_Space,
	XK_minus,		//Channel_Key_Minus,
	XK_equal,		//Channel_Key_Equals,
	XK_bracketleft,	//Channel_Key_LeftBracket,
	XK_bracketright,//Channel_Key_RightBracket,
	XK_backslash,	//Channel_Key_Backslash,
	XK_semicolon,	//Channel_Key_Semicolon
	XK_apostrophe,	//Channel_Key_Apostrophe
	XK_comma,		//Channel_Key_Comma,
	XK_period,		//Channel_Key_Period,
	XK_slash,		//Channel_Key_Slash,
	XK_Left,		//Channel_Key_Left,
	XK_Right,		//Channel_Key_Right,
	XK_Up,			//Channel_Key_Up,
	XK_Down,		//Channel_Key_Down,
	XK_Home,		//Channel_Key_Home,
	XK_End,			//Channel_Key_End,
	XK_Page_Up,		//Channel_Key_PageUp,
	XK_Page_Down,	//Channel_Key_PageDown,
	XK_Insert,		//Channel_Key_Insert,
	XK_Delete,		//Channel_Key_Delete,
	XK_KP_1,		//Channel_Key_Numpad_1,
	XK_KP_2,		//Channel_Key_Numpad_2,
	XK_KP_3,		//Channel_Key_Numpad_3,
	XK_KP_4,		//Channel_Key_Numpad_4,
	XK_KP_5,		//Channel_Key_Numpad_5,
	XK_KP_6,		//Channel_Key_Numpad_6,
	XK_KP_7,		//Channel_Key_Numpad_7,
	XK_KP_8,		//Channel_Key_Numpad_8,
	XK_KP_9,		//Channel_Key_Numpad_9,
	XK_KP_0,		//Channel_Key_Numpad_0,
	XK_KP_Divide,	//Channel_Key_Numpad_Slash,
	XK_KP_Multiply,	//Channel_Key_Numpad_Asterisk,
	XK_KP_Subtract,	//Channel_Key_Numpad_Minus,
	XK_KP_Add,		//Channel_Key_Numpad_Plus,
	XK_KP_Enter,	//Channel_Key_Numpad_Enter,
	XK_KP_Decimal,	//Channel_Key_Numpad_Period,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};

#endif//__FW_LINUXINPUT_H__

// Local variables:
// indent-tabs-mode: t
// tab-width: 4
// End:
// vim:ts=4:sw=4
