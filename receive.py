import serial
import socket

UDP_IP = "127.0.0.1"
UDP_PORT = 10015

sock = socket.socket(socket.AF_INET,  # Internet
                     socket.SOCK_DGRAM)  # UDP

while 1:
    with serial.Serial('/dev/ttyACM0', 115200, timeout=0.5) as ser:
        message = ser.readline()
        # sock.sendto(message, (UDP_IP, UDP_PORT))
        print(message)
