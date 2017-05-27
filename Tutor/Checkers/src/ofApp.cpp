#include "ofApp.h"


using namespace std;


//--------------------------------------------------------------
void ofApp::setup(){

    //	InterfaceControl t; // For testing purposes
    //	BoardModel bm(15,3);
    ofEnableAntiAliasing();
    p1 = new PlayerModel(1);
    p2 = new PlayerModel(2);
    
    autosave = new Autosave(8,8);
    gm = new GameModel(p1,p2,8,8, autosave);
    gm->initPieces();
    pieceSelected = false;
    
    
    //GameModel* gm = Autosave::load("Save.txt");
    //InterfaceControl ui(gm);
    
    //	ui.gm.board.PrintBoard();
    //	cout << endl << gm.board.CellValid(t.RequestCoord());
 //   ui.GameLoop();
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //Checks Winner
    if(winner != none)
    {
        if (winner == p1win)
            ofBackground(255, 255, 255);
        else
            ofBackground(91, 198, 77);
    }
    
    //Draws Board
    bool colour = false;
    boardX = ofGetWidth()/4;
    boardY = ofGetHeight()/4;
    ofTranslate( boardX, boardY);
    ofPushMatrix();
    squareLength = ofGetWidth() / 2 / gm->board.numRows;
    for( int row = 0; row < gm->board.numRows; row++)
    {
        ofPushMatrix();
        for (int col = 0; col < gm->board.numCols; col++)
        {
            if (colour)
                ofSetColor(206, 70, 24);
            else
                ofSetColor(40, 11, 2);
            ofDrawRectangle(0, 0, squareLength, squareLength);
            ofTranslate(squareLength, 0);
            colour = !colour;
        }
        ofPopMatrix();
        
        ofTranslate(0, squareLength);
        if ( gm->board.numCols % 2 == 0)
            colour = !colour;
        
    }
    ofPopMatrix();
    
    //Draws Pieces
    ofPushMatrix();
    for (int row = 0;  row < gm->board.numRows; row++)
    {
        ofPushMatrix();
        for (int col = 0; col < gm->board.numCols ; col++)
        {
            PieceModel *p = gm->getPiece(col, row);
            if(p != nullptr)
            {
               if (p->player->number == 1)
                    ofSetColor(255, 255, 255);
               else
                    ofSetColor(0, 0, 255);
                ofDrawCircle(squareLength/2, squareLength/2,squareLength * 0.4);
                if( typeid(*p) == typeid(KingPieceModel))
                {
                    ofSetColor(244, 200, 66);
                    ofDrawCircle(squareLength/2, squareLength/2,squareLength * 0.3);
                    
                }
            }


            ofTranslate(squareLength, 0);
        }
        ofPopMatrix();
        ofTranslate(0, squareLength);
    }
    ofPopMatrix();
    
    //Highlights hover on square
    ofPushStyle();
    int col = mouseXtoCol();
    int row = mouseYtoRow();
    if(inBoardRange(col, row))
    {
        ofNoFill();
        ofSetLineWidth(10);
        ofSetColor(255, 89, 205);
        ofDrawRectRounded((col * squareLength),(row * squareLength), squareLength, squareLength, 10);
    }
    ofPopStyle();
    
    //Highlights square if piece selected
    if(pieceSelected)
    {
        ofPushStyle();
        ofNoFill();
        ofSetLineWidth(10);
        ofSetColor(91, 198, 77);
        ofDrawRectRounded(selectedCo.x * squareLength,selectedCo.y * squareLength, squareLength, squareLength, 10);
        ofPopStyle();
        
    }
    
    //Displays active player
    string s = "Player ";
    s += to_string(gm->GetActivePlayer());
    s += " turn.";
    ofDrawBitmapString(s, 0, -10);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    int col = mouseXtoCol(x);
    int row = mouseYtoRow(y);

    Coord co;
    co.x = col;
    co.y = row;
    if(inBoardRange(col, row))
    {
        if(!pieceSelected)
        {
            if(gm->CoordContainsPlayerPiece(co, gm->GetActivePlayer()))
            {
                selectedCo = co;
                pieceSelected = true;
//               ofLog() << "Co:" << selectedCo.x << " " << selectedCo.y << " " << pieceSelected;
            }
        }
        else
        {
            if(gm->isMoveValid(selectedCo, co))
            {
                gm->doMove(selectedCo, co);
                winner = gm->getWinner();
            }
                
            pieceSelected = false;
            
            
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

int ofApp::mouseXtoCol()
{
    return ((int)floor((mouseX - boardX)/squareLength));
}
int ofApp::mouseXtoCol(int x)
{
    return ((int)floor((x - boardX)/squareLength));
}

int ofApp::mouseYtoRow()
{
    return ((int)floor((mouseY - boardY)/squareLength));
}
int ofApp::mouseYtoRow(int y)
{
    return ((int)floor((y - boardY)/squareLength));
}

bool ofApp::inBoardRange(int col, int row)
{
    return((col >= 0 && row >= 0)
           && (col < gm->board.numCols && row < gm->board.numRows));
}
