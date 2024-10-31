from pyfirmata import Arduino

#porque o arduino está conectado
PORTA=""

arduino=Arduino(PORTA)

#pinos conectados
#pino digital
led = arduino.get_pin("d:12:o")
#pino analógico A0
sensor_luz=arduino.get_pin("a:0:i")
while True:
    valorldr = sensor_luz.read()  
    valorldr = int(valorldr * 1023)  # Converte para inteiro (0-1023)
    print(valorldr)  # Imprime o valor lido
    if (valorldr <= 500):
        led.write(1)
    else:
        led.write(0)

