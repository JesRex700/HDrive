This library is meant to make extra easy the use of some of the most popular motor drivers for arduino and other microcontrolllers,
it has every function that they have built in, at only one code line away, also being capable of controlling speed using up to two
PWM chanels in this version; Iy also features an emergency brake function, by sending a double HIGH signaln to the driver, not all
drivers support this so use it at your own risk.
As a note, it is a necesity to calrify that in this 1.0.0 relase is necesary to put an int value in all the five movement functions
to prevent an error to ocour, even if you are not using pwm. This will be revised an posibly fixed in future updates
