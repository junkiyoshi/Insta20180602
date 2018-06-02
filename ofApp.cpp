#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	for (int x = -1; x <= 1; x++) {

		for (int y = -1; y <= 1; y++) {

			ofPushMatrix();
			ofTranslate(x * 200, y * 200);

			float noise_x_param = ofRandom(1000) + ofGetFrameNum() * 0.01;
			float noise_y_param = ofRandom(1000) + ofGetFrameNum() * 0.01;
			for (int i = 0; i < 100; i++) {

				ofColor circle_color;
				circle_color.setHsb(ofRandom(255), 239, 239);
				ofSetColor(circle_color, 64);

				ofPoint point = ofPoint(ofMap(ofNoise(noise_x_param + i * 0.02), 0, 1, -150, 150), ofMap(ofNoise(noise_y_param + i * 0.02), 0, 1, -150, 150));
				ofDrawCircle(point, 10);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}