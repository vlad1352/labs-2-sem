#pragma once
#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 25;//размер карты высота
const int WIDTH_MAP = 57;//размер карты ширина 


sf::String TileMap[HEIGHT_MAP] = {
	"000000000000000000000000000000000000000000000000000000000",
	"0        s   s     s     s  f  s sssss s    s s         0",
	"0   f    s  s     sss    ss   ss s     s    s s     f   0",
	"0        sss     s   s   s s s s sss   ssssss ssss      0",
	"0        s  s   sssssss  s  s  s s     s    s s   s     0",
	"0        s   s s       s s     s sssss s    s ssss      0",
	"0                                                       0",
	"0   s                 s             s        ss         0",
	"0                                             s         0",
	"0                                                 s     0",
	"0  s                s   s   s                     ssss  0",
	"0                        s       000000000000           0",
	"0        s     s                 0               ss      0",
	"000000000000000000000            0                      0",
	"0          0                     0                s     0",
	"0     k    0             s   s   0  aA       s          0",
	"0          0       s             0                      0",
	"0          0                s    0  s                   0",
	"0     s    0                s    000000000000           0",
	"0                                                  s    0",
	"0                s                                      0",
	"0     s                                                 0",
	"0                                s                      0",
	"0                                                       0",
	"000000000000000000000000000000000000000000000000000000000",
}; 
