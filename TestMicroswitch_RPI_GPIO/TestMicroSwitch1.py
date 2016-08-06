import RPi.GPIO as GPIO
from time import sleep
GPIO.setmode(GPIO.BCM)
GPIO.setup(4, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(21, GPIO.OUT, initial=GPIO.LOW)

GPIO.output(21, 0)

try:  
    while True:  
        
        sleep(0.1)                 # wait half a second  
        if GPIO.input(4):  
            print "LED just about to switch on"  
            GPIO.output(21, 1)         # set GPIO24 to 1/GPIO.HIGH/True  
        else:           
            print "LED just about to switch off"  
            GPIO.output(21, 0)     # set GPIO24 to 0/GPIO.LOW/False
except KeyboardInterrupt:          # trap a CTRL+C keyboard interrupt  
    GPIO.cleanup()     




