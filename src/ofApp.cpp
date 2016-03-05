#include "ofApp.h"
#include "StartMenu.hpp"
#include "Level.hpp"
#include "GameOver.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    font = std::shared_ptr<ofTrueTypeFont>(new ofTrueTypeFont());
    font->load("verdana.ttf", 48);
    GameState::addGameState(new StartMenu(this, font));
    GameState::addGameState(new Level(this, 10, 5));
    GameState::addGameState(new Level(this, 20, 10));
    GameState::addGameState(new GameOver(this, font));
    //setGameState(0);
    
}

//void ofApp::setGameState(int i)
//{
//    if(i >= 0 && i < gameStates.size()){
//        currentGameState = i;
//        gameStates[currentGameState]->start();
//    }
//}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    GameState::getCurrentGameState()->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    GameState::getCurrentGameState()->keyPressed(key);
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
