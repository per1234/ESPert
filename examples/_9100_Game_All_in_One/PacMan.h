// Pac-Man Simulator for ESPresso Lite

#ifndef _GAME_PAC_MAN_H_
#define _GAME_PAC_MAN_H_

#include "Game.h"

namespace pacMan {
static const byte numberOfPacManFrames = 4;
static const byte numberOfDieFrames = 14;
static const byte numberOfDirections = 4;
static const byte numberOfTiles = 24;
static const byte numberOfItems = 8;
static const byte numberOfGhosts = 4;
static const byte numberOfGhostFrames = 2;

const uint8_t characterBitmap[numberOfGhosts][(40 * 8) / 8] PROGMEM = {
  {0xC0, 0x25, 0x73, 0x9C, 0x08, 0x20, 0xA4, 0x94, 0xA2, 0x08, 0xC7, 0xBC, 0x97, 0xA2, 0x0A, 0x00, 0xA5, 0x94, 0xA2, 0x0D, 0xE0, 0xA4, 0x74, 0x9C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // shadow.png
  {0xC0, 0x9D, 0xF7, 0x4E, 0x04, 0x20, 0xA4, 0x10, 0x52, 0x04, 0xC7, 0x9C, 0x73, 0x92, 0x03, 0x00, 0x85, 0x10, 0x12, 0x01, 0xE0, 0x84, 0xF7, 0x0E, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // speedy.png
  {0xE0, 0x18, 0x97, 0x5E, 0x14, 0x20, 0xA5, 0x90, 0x42, 0x14, 0xE7, 0x3C, 0xF3, 0x4E, 0x14, 0x20, 0x25, 0x94, 0x42, 0x14, 0xE0, 0xA4, 0x93, 0x82, 0xF3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // bashful.png
  {0xE0, 0x38, 0xE9, 0x45, 0x00, 0x20, 0x45, 0x2D, 0x44, 0x00, 0xE7, 0x44, 0xE7, 0x38, 0x00, 0x20, 0x44, 0x2D, 0x10, 0x00, 0x20, 0x38, 0xE9, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // pokey.png
};

const uint8_t nicknameBitmap[numberOfGhosts][(40 * 8) / 8] PROGMEM = {
  {0x75, 0xC2, 0xA5, 0x14, 0x05, 0x95, 0x82, 0xAC, 0x16, 0x05, 0x70, 0x82, 0xBC, 0xE3, 0x00, 0x90, 0x82, 0xB4, 0x46, 0x00, 0x70, 0xDE, 0xA5, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // blinky.png
  {0x75, 0x2E, 0xA5, 0xA8, 0x00, 0x95, 0x64, 0xB5, 0xA8, 0x00, 0x70, 0xE4, 0x1D, 0x07, 0x00, 0x10, 0xA4, 0x35, 0x02, 0x00, 0x10, 0x2E, 0x25, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pinky.png
  {0x75, 0x29, 0x45, 0x05, 0x00, 0x25, 0xAB, 0x45, 0x05, 0x00, 0x20, 0xEF, 0x38, 0x00, 0x00, 0x20, 0xAD, 0x11, 0x00, 0x00, 0x70, 0x29, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // inky.png
  {0xE5, 0x84, 0xE8, 0xBC, 0x02, 0x15, 0x85, 0x28, 0x85, 0x02, 0x10, 0x04, 0x27, 0x1D, 0x00, 0x10, 0x05, 0x22, 0x05, 0x00, 0xE0, 0x3C, 0xE2, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // clyde.png
};

const uint8_t characterNicknameBitmap[(104 * 8) / 8] PROGMEM = { // characterNickname.png
  0x4E, 0x32, 0xC7, 0x38, 0xF7, 0x0E, 0x00, 0x81, 0x74, 0x4E, 0x4A, 0x26,
  0x7A, 0x51, 0x4A, 0x29, 0x45, 0x12, 0x12, 0x80, 0x80, 0x25, 0x51, 0x5B,
  0x69, 0x0B, 0xC1, 0x7B, 0xE7, 0x05, 0x72, 0x0E, 0x40, 0x80, 0x27, 0xC1,
  0x79, 0xAF, 0x3A, 0x51, 0x4A, 0x25, 0x45, 0x12, 0x0A, 0x20, 0x80, 0x26,
  0x51, 0x6B, 0x29, 0x0A, 0x4E, 0x4A, 0x29, 0x39, 0xF2, 0x12, 0x10, 0x80,
  0x74, 0x4E, 0x4A, 0x29, 0x7A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t dieBitmap[numberOfDieFrames][(16 * 16) / 8] PROGMEM = {
  {0x7C, 0x00, 0xFE, 0x00, 0xFF, 0x01, 0xFF, 0x01, 0xFF, 0x01, 0xFF, 0x01, 0xFF, 0x01, 0xFE, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die00.png
  {0x00, 0x00, 0x00, 0x00, 0xC7, 0x01, 0xEF, 0x01, 0xFF, 0x01, 0xFE, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die01.png
  {0x00, 0x00, 0x00, 0x00, 0x83, 0x01, 0xEF, 0x01, 0xFF, 0x01, 0xFF, 0x01, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die02.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x01, 0xFF, 0x01, 0xFF, 0x01, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die03.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0xFF, 0x01, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die04.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0xFF, 0x01, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die05.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0xFE, 0x00, 0xFF, 0x01, 0xEE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die06.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x38, 0x00, 0x7C, 0x00, 0xFE, 0x00, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die07.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x38, 0x00, 0x7C, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die08.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x38, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die09.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die10.png
  {0x44, 0x00, 0x28, 0x00, 0x01, 0x01, 0x82, 0x00, 0x00, 0x00, 0x82, 0x00, 0x01, 0x01, 0x28, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die11.png
  {0x44, 0x00, 0x28, 0x00, 0x01, 0x01, 0x82, 0x00, 0x00, 0x00, 0x82, 0x00, 0x01, 0x01, 0x28, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // die11.png
  {0x44, 0x00, 0x28, 0x00, 0x01, 0x01, 0x82, 0x00, 0x00, 0x00, 0x82, 0x00, 0x01, 0x01, 0x28, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // die11.png
};

const uint8_t gameOverBitmap[(64 * 8) / 8] PROGMEM = { // gameOver.png
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x9C, 0xB1, 0x0F,
  0x9E, 0xD9, 0xF7, 0x01, 0x0C, 0xB6, 0xBB, 0x01, 0xB3, 0xD9, 0x30, 0x03,
  0x06, 0xB3, 0xBF, 0x0F, 0xB3, 0xD9, 0x37, 0x03, 0x66, 0xBF, 0xB5, 0x01,
  0xB3, 0xD9, 0xF0, 0x00, 0x6C, 0xB3, 0xB1, 0x01, 0xB3, 0xCD, 0xB0, 0x01,
  0x78, 0xB3, 0xB1, 0x0F, 0x1E, 0xC7, 0xB7, 0x03, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

const uint8_t gameOverMaskBitmap[(64 * 8) / 8] PROGMEM = { // gameOverMask.png
  0xFC, 0xFF, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0x07, 0xFE, 0xFF, 0xFF, 0x9F,
  0xFF, 0xFF, 0xFF, 0x07, 0xFF, 0xFF, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0x07,
  0xFF, 0xFF, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0x07, 0xFF, 0xFF, 0xFF, 0x9F,
  0xFF, 0xFF, 0xFF, 0x07, 0xFF, 0xFF, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0x07,
  0xFE, 0xFF, 0xFF, 0x9F, 0xFF, 0xFF, 0xFF, 0x07, 0xFC, 0xFF, 0xFF, 0x9F,
  0xFF, 0xFF, 0xFF, 0x07
};

const uint8_t ghostBitmap[numberOfGhostFrames][(16 * 16) / 8] PROGMEM = {
  {0x00, 0x00, 0x70, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xDA, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ghost0.png
  {0x00, 0x00, 0x70, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0x76, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // ghost1.png
};

const uint8_t ghostMaskBitmap[numberOfGhostFrames][(16 * 16) / 8] PROGMEM = {
  {0x70, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xDA, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ghostMask0.png
  {0x70, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0x76, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // ghostMask1.png
};

const uint8_t ghostEdibleBitmap[numberOfGhostFrames][(16 * 16) / 8] PROGMEM = {
  {0x70, 0x00, 0x8C, 0x01, 0x02, 0x02, 0xD9, 0x04, 0xD9, 0x04, 0x01, 0x04, 0x51, 0x04, 0xA9, 0x04, 0x01, 0x04, 0x25, 0x05, 0xDA, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ghostEdible0.png
  {0x70, 0x00, 0x8C, 0x01, 0x02, 0x02, 0xD9, 0x04, 0xD9, 0x04, 0x01, 0x04, 0x51, 0x04, 0xA9, 0x04, 0x01, 0x04, 0x89, 0x04, 0x76, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // ghostEdible1.png
};

const uint8_t ghostEyeBitmap[numberOfDirections][(16 * 16) / 8] PROGMEM = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x00, 0xCC, 0x00, 0xEE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ghostEyeLeft.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x03, 0x98, 0x01, 0xB8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ghostEyeRight.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x54, 0x01, 0xDC, 0x01, 0xDC, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ghostEyeUp.png
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDC, 0x01, 0xDC, 0x01, 0x54, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // ghostEyeDown.png
};

const uint8_t ghostEyeMaskBitmap[numberOfDirections][(16 * 16) / 8] PROGMEM = {
  {0x00, 0x00, 0x00, 0x00, 0xEE, 0x00, 0xFF, 0x01, 0xFF, 0x01, 0xFF, 0x01, 0xEE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ghostEyeLeftMask.png
  {0x00, 0x00, 0x00, 0x00, 0xB8, 0x03, 0xFC, 0x07, 0xFC, 0x07, 0xFC, 0x07, 0xB8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ghostEyeRightMask.png
  {0x00, 0x00, 0x00, 0x00, 0xDC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xDC, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ghostEyeUpMask.png
  {0x00, 0x00, 0x00, 0x00, 0xDC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xDC, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // ghostEyeDownMask.png
};

const uint8_t highScoreBitmap[(32 * 8) / 8] PROGMEM = { // highScore.png
  0x00, 0x00, 0x00, 0x00, 0x2A, 0xEE, 0xEE, 0x0E, 0x2A, 0x22, 0xAA, 0x02, 0xAE, 0x2E, 0x6A, 0x0E, 0x2A, 0x28, 0xAA, 0x02, 0x2A, 0xEE, 0xAE, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t highScoreMaskBitmap[(32 * 8) / 8] PROGMEM = { // highScoreMask.png
  0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00
};

const uint8_t itemBitmap[numberOfItems][(16 * 16) / 8] PROGMEM = {
  {0x00, 0x00, 0x00, 0x03, 0xE0, 0x03, 0x90, 0x00, 0x8C, 0x00, 0x9E, 0x00, 0xDA, 0x00, 0xEC, 0x01, 0xA0, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemCherry.png
  {0x00, 0x00, 0x20, 0x00, 0xF8, 0x00, 0x24, 0x01, 0xDE, 0x03, 0xF6, 0x02, 0xBC, 0x01, 0xF4, 0x01, 0xD8, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemStrawberry.png
  {0x00, 0x00, 0xC0, 0x01, 0xE0, 0x00, 0x58, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemOrange.png
  {0x00, 0x00, 0x5C, 0x00, 0x70, 0x00, 0xAC, 0x01, 0xD6, 0x03, 0xFA, 0x03, 0xFA, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemApple.png
  {0x00, 0x00, 0xF8, 0x00, 0x40, 0x00, 0xF8, 0x01, 0x64, 0x02, 0x7C, 0x02, 0xEC, 0x03, 0x24, 0x03, 0x38, 0x01, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemMelon.png
  {0x00, 0x00, 0x22, 0x02, 0x72, 0x02, 0xFA, 0x02, 0x56, 0x03, 0x8C, 0x01, 0xD8, 0x00, 0xA8, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemGalaxian.png
  {0x00, 0x00, 0x20, 0x00, 0x70, 0x00, 0xD8, 0x00, 0xEC, 0x01, 0xEC, 0x01, 0xF6, 0x03, 0xFE, 0x03, 0x02, 0x02, 0xFC, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemBell.png
  {0x00, 0x00, 0xF0, 0x00, 0xD8, 0x01, 0xF8, 0x01, 0xF0, 0x00, 0x60, 0x00, 0xE0, 0x00, 0x60, 0x00, 0xE0, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // itemKey.png
};

const uint8_t itemMaskBitmap[numberOfItems][(16 * 16) / 8] PROGMEM = {
  {0x00, 0x03, 0xE0, 0x07, 0xF0, 0x07, 0xFC, 0x03, 0xFE, 0x01, 0xFF, 0x01, 0xFF, 0x01, 0xFE, 0x03, 0xFC, 0x03, 0xE0, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemCherryMask.png
  {0x20, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemStrawberryMask.png
  {0xC0, 0x01, 0xE0, 0x03, 0xF8, 0x01, 0xFC, 0x03, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemOrangeMask.png
  {0x5C, 0x00, 0xFE, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemAppleMask.png
  {0xF8, 0x00, 0xFC, 0x01, 0xF8, 0x01, 0xFC, 0x03, 0xFE, 0x07, 0xFE, 0x07, 0xFE, 0x07, 0xFE, 0x07, 0xFC, 0x03, 0xF8, 0x01, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemMelonMask.png
  {0x22, 0x02, 0x77, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xFC, 0x01, 0xF8, 0x00, 0x70, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemGalaxianMask.png
  {0x20, 0x00, 0x70, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // itemBellMask.png
  {0xF0, 0x00, 0xF8, 0x01, 0xFC, 0x03, 0xFC, 0x03, 0xF8, 0x01, 0xF0, 0x00, 0xF0, 0x01, 0xF0, 0x00, 0xF0, 0x01, 0xE0, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // itemKeyMask.png
};

const uint8_t lifeBitmap[(8 * 8) / 8] PROGMEM = { // life.png
  0x00, 0x1C, 0x3E, 0x38, 0x3E, 0x1C, 0x00, 0x00
};

const uint8_t lifeMaskBitmap[(8 * 8) / 8] PROGMEM = { // lifeMask.png
  0x3E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x3E, 0x00
};

const uint8_t numberBitmap[10][(8 * 8) / 8] PROGMEM = {
  {0x00, 0x0E, 0x0A, 0x0A, 0x0A, 0x0E, 0x00, 0x00}, // number0.png
  {0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00}, // number1.png
  {0x00, 0x0E, 0x08, 0x0E, 0x02, 0x0E, 0x00, 0x00}, // number2.png
  {0x00, 0x0E, 0x08, 0x0E, 0x08, 0x0E, 0x00, 0x00}, // number3.png
  {0x00, 0x0A, 0x0A, 0x0E, 0x08, 0x08, 0x00, 0x00}, // number4.png
  {0x00, 0x0E, 0x02, 0x0E, 0x08, 0x0E, 0x00, 0x00}, // number5.png
  {0x00, 0x0E, 0x02, 0x0E, 0x0A, 0x0E, 0x00, 0x00}, // number6.png
  {0x00, 0x0E, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00}, // number7.png
  {0x00, 0x0E, 0x0A, 0x0E, 0x0A, 0x0E, 0x00, 0x00}, // number8.png
  {0x00, 0x0E, 0x0A, 0x0E, 0x08, 0x0E, 0x00, 0x00}  // number9.png
};

const uint8_t numberMaskBitmap[10][(8 * 8) / 8] PROGMEM = { // numberMask.png
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
  {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00}
};

const uint8_t pacManBitmap[numberOfDirections][numberOfPacManFrames][(16 * 16) / 8] PROGMEM = {
  {
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xF0, 0x03, 0xC0, 0x03, 0xF0, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManLeft0.png
    {0x00, 0x00, 0xF8, 0x00, 0xF8, 0x01, 0xF0, 0x03, 0xE0, 0x03, 0xC0, 0x03, 0xE0, 0x03, 0xF0, 0x03, 0xF8, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManLeft1.png
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xF0, 0x03, 0xC0, 0x03, 0xF0, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManLeft2.png
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // pacManLeft3.png
  },
  {
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0x7E, 0x00, 0x1E, 0x00, 0x7E, 0x00, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManRight0.png
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x00, 0x7E, 0x00, 0x3E, 0x00, 0x1E, 0x00, 0x3E, 0x00, 0x7E, 0x00, 0xFC, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManRight1.png
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0x7E, 0x00, 0x1E, 0x00, 0x7E, 0x00, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManRight2.png
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // pacManRight3.png
  },
  {
    {0x00, 0x00, 0x88, 0x00, 0x8C, 0x01, 0x8E, 0x03, 0xDE, 0x03, 0xDE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManUp0.png
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x8E, 0x03, 0xDE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManUp1.png
    {0x00, 0x00, 0x88, 0x00, 0x8C, 0x01, 0x8E, 0x03, 0xDE, 0x03, 0xDE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManUp2.png
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // pacManUp3.png
  },
  {
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xDE, 0x03, 0xDE, 0x03, 0x8E, 0x03, 0x8C, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManDown0.png
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xDE, 0x03, 0x8E, 0x03, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManDown1.png
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xDE, 0x03, 0xDE, 0x03, 0x8E, 0x03, 0x8C, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManDown2.png
    {0x00, 0x00, 0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // pacManDown3.png
  }
};

const uint8_t pacManMaskBitmap[numberOfDirections][numberOfPacManFrames][(16 * 16) / 8] PROGMEM = {
  {
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFE, 0x07, 0xF0, 0x07, 0xFE, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManLeftMask0.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFC, 0x03, 0xF8, 0x07, 0xF0, 0x07, 0xE0, 0x07, 0xF0, 0x07, 0xF8, 0x07, 0xFC, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManLeftMask1.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFE, 0x07, 0xF0, 0x07, 0xFE, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManLeftMask2.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // pacManLeftMask3.png
  },
  {
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x03, 0x7F, 0x00, 0xFF, 0x03, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManRightMask0.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x01, 0xFF, 0x00, 0x7F, 0x00, 0x3F, 0x00, 0x7F, 0x00, 0xFF, 0x00, 0xFE, 0x01, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManRightMask1.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x03, 0x7F, 0x00, 0xFF, 0x03, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManRightMask2.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // pacManRightMask3.png
  },
  {
    {0x88, 0x00, 0xDC, 0x01, 0xDE, 0x03, 0xDF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManUpMask0.png
    {0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x8F, 0x07, 0xDF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManUpMask1.png
    {0x88, 0x00, 0xDC, 0x01, 0xDE, 0x03, 0xDF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManUpMask2.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // pacManUpMask3.png
  },
  {
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xDF, 0x07, 0xDE, 0x03, 0xDC, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManDownMask0.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xDF, 0x07, 0x8F, 0x07, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManDownMask1.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xDF, 0x07, 0xDE, 0x03, 0xDC, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // pacManDownMask2.png
    {0xF8, 0x00, 0xFC, 0x01, 0xFE, 0x03, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 0x07, 0xFE, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // pacManDownMask3.png
  }
};

const uint8_t ptsBitmap[(40 * 16) / 8] PROGMEM = { // pts.png
  0x00, 0x10, 0x07, 0xCE, 0x39, 0x00, 0x98, 0x08, 0x92, 0x04, 0x06, 0x90,
  0x08, 0x8E, 0x18, 0x06, 0x90, 0x08, 0x82, 0x20, 0x00, 0x38, 0x07, 0x82,
  0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x06, 0x3C, 0x07, 0xCE, 0x39, 0x0F, 0x84, 0x08,
  0x92, 0x04, 0x0F, 0x9C, 0x08, 0x8E, 0x18, 0x06, 0xA0, 0x08, 0x82, 0x20,
  0x00, 0x1C, 0x07, 0x82, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t readyBitmap[(40 * 8) / 8] PROGMEM = { // ready.png
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x1F, 0xE7, 0x23, 0x73, 0x66, 0x83,
  0x6D, 0x27, 0x73, 0x66, 0xDF, 0x6C, 0xE6, 0x73, 0x1E, 0xC3, 0x6F, 0xC6,
  0x30, 0x36, 0xC3, 0x6C, 0xC3, 0x00, 0x76, 0xDF, 0xEC, 0xC3, 0x30, 0x00,
  0x00, 0x00, 0x00, 0x00
};

const uint8_t readyMaskBitmap[(40 * 8) / 8] PROGMEM = { // readyMask.png
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0xF7, 0xFF, 0xFF, 0xDF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF,
  0xFB, 0xFF, 0xFF, 0xFF, 0xE7, 0xB1, 0xFF, 0xFF, 0xFF, 0xE7, 0xF9, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF
};

const uint8_t tileBitmap[numberOfTiles][8] PROGMEM = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // tile00.png
  {0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, 0x00}, // tile01.png
  {0x00, 0x0C, 0x1E, 0x1E, 0x0C, 0x00, 0x00, 0x00}, // tile02.png
  {0x00, 0x38, 0x04, 0x32, 0x0A, 0x00, 0x00, 0x00}, // tile03.png
  {0x00, 0x07, 0x08, 0x13, 0x14, 0x00, 0x00, 0x00}, // tile04.png
  {0x14, 0x13, 0x08, 0x07, 0x00, 0x00, 0x00, 0x00}, // tile05.png
  {0x0A, 0x32, 0x04, 0x38, 0x00, 0x00, 0x00, 0x00}, // tile06.png
  {0x00, 0x3F, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00}, // tile07.png
  {0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00}, // tile08.png
  {0x14, 0x14, 0x14, 0x14, 0x14, 0x00, 0x00, 0x00}, // tile09.png
  {0x00, 0x3F, 0x00, 0x31, 0x0A, 0x00, 0x00, 0x00}, // tile10.png
  {0x14, 0x13, 0x10, 0x13, 0x14, 0x00, 0x00, 0x00}, // tile11.png
  {0x0A, 0x31, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00}, // tile12.png
  {0x14, 0x23, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00}, // tile13.png
  {0x0A, 0x32, 0x02, 0x32, 0x0A, 0x00, 0x00, 0x00}, // tile14.png
  {0x0A, 0x0A, 0x0A, 0x04, 0x00, 0x00, 0x00, 0x00}, // tile15.png
  {0x14, 0x14, 0x14, 0x08, 0x00, 0x00, 0x00, 0x00}, // tile16.png
  {0x00, 0x3C, 0x02, 0x3C, 0x00, 0x00, 0x00, 0x00}, // tile17.png
  {0x00, 0x04, 0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00}, // tile18.png
  {0x00, 0x08, 0x14, 0x14, 0x14, 0x00, 0x00, 0x00}, // tile19.png
  {0x00, 0x0F, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x00}, // tile20.png
  {0x00, 0x03, 0x3C, 0x03, 0x00, 0x00, 0x00, 0x00}, // tile21.png
  {0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00}, // tile22.png
  {0x00, 0x30, 0x0F, 0x30, 0x00, 0x00, 0x00, 0x00}  // tile23.png
};

const uint8_t titleBitmap[(128 * 32) / 8] PROGMEM = { // title.png
  0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x02, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
  0x00, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x1F, 0x01, 0x00, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x01, 0x80, 0x0C, 0x80, 0xBF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x6F, 0xFF, 0xFB, 0xFB, 0xAF, 0x03, 0x7C, 0x02,
  0x80, 0xEC, 0xBF, 0x5F, 0xFE, 0x07, 0xFF, 0xFF, 0x4F, 0xFE, 0xF5, 0xE5,
  0x0F, 0xFB, 0x7D, 0x02, 0x80, 0x2C, 0x00, 0x5F, 0xFD, 0x19, 0xF8, 0xFF,
  0x2F, 0xFC, 0xE2, 0xD5, 0x2F, 0x0A, 0x78, 0x02, 0x80, 0xAC, 0xFF, 0xAE,
  0xF9, 0xE6, 0xE7, 0xFF, 0xAF, 0x78, 0xE5, 0x9A, 0x2F, 0xE8, 0x73, 0x02,
  0x80, 0xAC, 0xFF, 0xAD, 0x79, 0xFB, 0xDF, 0xFF, 0xAF, 0xB1, 0xE6, 0x9A,
  0xAF, 0xE8, 0x73, 0x02, 0x80, 0xAC, 0xFF, 0xD3, 0x73, 0xFD, 0x9F, 0x01,
  0xAE, 0x43, 0x67, 0x3D, 0xAF, 0xE9, 0x73, 0x02, 0x80, 0xAC, 0xCF, 0xD3,
  0xB3, 0xFD, 0xCF, 0xFD, 0xAE, 0x87, 0x67, 0x3D, 0xAF, 0xEB, 0x73, 0x02,
  0x80, 0xAC, 0xCF, 0xE3, 0xA7, 0xFE, 0xE7, 0x01, 0xAC, 0xCF, 0xA7, 0x7E,
  0xAE, 0xE7, 0x73, 0x02, 0x80, 0xAC, 0xFF, 0xE2, 0xA7, 0xFE, 0xF3, 0xF9,
  0xA9, 0xFF, 0xA7, 0x7E, 0xAE, 0xEF, 0x73, 0x02, 0x80, 0xAC, 0xFF, 0x72,
  0x8E, 0xFE, 0xF9, 0xFB, 0xA9, 0xFF, 0x47, 0xE7, 0xAC, 0xFF, 0x73, 0x02,
  0x80, 0xAC, 0x7F, 0x73, 0x8E, 0xFE, 0xF1, 0x03, 0xA8, 0xFF, 0x47, 0xE7,
  0xAC, 0xFF, 0x73, 0x02, 0x80, 0xAC, 0x87, 0xF9, 0x9F, 0xFE, 0xEB, 0x07,
  0xA8, 0xFF, 0xA7, 0xFF, 0xA9, 0xFF, 0x73, 0x02, 0x80, 0xAC, 0xF7, 0xF8,
  0x9F, 0xFE, 0xD6, 0xFF, 0xAF, 0xFF, 0xA5, 0xFF, 0xA9, 0xFF, 0x72, 0x02,
  0x80, 0xAC, 0x17, 0xFC, 0x37, 0xFD, 0xAD, 0xFF, 0xAF, 0xFF, 0xC5, 0x7F,
  0xA3, 0xFF, 0x72, 0x02, 0x80, 0xAC, 0x17, 0xFC, 0x2F, 0xFD, 0x9B, 0xFF,
  0xAF, 0xFF, 0xC5, 0xFF, 0xA2, 0xFF, 0x72, 0x02, 0x80, 0x8C, 0x90, 0xFE,
  0x43, 0x7A, 0x9C, 0xFF, 0xAF, 0x3F, 0xE4, 0x3F, 0x84, 0x1F, 0x72, 0x02,
  0x80, 0xBC, 0x1F, 0xFE, 0x7F, 0xE4, 0x87, 0xFF, 0x8F, 0xFF, 0xE7, 0xFF,
  0x87, 0xFF, 0x73, 0x02, 0x80, 0x3C, 0x80, 0x00, 0x00, 0x00, 0xC0, 0xFF,
  0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x02, 0x80, 0x7C, 0x80, 0x01,
  0x00, 0x3C, 0xF0, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x02,
  0x00, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x3F, 0x01, 0x00, 0xF1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x01, 0x00, 0x02, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
  0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x02,
  0x20, 0x08, 0x40, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x2F, 0x00, 0x20, 0x18, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xDA, 0xAA, 0xC9, 0x0D, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xAA,
  0x2A, 0x4A, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xE0, 0xAA, 0xAE, 0xDB, 0x05, 0x00
};

class PacMan : public Game {
  private:
    static const byte numberOfRows = 27;
    static const byte numberOfColumns = 21;
    const byte initialWorld[numberOfRows][numberOfColumns] = {
      //0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
      { 3,  7,  7,  7,  7,  7,  7,  7,  7,  7, 10,  7,  7,  7,  7,  7,  7,  7,  7,  7,  4}, //  0
      { 8,  1,  1,  1,  1,  1,  1,  1,  1,  1,  8,  1,  1,  1,  1,  1,  1,  1,  1,  1,  9}, //  1
      { 8,  1,  3,  7,  4,  1,  3,  7,  4,  1,  8,  1,  3,  7,  4,  1,  3,  7,  4,  1,  9}, //  2
      { 8,  2,  8,  0,  9,  1,  8,  0,  9,  1,  8,  1,  8,  0,  9,  1,  8,  0,  9,  2,  9}, //  3
      { 8,  1,  6,  7,  5,  1,  6,  7,  5,  1, 15,  1,  6,  7,  5,  1,  6,  7,  5,  1,  9}, //  4
      { 8,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  9}, //  5
      { 8,  1,  3,  7,  4,  1, 18,  1,  3,  7,  7,  7,  4,  1, 19,  1,  3,  7,  4,  1,  9}, //  6
      { 8,  1,  6,  7,  5,  1,  8,  1,  6,  7, 10,  7,  5,  1,  9,  1,  6,  7,  5,  1,  9}, //  7
      { 8,  1,  1,  1,  1,  1,  8,  1,  1,  1,  8,  1,  1,  1,  9,  1,  1,  1,  1,  1,  9}, //  8
      { 6,  7,  7,  7,  4,  1, 14,  7, 20,  0, 15,  0, 17,  7, 11,  1,  3,  7,  7,  7,  5}, //  9
      { 0,  0,  0,  0,  9,  1,  8,  0,  0,  0,  0,  0,  0,  0,  9,  1,  8,  0,  0,  0,  0}, // 10
      { 0,  0,  0,  0,  9,  1,  8,  0,  3, 21, 22, 23,  4,  0,  9,  1,  8,  0,  0,  0,  0}, // 11
      {17,  7,  7,  7,  5,  1, 15,  0,  8,  0,  0,  0,  9,  0, 16,  1,  6,  7,  7,  7, 20}, // 12
      { 0,  0,  0,  0,  0,  1,  0,  0,  8,  0,  0,  0,  9,  0,  0,  1,  0,  0,  0,  0,  0}, // 13
      {17,  7,  7,  7,  4,  1, 18,  0,  6,  7,  7,  7,  5,  0, 19,  1,  3,  7,  7,  7, 20}, // 14
      { 0,  0,  0,  0,  9,  1,  8,  0,  0,  0,  0,  0,  0,  0,  9,  1,  8,  0,  0,  0,  0}, // 15
      { 0,  0,  0,  0,  9,  1,  8,  0,  3,  7,  7,  7,  4,  0,  9,  1,  8,  0,  0,  0,  0}, // 16
      { 3,  7,  7,  7,  5,  1, 15,  0,  6,  7, 10,  7,  5,  0, 16,  1,  6,  7,  7,  7,  4}, // 17
      { 8,  1,  1,  1,  1,  1,  1,  1,  1,  1,  8,  1,  1,  1,  1,  1,  1,  1,  1,  1,  9}, // 18
      { 8,  1, 17,  7,  4,  1, 17,  7, 20,  1, 15,  1, 17,  7, 20,  1,  3,  7, 20,  1,  9}, // 19
      { 8,  2,  1,  1,  9,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  8,  1,  1,  2,  9}, // 20
      {14,  7,  4,  1,  9,  1, 18,  1,  3,  7,  7,  7,  4,  1, 19,  1,  8,  1,  3,  7, 11}, // 21
      {14,  7,  5,  1, 16,  1,  8,  1,  6,  7, 10,  7,  5,  1,  9,  1, 15,  1,  6,  7, 11}, // 22
      { 8,  1,  1,  1,  1,  1,  8,  1,  1,  1,  8,  1,  1,  1,  9,  1,  1,  1,  1,  1,  9}, // 23
      { 8,  1, 17,  7,  7,  7, 12,  7, 20,  1, 15,  1, 17,  7, 13,  7,  7,  7, 20,  1,  9}, // 24
      { 8,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  9}, // 25
      { 6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  5}  // 26
    };

    typedef struct TileStruct {
      int row;
      int column;
    } Tile;

    typedef enum {
      SOUND_NONE,
      SOUND_EAT_DOT,
      SOUND_EAT_ITEM,
      SOUND_EAT_GHOST,
      SOUND_EAT_POWER_PELLET,
      SOUND_DIE,
      SOUND_DISAPPEAR,
      SOUND_VOLUME
    } SoundType;

    typedef enum {
      GAME_MODE_TITLE,
      GAME_MODE_READY,
      GAME_MODE_PLAY,
      GAME_MODE_DIE,
      GAME_MODE_SUCCESS,
      GAME_MODE_GAME_OVER
    } GameMode;

    typedef enum {
      TILE_TYPE_SPACE,
      TILE_TYPE_DOT,
      TILE_TYPE_POWER_PELLET,
      TILE_TYPE_DOOR = 22
    } TitleType;

    typedef enum {
      DIRECTION_NONE = -1,
      DIRECTION_LEFT,
      DIRECTION_RIGHT,
      DIRECTION_UP,
      DIRECTION_DOWN
    } MoveDirection;

    typedef enum {
      GHOST_STATE_WAIT,
      GHOST_STATE_GO,
      GHOST_STATE_RUN,
      GHOST_STATE_DIE
    } GhostState;

    typedef enum {
      ITEM_CHERRY,
      ITEM_STRAWBERRY,
      ITEM_ORANGE,
      ITEM_APPLE,
      ITEM_MELON,
      ITEM_GALAXIAN,
      ITEM_BELL,
      ITEM_KEY
    } ItemType;

    // game
    Point screenCenter;
    int gameMode;
    const float maxReadyTime = 5000.0f;
    float readyTime;
    Point readyPosition;
    const float gameNormalSpeed = 25.0f / 1000.0f;
    float gameSpeed;
    static const int numberOfLevels = 256;
    int level;
    float successTime;
    float gameOverTime;
    Point gameOverPosition;
    float titleTime;
    bool isAutoPlay;

    // score
    const Size numberSize = {5, 7};
    bool isAwardExtraLife;

    // item
    const Size itemSize = {11, 11};
    Tile itemTile;
    Point itemPosition;
    int itemIndex;
    String itemPointString;
    Size itemPointSize;
    Point itemPointPosition;
    float itemVisibledTime;
    const int itemPoint[numberOfItems] = {100, 300, 500, 700, 1000, 2000, 3000, 5000};
    static const int maxItems = 13;
    const int item[maxItems] = {
      ITEM_CHERRY,
      ITEM_STRAWBERRY,
      ITEM_ORANGE,
      ITEM_ORANGE,
      ITEM_APPLE,
      ITEM_APPLE,
      ITEM_MELON,
      ITEM_MELON,
      ITEM_GALAXIAN,
      ITEM_GALAXIAN,
      ITEM_BELL,
      ITEM_BELL,
      ITEM_KEY
    };

    // world
    const Size statusBarSize = {128, 0};
    const Size tileSize = {6, 5};
    const Size worldPixelSize = {tileSize.width * numberOfColumns, (tileSize.height * numberOfRows) + 1.0f};
    Point worldPosition;
    byte world[numberOfRows][numberOfColumns];
    float worldStartPosition;
    Tile availabledTile;
    const int directionOrderUpperLeft[numberOfDirections] = {DIRECTION_DOWN, DIRECTION_RIGHT, DIRECTION_UP, DIRECTION_LEFT};
    const int directionOrderUpperRight[numberOfDirections] = {DIRECTION_DOWN, DIRECTION_LEFT, DIRECTION_UP, DIRECTION_RIGHT};
    const int directionOrderLowerLeft[numberOfDirections] = {DIRECTION_UP, DIRECTION_RIGHT, DIRECTION_DOWN, DIRECTION_LEFT};
    const int directionOrderLowerRight[numberOfDirections] = {DIRECTION_UP, DIRECTION_LEFT, DIRECTION_DOWN, DIRECTION_RIGHT};

    // pac-man
    const Size pacManSize = {11, 11};
    Point pacManPosition;
    int pacManDirection;
    int pacManNextDirection;
    const float pacManAnimationSpeed = 15.0f / 1000.0f;
    float pacManFrame;
    bool isPacManStoped;
    Tile pacManTile;
    Tile pacManLastTile;
    static const byte startPacManLives = 3;
    byte numberOfPacManLives;
    bool isPacManVisibled;
    const float minPowerPelletTime = 3000.0f;
    float maxPowerPelletTime;
    float powerPelletTime;
    int dotCounter;
    int numberOfDots;
    float pacManDieTime;
    float pacManDieFrame;
    bool isPacManDisappeared;
    const float pacManMaxIncreseSpeed = 3.0f;
    float pacManIncreseSpeed;
    const float pacManMaxIncreseSpeedTime = 1000.0f;
    float pacManIncreseSpeedTime;

    // ghost
    const Size ghostSize = {11, 11};
    Point ghostPosition[numberOfGhosts];
    int ghostDirection[numberOfGhosts];
    int ghostNextDirection[numberOfGhosts];
    const float ghostAnimationSpeed = 9.0f / 1000.0f;
    float ghostFrame[numberOfGhosts];
    bool isGhostStoped[numberOfGhosts];
    Tile ghostTile[numberOfGhosts];
    Tile ghostLastTile[numberOfGhosts];
    bool isGhostVisibled[numberOfGhosts];
    float ghostWaitTime[numberOfGhosts];
    const float maxGhostRandomTime = 4000.0f;
    float ghostRandomTime[numberOfGhosts];
    bool isRandomGhostPath[numberOfGhosts];
    bool isRunaway[numberOfGhosts];
    int ghostState[numberOfGhosts];
    static const int ghostMaxPaths = numberOfRows * 2;
    Tile ghostPath[numberOfGhosts][ghostMaxPaths];
    int ghostNumberOfPaths[numberOfGhosts];
    int ghostCurrentPath[numberOfGhosts];
    bool isGhostEdible[numberOfGhosts];
    const int ghostEdiblePoint[numberOfGhosts] = {200, 400, 800, 1600};
    int ghostEdiblePointIndex;
    float ghostEdiblePointVisibledTime;
    String ghostEdiblePointString;
    Size ghostEdiblePointSize;
    Point ghostEdiblePointPosition;
    int ghostEdiblePointGhost;
    const Tile cornerTile[4] = {{1, 1}, {1, 19}, {25, 1}, {25, 19}}; // upper left, upper right, lower left, lower right

    void addDotCounter(int value);
    void addGhostPath(int i, Tile tile);
    void addScore(unsigned long value);
    void changeGameMode(int mode);
    void chasePacMan(int i);
    void eat(Tile tile);
    void eatGhost(int i);
    void eatPowerPellet();
    void exitAutoPlay();
    int getDirection(Tile fromTile, Tile toTile);
    Game::Point getPositionFromTile(Tile tilePos, Size size);
    PacMan::Tile getTileFromPosition(Point pos, Size size);
    void ghostDie(int i);
    void initGame();
    bool isCollideGhost(int i);
    bool isGhostPath(int i);
    bool isJustMoveToNewTile(Tile currentTile, Tile lastTile);
    bool isTileAvailabled(int direction, Tile tile, bool isDoorTileEnabled = true);
    bool isWallTile(Tile tile, bool isDoorTileEnabled = true);
    void newLevel();
    bool pathFinding(int i, Tile targetTile, bool isDoorTileEnabled = true);
    void playSound(int index);
    void pressButton();
    bool readGhostPath(int i);
    void renderEdibleGhost();
    void renderGhost();
    void renderHUD();
    void renderItem();
    void renderPacMan();
    void renderTitle();
    void renderWorld();
    void resetGame();
    void resetGhostPath(int i);
    void resetPacManIncreseSpeed();
    void restartLevel();
    bool randomGhostPath(int i);
    void scrollWorldToPacManPosition();
    void scrollWorldToPosition(float y);
    void setRandomGhostPath(int i, bool runaway);
    void spawnGhost(int i, Tile tile, int state, int direction, int waitTime = 0.0f);
    void updateGhost();
    void updatePacMan();
    void updateTitle();

  public:
    PacMan();
    bool isBackToMenuEnabled();
    void update();
    void render();
};
}

#endif
