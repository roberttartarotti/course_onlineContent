# Robert Tartarotti, 2022-07-29
# Power on the led with push botton

import RPi.GPIO as GPIO
import time
import sys

LED_PIN = (17, 27, 22)
BUTTON_PREVIUS_STATUS = False
BUTTON_PIN = 26


def detect_botton():
    """ Detect botton """
    GPIO.setmode(GPIO.BCM)

    GPIO.setup(BUTTON_PIN, GPIO.IN)

    return GPIO.input(BUTTON_PIN)


def power_led(led_id, operation):
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(LED_PIN, GPIO.OUT)

    if operation:
        GPIO.output(led_id, GPIO.HIGH)
    else:
        GPIO.output(led_id, GPIO.LOW)


def main():
    global BUTTON_PREVIUS_STATUS
    led_id = 0
    power_led(LED_PIN[led_id], True)
    for id in range(3):
        power_led(LED_PIN[id], False)
    while True:
        time.sleep(0.01)
        det_botton = detect_botton()
        if  (det_botton != BUTTON_PREVIUS_STATUS):
            BUTTON_PREVIUS_STATUS = det_botton
            if det_botton:
                power_led(LED_PIN[led_id], False)
                led_id += 1
                if led_id == 3:
                    led_id = 0
                power_led(LED_PIN[led_id], True)


try:
    main()
except KeyboardInterrupt:
    GPIO.cleanup()
    print("")
    sys.exit(0)