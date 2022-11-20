# fujinet-config-adam

More documentation to be written as it takes shape.


This repo is named fujinet-config-adam but it is really the primary repo for the CONFIG application for every supported platform on FujiNet. 

In the beginning there was only Atari. And so the CONFIG application was just called fujinet-config. Then came the ADAM and now common strands for the platforms began to take shape in this repo. Apple II soon joined and benefited from the commonality here. Atari was still on it's own but it is currently in the middle of being brought back into this repo (summer of 2022) so there is again just one place for all CONFIGs going forward.

## What is CONFIG?
CONFIG is the primary management application for the FujiNet device. It manages the WIFI connections and credentials, the SD card if one is inserted into your FN, and it traverses the HOSTS for images to mount in the Virtual SLOTS. The main page of CONFIG is the familiar HOSTS and SLOTS view that greets most people at boot with a FN device active on their system. CONFIG also can copy images to and from the SD card and finally has a configuration screen that shows the current network configuration of the ESP32 on your local network.

The CONFIG application must be coded and compiled to build a native binary application for each host platform. Then there are some scripts used to copy the CONFIG application to a bootable disk image for each platform. The process for those steps varies by platform. The final bootable disk image is then used in the main fujinet repo to flash the fs on the FN with the disk image, which is then loaded and mounted when you are booting the system without a virtual mounted disk.


## Screen Shots

### CONFIG on the ADAM
![ADAM CONFIG](./docs/images/fn_adam_config_v1.jpg)


### CONFIG on the AppleII
![Apple II CONFIG](./docs/images/fn_apple_config_v1.jpg)

### CONFIG on the Atari
![Atari CONFIG](./docs/images/fn_atari_config_v1.jpg)

* Note that the Atari screenshot above is from the classic CONFIG.


## Compiling on the Atari
To compile, currently requires:

* dir2atr - https://www.horus.com/~hias/atari/atarisio/atarisio-221009.tar.gz
  * download, build and install on your local build system

* https://github.com/FujiNetWIFI/fujinet-config-tools
  ** clone that repo and then do a `make dist` in order to get the ftools built for atari
  ** these are copied over to the FujiNet Atari Boot Disk to have available from DOS if needed


Now with those prerequisites out of the way:

$ make -f Makefile.atari clean dist

Check for any errors. If sucessful there will be an 

```
created image "autorun.atr"
```

copy autorun.atr to ~//fujinet-platformio/data/BUILD_ATARI/ and then using PIO (Platform IO) build  
"Build Filesystem Image" 
Then use "Upload Filesystem Image" to load the new image onto the FujiNet. Your new CONFIG should be ready to use.



## Compiling on the ADAM
To compile, currently requires:

* make
* Z88DK (http://github.com/z88dk/z88dk)
* eoslib (http://github.com/tschak909/eoslib)
* smartkeyslib (http://github.com/tschak909/smartkeyslib)

Make using 'make -f <file>'
  where file is Makefile.<platform>
