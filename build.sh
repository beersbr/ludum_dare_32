#!/bin/bash

mv prefab bin/prefab.$(date +%s)
clang++ -std=c++11 -framework SDL2 -framework OpenGL -lglew main2.cpp -o Ldm32 -D DEBUG_BUILD=1