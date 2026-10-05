import serial
import serial.tools.list_ports
import time

arduino = None


def findAurdino(baud=9600):
    global arduino

    print("Looking for Arduino...")

    ports = serial.tools.list_ports.comports()

    for port in ports:
        print(f"Found {port.device}: {port.description}")

        description = port.description.lower()

        if (
            "arduino" in description
            or "ch340" in description
            or "usb serial" in description
        ):
            try:
                arduino = serial.Serial(
                    port.device,
                    baudrate=baud,
                    timeout=1
                )

                # Arduino resets when serial connection opens
                time.sleep(2)

                print(f"Connected to Arduino on {port.device}")
                return True

            except serial.SerialException as e:
                print(f"Couldn't open {port.device}: {e}")
                return False

    print("Arduino not found!")
    return False


def getData():
    global arduino

    if arduino is None:
        print("Arduino isn't connected!")
        return None

    try:
        return arduino.readline().decode("utf-8").strip()

    except serial.SerialException as e:
        print(f"Error reading Arduino: {e}")
        return None
