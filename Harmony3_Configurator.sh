#!/bin/bash

path=$(pwd)
cd $path
mkdir firmware
shopt -s extglob
mv !(firmware) firmware/
mcc
wait
cd $path
rm -rf cmake-build-debug
mv ./firmware/* ./
rm -rf firmware
rm ./src/config/default/startup_xc32.c