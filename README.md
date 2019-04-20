# DbW-Tiva

University of Michigan - Dearborn

MDAS.ai with V2X for enhanced Safety

Capstone design 4/20/2019

This embedded software was created during capstone design for the MDAS.ai vehicle.

It is this Drive-by-Wire (DbW) software that allows the Drive PX2 to take control of the vehicle.

There are five major modules, this includes: Throttle, Steering, Brake & Radio module.

Each individual module provides control functionality of the vehicle as the name suggests.

i.e.) Throttle modules provides control to the throttle of the vehicle via Controller Area Network (CAN)

In the code, you will find the use of Sensors via ADC reads, control loops, fixed point math for scaling, 
I2C DACs to control throttle of the vehicle & CAN interconnection between the modules and actuators.

Feedback messages provide status of sensors for training information to train the neural network via CAN.

The use of V2X communications to simulate a pedestrian in the crosswalk. 

This was done using Dedicated Short Range Communication (DSRC - 5.9 GHz radio) and interfacing the radio 
via CAN to the throttle, steering and brake modules.

When a DSRC message is received a CAN message will generated & transmitted to the individual modules & when received will enter a DSRC mode disabling throttle, steering & brake
Until the pedestrian has finished crossing in the crosswalk.


Original Creators:

Athanasios Argyris,
Kayleigh James,
Sarah Overbeck,
Josh Quejadas.
