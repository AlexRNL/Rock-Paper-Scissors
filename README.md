# Rock-Paper-Scissors

Simple rock paper scissors game in a shell.

## Description

Play in a shell against the computer at the famous game "rock-paper-scissors".

## Rules

When starting, choose a number of rounds needed to win the game.

For each round, press the first letter (in french!) of each element to select it:
* `c` for scissors
* `p` for rock
* `f` for paper

As per standard rules, the rock beats the scissors, the scissors beat the paper,
and the paper beat the rock. 

## How to build

This project can be build with CMake:
```shell
mkdir ci-build
cd ci-build
cmake .. && cmake --build . && make
```

## License
This project is under BSD 3-clause license.