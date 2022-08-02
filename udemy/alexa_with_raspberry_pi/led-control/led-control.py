# Led control using raspberry and alexa
# Robert Tartarotti, 2022-08-02

from flask import Flask, render_template
from flask_ask import Ask, statement, question
import RPi.GPIO as GPIO


LED_PIN = 17
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.output(LED_PIN, GPIO.LOW)
app = Flask(__name__)
ask = Ask(app, "/")



def power_led(action):
    if action:
        GPIO.output(LED_PIN, GPIO.HIGH)
    else:
        GPIO.output(LED_PIN, GPIO.LOW)


@ask.launch
def launch():
    return question(render_template("welcome_text"))

@ask.intent("AMAZON.FallbackIntent")
def fallback():
    return question(render_template("command_reprompt"))

@ask.intent("OnOffIntent")
def control(on_off):
    print(on_off)
    if on_off is None or on_off not in ("on", "off"):
        # No command was given
        return question(render_template("command_reprompt"))
    elif on_off == "on":
        power_led(True)
    else:
        power_led(False)
    response_text = render_template("hello", onOffCommand=on_off)
    return statement(response_text).simple_card("Hello", response_text)

if __name__ == "__main__":
    app.run(debug=True)