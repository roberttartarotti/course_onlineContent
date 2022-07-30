# Robert Tartarotti, 2022-07-29
# Power on the led with push botton

import RPi.GPIO as GPIO
import time
import sys

LED_PIN = 17
BUTTON_PIN = 26


def detect_botton():
    """ Detect botton """
    GPIO.setmode(GPIO.BCM)

    GPIO.setup(BUTTON_PIN, GPIO.IN)

    return GPIO.input(BUTTON_PIN)


def power_led():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(LED_PIN, GPIO.OUT)

    while True:
        time.sleep(0.01)
        if detect_botton():
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