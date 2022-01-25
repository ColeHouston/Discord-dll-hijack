# Discord dll hijack
This repository contains the code to a dll that proxys "ffmpeg.dll" to "payload.dll" and executes supplied shellcode.
To make this attack work you must name the proxy dll "ffmpeg.dll" and place it in the discord directory with the real "ffmpeg.dll" (which must be renamed to "payload.dll").

