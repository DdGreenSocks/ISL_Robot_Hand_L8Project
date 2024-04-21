import serial
import time

ser=serial.Serial('/dev/ttyACM0',9600) # '/dev/ttyAMA0 is Arduino COM Port
time.sleep(10) #Wait for Arduino to initialize


def send_command(command):
    ser.write(command.encode())
    print(f"Sent command: {command}")


if __name__ == "__main__":
    while True:
        action = input("Enter letter:").upper()
        send_command(action)
        if action == "CLOSE":
            print("Exiting...")
            break
ser.close()
