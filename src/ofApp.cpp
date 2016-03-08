#include "ofApp.h"
#include "StartMenu.hpp"
#include "Level.hpp"
#include "GameOver.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    // load the font that is shared across menus
    font = std::shared_ptr<ofTrueTypeFont>(new ofTrueTypeFont());
    font->load("verdana.ttf", 48);
    
    // load levels
    GameState::addGameState(new StartMenu(font));
    GameState::addGameState(new Level(10, 5));
    GameState::addGameState(new Level(20, 10));
    GameState::addGameState(new GameOver(font));
    
    // this will be the start menu
    GameState::setGameState(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // the real stuff is done by the current game state
    GameState::getCurrentGameState()->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // the real stuff is done by the current game state
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
