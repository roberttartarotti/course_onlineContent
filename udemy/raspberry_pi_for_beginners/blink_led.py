# Robert Tartarotti, 2022-07-28
# Blink led


import RPi.GPIO as GPIO
import time
import sys

LED_PIN = 17


def blink_led():
    GPIO.setmode(GPIO.BCM)

    while True:
        GPIO.setup(LED_PIN, GPIO.OUT)
        GPIO.output(LED_PIN, GPIO.HIGH)
        time.sleep(1)
        GPIO.output(LED_PIN, GPIO.LOW)
        time.sleep(1)

def main():
    blink_led()

try:
    main()
except KeyboardInterrupt:
    GPIO.cleanup()
    print("")
    sys.exit(0)