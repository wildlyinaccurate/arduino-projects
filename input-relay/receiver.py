import json
import serial

s = serial.Serial('/dev/ttyACM0', 9600)

while True:
    line = s.readline().decode('utf-8')

    try:
        data = json.loads(line)
        print(data)
    except json.decoder.JSONDecodeError:
        print('Invalid JSON received. Waiting for next message.')
