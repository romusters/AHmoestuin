from time import sleep
import serial
import os


def main():
	ser = serial.Serial('/dev/ttyACM0', 9600) # Establish the connection on a specific port

	print "test"
	while True:
		value = ser.readline()[0:3] # Read the newest output from the Arduino
		sleep(.1) # Delay for one tenth of a second
		print value
		file(value)
		ssh()

def file(value):
	f = open('/home/cluster/Arduino/file.dat', 'w')
	f.write(value)
	f.close()

def ssh():
	import subprocess
	p = subprocess.Popen(["scp", '/home/cluster/Arduino/file.dat', 'user@ip:/file.dat'])
	sts = os.waitpid(p.pid, 0)


if __name__ ==  "__main__":
	main()
