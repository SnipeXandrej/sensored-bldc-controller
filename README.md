# Arduino-based Sensored BLDC Motor Controller
Motor controller for an E-Bike/Electric Pitbike that will use an alternator that's converted to a motor! (With hall sensors!)

This code is specifically made for the SparkFun Pro Micro board. <i>Does it matter though?</i>
<br>You might have to change a few things if you use a different board... <i>I think...</i>

I basically know <b>dogshit</b> about programming so this hot mess of code consists of about three different codebases that other people made for their own BLDC Motor Controllers. One worked (but had some flaws) and the other two that were made by using port manipulation just outright didn't, so I improvised....

For now it doesn't have any PWM and no speed adjustment (that's currently controlled by externally controlling the output MOSFETS with PWM), but I plan to try and make it adjustable by using a POT wired to the arduino soon™️.

# The wiring up
Hall sensor 1 goes to pin 1 (TX)
<br>Hall sensor 2 goes to pin 0 (RX)
<br>Hall sensor 3 goes to pin 2

<b>Phase 1</b>
<br>Low-side Mosfet goes to pin 10
<br>High-side Mosfet goes to pin 3
<br><b>Phase 2</b>
<br>Low-side &nbsp; Mosfet goes to pin 4
<br>High-side Mosfet goes to pin 5
<br><b>Phase 3</b>
<br>Low-side &nbsp; Mosfet goes to pin 6
<br>High-side Mosfet goes to pin 9

<b>There's 99% chance you will have to try swapping phases and/or Hall sensors.</b>


To be honest, I don't even know how I made all of this to work.
