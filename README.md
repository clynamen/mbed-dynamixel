# mbed-dynamixel
dynamixel motor control using mbed rtos

## Download and compile

```bash
git clone https://github.com/clynamen/mbed-dynamixel.git
cd mbed-dynamixel
git submodule init
git submodule update
# cd into the project-file of your mbed platform of choice. 
# new platform can be added using the export command, see 
# http://wiki.teamdiana.org/en/#!pages/mbed.md
http://wiki.teamdiana.org/en/#!pages/mbed.md
http://wiki.teamdiana.org/en/#!pages/mbed.md
cd projectfiles/gcc_arm_NUCLEO_F401RE
make
```

This will create a mbed_dynamixel.bin file, that can be directly flashed to an mbed platform
