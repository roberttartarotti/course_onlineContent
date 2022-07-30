# Robert Tartarotti, 2022-07-29
# Detect push botton

import RPi.GPIO as GPIO
import time
import sys

BUTTON_PIN = 26

def detect_botton():
    """ Detect botton """
    GPIO.setmode(GPIO.BCM)

    GPIO.setup(BUTTON_PIN, GPIO.IN)

    print(GPIO.input(BUTTON_PIN))

    

def main():
    detect_botton()

try:
    main()
except KeyboardInterrupt:
    GPIO.cleanup()
    sys.exit(0)