#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  testsocketserver.py
#  
#  Copyright 2016  <pi@raspberrypi>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  



def main():
	import socket
	import sys
	HOST = ''
	PORT = 5000
	
	print 'Creating Socket'
	s = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
	print 'Socket Created'
	
	try:
		s.bind((HOST,PORT))
	except	socket.error, msg:
		print 'Bind failed. Error Code:' + str(msg[0]) + 'Message:' + msg[1]
		sys.exit
	print 'Socket bind complete.'
	
	s.listen(0)
	print 'Socket now listening.'
	while 1:
		conn, addr = s.accept()
		print 'Connected with ' + addr[0] + ':' + str(addr[1])
		
		data= conn.recv(1024)
		reply = 'OK...' + data
		print reply
		if not data:
			break
		conn.sendall(reply)	
		
	conn.close()
	s.close()
	
	return 0

if __name__ == '__main__':
	main()

