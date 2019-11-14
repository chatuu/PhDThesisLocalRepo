#!/bin/bash

g++ `root-config --cflags --glibs` -g createHistograms.C -o createHistograms
