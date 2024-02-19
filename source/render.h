/*
	Copyright 2016-2017 sub1to

	This file is part of 2Take1 2 GTA:O Hack.

    2Take1 2 GTA:O Hack is free software: you can redistribute
	it and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

    2Take1 2 GTA:O Hack is distributed in the hope that it
	will be useful, but WITHOUT ANY WARRANTY; without even the implied
	warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
	the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with 2Take1 2 GTA:O Hack.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#ifndef RENDER_H
#define RENDER_H

#define FONT_BUFFER_SIZE	0x10									//max amount of fonts

//Layout defines
#define LAYOUT_BORDER_SIZE		2
#define LAYOUT_ELEMENT_WIDTH	300
#define LAYOUT_ELEMENT_HEIGHT	25

#define LAYOUT_SCROLLBAR_WIDTH	0x08
#define LAYOUT_SCROLLBAR_HEIGHT	0x40

//#define LAYOUT_COLOR_BACKGROUND		D3DCOLOR_ARGB(0xff, 0x38, 0x78, 0xe2)
//#define LAYOUT_COLOR_BORDER			D3DCOLOR_ARGB(0xff, 1, 1, 1)
//#define LAYOUT_COLOR_TEXT			D3DCOLOR_ARGB(0xff, 1, 1, 1)
//#define LAYOUT_COLOR_SLIDER_BG		D3DCOLOR_ARGB(0xff, 0x28, 0x28, 0x28)
//#define LAYOUT_COLOR_SLIDER_BTN		D3DCOLOR_ARGB(0xff, 0x73, 0x73, 0x73)
//#define LAYOUT_COLOR_ACTIVE_BG		D3DCOLOR_ARGB(0xff, 0x85, 0xac, 0xed)
//#define LAYOUT_COLOR_ACTIVE_BORDER	D3DCOLOR_ARGB(0xff, 1, 1, 1)
//#define LAYOUT_COLOR_SELECTED		D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff)

#define LAYOUT_WIDTH	310
#define LAYOUT_HEIGHT	300

enum eDrawTextFlags
{
	TEXTFLAG_NONE		= 0,
	TEXTFLAG_CENTER		= 1 << 0,
	TEXTFLAG_NOSHADOW	= 1 << 1,
};

struct scrnVars
{
	int		w = LAYOUT_WIDTH,	//size
			h = LAYOUT_HEIGHT,
			x = 50,				//padding
			y = 50;
};

class CRender
{
	public:
		static scrnVars		m_screen;
		static std::string	m_szWindowTitle;

		static CColor LAYOUT_COLOR_BACKGROUND;
		static CColor LAYOUT_COLOR_BORDER;
		static CColor LAYOUT_COLOR_SLIDER_BG;
		static CColor LAYOUT_COLOR_SLIDER_BTN;
		static CColor LAYOUT_COLOR_ACTIVE_BG;
		static CColor LAYOUT_COLOR_SELECTED;

		static bool	initialze(HMODULE hModule, std::string szWindowTitle);

		static bool	render();

		static void	drawBox(int x, int y, int w, int h, CColor color);
		static void	drawBoxInline(int x, int y, int w, int h, int size, CColor color);
		static void	drawBoxBorder(int x, int y, int w, int h, int borderSize, CColor color, CColor borderColor);
		static void	drawText(char*, int x, int y, int w, int h, int font, float scale, CColor color, uint32_t flags = TEXTFLAG_NONE);

	protected:

	private:
		CRender	() {};		//don't allow construction
		~CRender() {};
};

#endif