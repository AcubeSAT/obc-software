#!/bin/bash

if [ ! -z "$1" ]; then
  harmony_path="$1"
  if [ ! -d "$harmony_path" ]; then
      echo "Error: Directory '$harmony_path' not found"
      exit 1
  fi
elif [ -z "$1" ]; then
      echo "The harmony path is not given as argument to the script: $0"
      echo "The default path will be set as '~/Harmony3/mhc/'"
      harmony_path="$HOME/Harmony3/mhc"
      if [ ! -d $harmony_path ]; then
          echo "Error: The default path '$harmony_path' not found"
          exit 1
      fi
fi

path=$(pwd)
cd $path
mkdir firmware
shopt -s extglob
mv !(firmware) firmware/
cd "$harmony_path"
java -jar mhc.jar -mode=gui -fw=../ -c $path/firmware/src/config/default/default.mhc
cd $path
rm -rf cmake-build-debug
mv ./firmware/* ./
rm -rf firmware
rm ./src/config/default/startup_xc32.c