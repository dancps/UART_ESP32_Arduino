import serial

ser = serial.Serial('COM3',115200)  # open serial port
print(ser.name)         # check which port was really used

print("Escrevendo dados...\n")
outputFile = open("./dados.txt","w")

for i in range(0,10):
    x = ser.readline() # Le a linha da porta serial
    print(x) ,
    outputFile.write(x)

outputFile.close()

print("\nLendo dados...\n")
inputFile = open("./dados.txt","r")
print(inputFile.read())
inputFile.close()