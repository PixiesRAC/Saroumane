# RAC

Packet sniffer and attack encoder (arp spoof and so on)

First at all, you should use the script /script/sanityCheck.sh in order to verify the infrastructure of this project.

1: Create a directory named build at the root of the project

2: cd build && cmake .. && make

2 bis: (You can desactivate the filter mode in the file cmakeList.txt (replace the value ON by OFF and delete the cmakeCache) then do a cmake ..
again
3: YOU HAVE TO RUN THE PROGRAM IN SUDO MODE (sudo ./RacRenifleurDuXul - -e [ENCODER_MODE : ON] -s [SNIFFER_MODE : ON])

4: The log file are in log folder

5: You can change the configuration mode in the file RenifleurDuXul.json if the folder conf -for any help, take a look on the file conf.help)


