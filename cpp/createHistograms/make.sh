#!/bin/bash

#function setup_nova {
#  source /grid/fermiapp/nova/novaart/novasvn/setup/setup_nova.sh "$@" 
#  setup_fnal_security
#  cd /nova/app/users/ckuruppu
#}
#
#setup_nova -r S19-02-22 -b maxopt

#cd /nova/app/users/ckuruppu/workingThesis/cpp/createHistograms/

g++ `root-config --cflags --glibs` -g createHistograms.cxx makeHistograms.cxx -o createHistograms
