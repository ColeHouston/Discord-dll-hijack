# Discord dll hijack
This repository contains the source code for a dll that proxies "ffmpeg.dll" to "payload.dll" and executes supplied shellcode.

## Usage
Replace the "x86_SHELLCODE_HERE" variable in main.cpp with some 32 bit shellcode. Discord is only available as a 32 bit application, so it is important that the shellcode is written accordingly.

Compile main.cpp to a dll named "ffmpeg.dll" and place it in the discord app directory with the real "ffmpeg.dll" (which must be renamed to "payload.dll").
