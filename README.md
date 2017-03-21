# Arduino Sonoff Dual

[![Build Status](https://travis-ci.org/marvinroger/arduino-sonoff-dual.svg?branch=master)](https://travis-ci.org/marvinroger/arduino-sonoff-dual)

This Arduino library provides helpers for a custom Sonoff Dual firmware

## Features

* Control the LED
* Control the relays
* Detect short press and long press of the hardware button

## Installation

1. Download the [latest version](https://github.com/marvinroger/arduino-sonoff-dual/archive/master.zip)
2. Load the `.zip` with **Sketch → Include Library → Add .ZIP Library**

## API

See examples folder for examples.

#### SonoffDualClass ()

Constructor. You don't have to instantiate an instance of the class, use the `SonoffDual` instance directly.

#### void .setup ()

Setup the Serial connection, turn the LED off and set both relays off.

#### SonoffDualButton .handleButton ()

Return `SonoffDualButton::NONE` if nothing happened, or `SonoffDualButton::SHORT` or `SonoffDualButton::LONG`.

#### void .setLed (bool `on`)

Set the state of the LED.

* **`on`**: should the LED be on?

#### bool .setRelays (bool `first`, bool `second`)

Set the state of the relays.

* **`first`**: should the first relay be on?
* **`second`**: should the second relay be on?
