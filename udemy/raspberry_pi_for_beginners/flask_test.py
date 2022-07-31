# Robert Tartarotti, 2022-07-30
# Test flask for web application

from flask import Flask
import RPi.GPIO as GPIO

BUTTON_PIN = 26
LED_PIN = (17, 27, 22)

app = Flask(__name__)


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


@app.route("/")
def index():
    return "Hello from Flask"


@app.route("/push-button")
def check_push_button_state():
    if detect_botton():
        return "Button is pressed"
    return "Button is not pressed"


@app.route("/led/<int:led_pin>/state/<int:led_State>")
def trigger_led(led_pin, led_State):
    if not led_pin in range(3):
        return "Wrong GPIO led id: " + str(led_pin)
    if led_State not in (0, 1):
        return "State must be 0 or 1"
    power_led(LED_PIN[led_pin], led_State)
    return "Ok"

def main():
    for id in range(3):
        power_led(LED_PIN[id], False)
    # Create some routes
    app.run(host = "0.0.0.0", port=8500)


try:
    main()
except KeyboardInterrupt:
    GPIO.cleanup()
    sys.exit(0)