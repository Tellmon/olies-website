import audinoRead
import pyautogui

audinoRead.findAurdino()

while(True):
    data = audinoRead.getData()

    if(data == "None"):
        print("No input")

    else:
        if(" " in data):
            yAxis = data[0]
            xAxis = data[2]

        for i in data:

            if(i == "L"):
                pyautogui.press("left")

            if(i == "U"):
                pyautogui.press("up")

            if(i == "D"):
                pyautogui.press("down")

            if(i == "R"):    
                pyautogui.press("right")

            if(i == " "):
                pyautogui.press("space")