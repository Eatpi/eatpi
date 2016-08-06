import RPi.GPIO as GPIO
from time import sleep
import time, datetime
import socket

#
GPIO.setmode(GPIO.BCM)
#
GPIO.setup(4, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(21, GPIO.OUT, initial=GPIO.LOW)

GPIO.output(21, 0)

# configure the socket servre connection
HOST = ''    		# The remote host
PORT = 5000             # The same port as used by the server
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


try:  
    while True:  
        
    	sleep(0.1)                  		# wait half a second  
        if GPIO.input(4):  
            	print "LED just about to switch on"  
           	GPIO.output(21, 1)         	# set GPIO24 to 1/GPIO.HIGH/True  
		# Now communicate with the socket server

		s.connect((HOST, PORT))
		msg = MSClick:
		s.sendall(msg)
		data = s.recv(1024)
		s.close()
		print 'Received', repr(data)
	
        else:           
            print "LED just about to switch off"  
            GPIO.output(21, 0)    		 # set GPIO24 to 0/GPIO.LOW/False

except KeyboardInterrupt:  			 # trap a CTRL+C keyboard interrupt  
    GPIO.cleanup()     




