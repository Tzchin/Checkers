#pragma once

#include "ofMain.h"
#include <iostream>
#include <stddef.h>
#include "GameModel.h"
#include "InterfaceControl.h"
#include "Autosave.h"
#include "BoardModel.h"
#include "PlayerModel.h"
#include "KingPieceModel.h"
#include <typeinfo>
#include <math.h>

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
private:
    GameModel* gm;
    PlayerModel* p1;
    PlayerModel* p2;
    Autosave* autosave;
    float squareLength;
    float boardX;
    float boardY;
    int mouseXtoCol();
    int mouseXtoCol(int x);
    int mouseYtoRow();
    int mouseYtoRow(int y);
    bool inBoardRange(int col, int row);
    bool pieceSelected;
    Coord selectedCo;
    WinState winner;
};
