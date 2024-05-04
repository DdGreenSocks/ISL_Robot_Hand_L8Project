import serial  # Import the serial module for UART communication
import time    # Import the time module for delays

# Initialize the serial connection with the Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)  # '/dev/ttyACM0' is the Arduino COM Port
time.sleep(10)  # Wait for Arduino to initialize (adjust delay as needed)

# Function to send commands to the Arduino
def send_command(command):
    ser.write(command.encode())  # Send the command to the Arduino (encoded as bytes)
    print(f"Sent command: {command}")  # Print the sent command for debugging

if __name__ == "__main__":
    while True:
        action = input("Enter letter:").upper()  # Prompt user for input (convert to uppercase)
        send_command(action)  # Send the user input as a command to the Arduino

        # Check if the user wants to exit
        if action == "CLOSE":
            print("Exiting...")  # Print a message indicating program exit
            break  # Exit the loop and close the serial connection

ser.close()  # Close the serial connection
