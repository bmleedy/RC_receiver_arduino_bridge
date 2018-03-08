import serial
import io

ser = serial.Serial('/dev/tty.SLAB_USBtoUART', 9600, timeout=1)

while True:
  line = ser.readline()
  values = line.split(",")


  fields = []
  for value in values:
    fields.append(int(value))


  # Just output the values for debug purposes
  if len(fields) > 4:
    print "Time(ms): ", repr(fields[0]).ljust(10), repr(fields[1]).rjust(5), repr(fields[2]).rjust(5), repr(fields[3]).rjust(5),repr(fields[4]).rjust(5)

