#pragma once

#include "../stdafx.h"

#include "SDL_ttf.h"
#include "draw.h"
#include "game.h"
#include <string>

enum {TEXTBOX_NO_FOCUS = 0,
      TEXTBOX_FOCUS
      };

enum {TEXTBOX_TYPE_NUM = 0,
      TEXTBOX_TYPE_MOVE
      };

class TextBox {
  private:
    Game * game;
    SDL_Color textColor;
    TTF_Font * font;
    SDL_Surface * textRender;
    SDL_Surface * destination;
    int ticksStart;
    Point point;
    bool changed;           // holds whether we should re render the string or not
    int state;              // Holds whether it has focus or not
    int type;               // Holds what type of box it is (So that we know where to send the string on enter)
    int cursor;             // Where in the flash animation the cursor is
    std::string textString;            // The text String
  public:
    TextBox(TTF_Font * theFont, SDL_Color color, int type, Point placement, Game * theGame);
    ~TextBox();
    bool draw(SDL_Surface * destination);//draws the textbox
    bool processKeyDown(SDL_Event * event);//processes keyboard input
    bool setState(int state);
    int  getState(void);
    bool isMouseover(int x, int y);//determines the space where mouse input can be accepted
};


