Initial work has begun on an attempt at a Verilog implementation of the BJX1 ISA.

Minor ISA tweaks may be made in an attempt to make it implementable, and an effort may be made to keep this documented, and to keep the implementation consistent.

I may also include a partial rework of my prior VM (SHx Emu), and a goal will try to get them to have consistent behavior.
* Split MMIO/Hardware abstractions from the VM Core.
* Cleanup the code.
* Hopefully fix some things to improve VM performance.
* Try to keep behavior relatively consistent between the Emu and the Core.
* ...

Additionally, another Emu may exist based on plugging a Verilog-based simulation into the VM hardware. This is more intended for debugging than for performance.


Another project goal will to include a C compiler for the ISA, and a simplistic OS.
* Goal would be to have a relatively simplistic Unix-style OS or RTOS.


Predecessor [BGBTech SHx Emulator](https://github.com/cr88192/bgbtech_shxemu)
* This project will attempt to be its own thing, but builds on this.
