#!/usr/bin/env python

from pyocd.core.helpers import ConnectHelper
from pyocd.flash.file_programmer import FileProgrammer
import argparse
import serial
import time
import sys

import logging
logging.basicConfig(level=logging.DEBUG)


"""
Code that flashes a .elf file to the target and then reads the serial port for the test results.
"""
if __name__ == '__main__':
    # Set-up argument parser
    parser = argparse.ArgumentParser(description='Perform Hardware-In-The-Loop Tests')
    parser.add_argument("--binary", '-b', type=str, help="Binary file to upload to the MCU")
    parser.add_argument("--serial_port", '-s', type=str, help="Serial port to read test result data")
    parser.add_argument('--baudrate', '-r', default=1000000)
    parser.add_argument("--unique-id", '-i', default=None)
    args = parser.parse_args()

    with ConnectHelper.session_with_chosen_probe(unique_id=args.unique_id) as session:
        board = session.board
        target = board.target

        # Reset
        target.reset_and_halt()

        if args.binary is not None:
            # Load firmware into device.
            flash = target.memory_map.get_boot_memory()
            FileProgrammer(session).program(args.binary)

        if args.serial_port is not None:
            # Connect to the device via serial
            return_value = 1
            with serial.Serial(args.serial_port, args.baudrate, rtscts=True) as ser:
                time.sleep(0.1)
                ser.reset_input_buffer()

                # Run the newly uploaded software
                target.resume()
                target.resume() # For some reason this needs to be executed twice, no idea why

                start_time = time.time()
                while time.time() - start_time < 60:  # Read for 1 minute
                    line = ser.readline()
                    sys.stdout.buffer.write(line)
                    sys.stdout.flush()

                    if line.startswith(b"@RETURN"):
                        return_value = int(line.split(b' ', 2)[1])
                        break

            exit(return_value)
