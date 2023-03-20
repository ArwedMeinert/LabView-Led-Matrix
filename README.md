# LabView-Led-Matrix
The project I did for my LabView course in university displays the current humidity and temperature and shows both stats over time. The temperature and humidity get measured by a sensor connected to the Arduino and get send via the serial connection to the LabView program running on a PC. The LabView program calculates the pixels that need to be switched on as well as the colour and sends this data back to the Arduino. There, the LED-Matrix gets displayed.
All documentation is in German.

This is the prototyping phase of the project. All necessary components are placed on the breadboard and are wired up. 

<img src="https://github.com/ArwedMeinert/LabView-Led-Matrix/blob/main/Pictures/IMG_20220116_170250_511%20-%20Kopie.jpg" alt="Prototyping" width="50%" height="50%">

After Collecting multiple points of humidity and temperature data, a spline interpolation is used to display the temperature and humidity with a width of 10 pixels on the matrix. The lowest temperature is visualised in a yellow colour, the maximal temperature is displayed in red. 

<img src="https://github.com/ArwedMeinert/LabView-Led-Matrix/blob/main/Pictures/IMG_20220116_142454_549%20-%20Kopie.jpg" alt="Display Temperature and Humidity graph" width="50%" height="50%">

The current temperature (yellow, 20°) and humidity (blue, 63%) are displayed on the display. The colour gets scaled by the maximum and minimum colour measured in the measurement series.

<img src="https://github.com/ArwedMeinert/LabView-Led-Matrix/blob/main/Pictures/IMG_20220116_141949_867%20-%20Kopie.jpg" alt="Display Temperature and Humidity graph" width="50%" height="50%">

Of cause, the actual use case is a little gimmicky. The graph doesn't show the absolute values only relative values. Also, ten pixels are a bit few. The same goes for the current temperature. One needs to know how the numbers are displayed to be able to read them. 
