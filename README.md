


# Dofus3Click

A simple mechanical bot for Dofus 3

This bot iterate through a Roadmap to recolect resources automatically while you are AFK.

It follows a .csv telemetry with the points where the resources are located. <br>
(You need it to introduce it manually, but you can record a telemetry with this program 1, 2)
 
<video controls width="50%" poster="assets/espantal_preview.png" autoplay muted>
    <source src="Videos/RecolectaFast.mp4" type="video/mp4">
    Your browser does not support the video tag. <a href="Videos/RecolectaFast.mp4">Download the video instead.</a>
</video>

<br>
<br>

When it encounters a resource protector it figths!

<video controls width="50%" poster="assets/espantal_preview.png" autoplay muted>
    <source src="Videos/EspantaLittle.mp4" type="video/mp4">
    Your browser does not support the video tag. <a href="Videos/EspantaLittle.mp4">Download the video instead.</a>
</video>

<br>
<br>

Log:

<img src="images/salviasLog.png" alt="Salvias Log" width="300" style="opacity:0.9;"/>

<br>
<br>

This bot also works for training. It iterates trough four maps finding the enemies on it and fighting them.

If your PJ dies, starts the roadmap again.

If your PJ dies and becomes a ghost, it goes to the closer fenix statue to resucitate and restart the roadmap.


<br>

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
