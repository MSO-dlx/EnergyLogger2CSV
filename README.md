# EnergyLogger2CSV

Top ENGLISH – 
DEUTSCH darunter

Voltcraft Energy Logger 4000 (and 3500 ?) binary files decoder
similar to https://github.com/cvermot/QEnergyLoggerDecoder

####################################################################

This solution copies the data of a Voltcraft EnergyLogger 3500 Data.bin file into a Data.csv file or into an Excel file.

Electro-Conrad sells an Energy Logger 3500/4000 plug to monitor and log the power consumption of a device plugged in over time.  However there did not seem to be satisfactory analysis software for the data logged to a SD card by minutes (voltage/current/power factor Phi).  The logger records data in two file types (a) a summary INFO file of 1k and (b) DATA files of 10k size with data sets recorded every minute. 

– This project's EnergyLogger2CSV.exe copies single DATA files' data into comma separated data files.  
– The Excel files more comprehensively copies the data of the INFO file as well as the DATA files from a directory into a worksheet and adds a few charts for quick analysis.  It also logs the readout process and the data can be written into a .csv file, too. 

Syntax to use with the .exe:  
EnergyLogger2CSV.exe SourceData.bin TargetData.csv

####################################################################

Electro-Conrad verkauft zwar einen Voltcraft Energy Logger 3500/4000 Stecker, mit welchem der Stromverbrauch des eingesteckten Geräts überwacht und protokolliert werden kann. Doch wenn man nun wirklich die aufgezeichneten Daten von der SD-Karte lesen möchte, gab es anscheinend keine fähige Software-Lösung. Die Daten werden in zwei Dateitypen aufgezeichnet: (a) eine INFO-Datei enthält eine Zusammenfassung, wohingegen (b) die DATEN-Dateien enthalten die minütlich aufgezeichneten Werte (Spannung, Strom, Phasenverschiebung). 

– Mit der .exe-Datei in diesem Projekt können nun die Daten einzelner DATEN-Dateien in kommagetrennte Datendateien kopiert (ausgelesen) werden. 

– Mit der Excel-Datei können dagegen umfassender sowohl die Infodatei als auch die Datendateien eingelesen werden. Für einen schnellen Überblick werden noch ein paar Datendiagramme eingefügt. Es wird ein Ausleseprotokoll angefertigt und die Logger-Daten können auch nur in eine .csv geschrieben werden. 

Aufruf zum Auslesen mit der .exe-Datei:  
EnergyLogger2CSV.exe Quelldaten.bin Zieldaten.csv

