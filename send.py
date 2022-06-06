import serial
import socket
from cobs import cobs

UDP_IP = "127.0.0.1"
UDP_PORT = 10015
UDP_PORT2 = 10025

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))
sock2.bind((UDP_IP, UDP_PORT2))

baud_rate = 115200

with serial.Serial("/dev/ttyACM0", baud_rate, timeout=1) as ser:
    # Create TC[17,1] with ECSS Header.
    message = b"\x20\x11\x01\x01\x01\x00"
    m = [32, 17, 1, 1, 1, 0]
    # encoded_message = cobs.encode(bytearray(m))
    # encoded_message = cobs.encode(bytes(message))
    # data, addr = sock2.recvfrom(message)
    ser.write(message)

# todo: here perform the receiving of the TM message.
# while 1:
#     return_mess = ser.readline()
#     print(return_mess)
