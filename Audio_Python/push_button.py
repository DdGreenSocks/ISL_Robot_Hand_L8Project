import RPi.GPIO as GPIO # Import Raspberry Pi GPIO library
import time 

GPIO.setwarnings(False) # Ignore warning for now
GPIO.setmode(GPIO.BOARD) # Use physical pin numbering
print("HELLO")

button_pin = 10

GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN) # Set pin 10 to be an input pin and set initial value to be pulled low (off)

debounce_delay = 0.05

last_button_state = GPIO.input(button_pin)


def button_press():
	global last_button_state
	current_button_state= GPIO.input(button_pin)
	print("Current button state:", current_button_state)
	print("Last button state:", last_button_state)
	
	if current_button_state != last_button_state:
		last_button_state = current_button_state
		if current_button_state == GPIO.HIGH:
			print("Button Pressed")
			#time.sleep(0.3)
	last_button_state=0
		
			
	
#GPIO.add_event_detect(button_pin, GPIO.RISING, callback=button_press, bouncetime=200)
	
try:
	while True: # Run forever
	
		if GPIO.input(10) == GPIO.HIGH:
			button_press()
			
			#print("Button was pushed!")
		
		time.sleep(0.1)

except KeyboardInterrupt:
	GPIO.cleanup()
