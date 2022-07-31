# Robert Tartarotti, 2022-07-29
# Detect push botton

import RPi.GPIO as GPIO
import time
import sys

BUTTON_PIN = 26

def detect_button():
    """ Detect button """
    GPIO.setmode(GPIO.BCM)

    GPIO.setup(BUTTON_PIN, GPIO.IN)

    print(GPIO.input(BUTTON_PIN))

    

def main():
    detect_button()

try:
    main()
except KeyboardInterrupt:
    GPIO.cleanup()
    sys.exit(0)