#!/bin/bash

g++ `root-config --cflags --glibs` cleanFile.C -o cleanFile
