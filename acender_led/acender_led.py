import pyfirmata

porta= 'COM3'

arduino=pyfirmata.Arduino(porta)
arduino.digital[2].mode=pyfirmata.OUTPUT

arduino.digital[2].write(1)
arduino.pass_time(2)
arduino.digital[2].write(0)
arduino.pass_time(2)