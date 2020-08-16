#!/bin/bash

printf "\nCreating new directory under name: %s" $1
mkdir $1
cp *.h makeHistograms.cxx createHistograms.cxx ./$1
echo "g++ \$(root-config --cflags --glibs) -g createHistograms.cxx makeHistograms.cxx -o makeHistograms" > temp.sh
chmod +x temp.sh
mv temp.sh ./$1/make.sh
printf "\nDirectory %s is created Successfully..!" $1
cd ./$1

