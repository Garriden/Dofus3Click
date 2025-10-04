


# Dofus3Click

A simple mechanical bot for Dofus 3



## Setup

Cmake with VSCode. Clang14

```bash
cmake -B build
```

## Documentation

Generate documentation executing this command. (Make sure you have Doxygen installed).

```bash
doxygen Doxyfile
```

## How to execute

After compile-building it

.exe located at: /build/bin/Dofus3Click.exe

Right Click -> Open as an administrator.

An external terminal would appear (Game support).


## How it is implemented

A quick look at how the code and the calls work:
 
![Main UML](images/mainClass.png)

Fight Class:

![Fight Class UML](images/FightClass.png)

If you want to know the strategy the PJ uses to figth:
Is still quite brute force, pending to improve it.

![Fight Class UML](images/FightStrategyClass.png)



## About

First version, on Dofus2: https://github.com/Garriden/Bots/tree/main/Dofus

Marc Garrido Casas. &copy; 2025. All rights reserved.
