# Robert Tartarotti, 2022-07-28
# Power on and power off the led

import RPi.GPIO as GPIO
import time
import sys

LED_PIN = 17


def power_led():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(LED_PIN, GPIO.OUT)

    while True:
        state = input("Insert 1 to turn on and 0 to turn off the led: ")
        if state not in ("0", "1"):
            print("Invalid input parameter")
            continue
        if state == "1":
            GPIO.output(LED_PIN, GPIO.HIGH)
        else:
            GPIO.output(LED_PIN, GPIO.LOW)


def main():
    power_led()


try:
    main()
except KeyboardInterrupt:
    GPIO.cleanup()
    print("")
    sys.exit(0)