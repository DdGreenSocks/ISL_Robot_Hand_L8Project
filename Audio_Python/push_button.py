import RPi.GPIO as GPIO  # Import Raspberry Pi GPIO library
import time

GPIO.setwarnings(False)  # Ignore warning for now
GPIO.setmode(GPIO.BOARD)  # Use physical pin numbering

button_pin = 10  # Define the pin number connected to the push button

GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)  # Set pin 10 as an input pin with pull-down resistor

debounce_delay = 0.05  # Define a debounce delay to handle button press events

last_button_state = GPIO.input(button_pin)  # Initialize the last button state

def button_press():
    global last_button_state  # Use the last_button_state variable from the outer scope
    current_button_state = GPIO.input(button_pin)  # Get the current button state
    print("Current button state:", current_button_state)
    print("Last button state:", last_button_state)

    # Check if the current button state is different from the last button state
    if current_button_state != last_button_state:
        last_button_state = current_button_state  # Update the last button state

        # Check if the button is pressed (high state)
        if current_button_state == GPIO.HIGH:
            print("Button Pressed")
            # Perform desired actions here when the button is pressed
            # For example, you can add code to start recording audio
            #time.sleep(0.3)  # Add a delay to handle button bounce

    last_button_state = 0  # Reset the last button state after processing the button press event

try:
    while True:  # Run forever
        # Check if the button is pressed (high state)
        if GPIO.input(10) == GPIO.HIGH:
            button_press()  # Call the button_press function
            print("Button was pushed!")  # Debugging message

        time.sleep(0.1)  # Add a short delay to reduce CPU usage

except KeyboardInterrupt:
    GPIO.cleanup()  # Clean up GPIO resources upon keyboard interrupt
