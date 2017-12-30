#!/bin/bash
verilator -Wall --cc FbNtMod.v --exe sim_fbtst0.cpp
make -C obj_dir -f VFbNtMod.mk
obj_dir/VFbNtMod ../DE3D0.tga
./compdec0 sim_fbtst0_pwm.dat
