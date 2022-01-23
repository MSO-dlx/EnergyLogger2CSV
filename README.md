# EnergyLogger2CSV

Top ENGLISH – 
DEUTSCH darunter

####################################################################
Copies the data of a Voltacraft EnergyLogger 3500 Data.bin file into a Data.csv file or into an Excel file.

Electro-Conrad sells an Energy Logger 3500 plug to monitor and log the power consumption of a device plugged in over time.  However there did not seem to be working analysis tools for the data logged to a SD card by minutes (voltage/current/power factor Phi).  The data are recorded in two file types (a) an INFO file of 1k and DATA files of 10k size. The EnergyLogger2CSV.exe copies single DATA files' data into comma separated data files.  The Excel files more comprehensively copies the data of the INFO file as well as the DATA files from a directory into a worksheet and adds a few charts for quick analysis.

Syntax to use with the .exe:  
EnergyLogger2CSV.exe SourceData.bin TargetData.csv

####################################################################

Electro-Conrad verkauft zwar einen Energy Logger 3500 Stecker, mit welchem der Stromverbrauch des eingesteckten Geräts überwacht und protokolliert werden kann. Doch wenn man nun wirklich die aufgezeichneten Daten von der SD-Karte lesen möchte, gab es anscheinend keine funktionierende Lösung. Die Daten werden in zwei Dateitypen aufgezeichnet: (a) eine INFO-Datei enthält eine Zusammenfassung, wohingegen (b) die DATEN-Dateien enthalten die minütlich aufgezeichneten Werte (Spannung, Strom, Phasenverschiebung). Mit der .exe-Datei können nun die Daten einzelner DATEN-Dateien in kommagetrennte Datendateien kopiert (ausgelesen) werden. Mit der Excel-Datei können dagegen umfassender sowohl die Infodatei als auch die Datendateien eingelesen werden. Für einen schnellen Überblick werden noch ein paar Datendiagramme eingefügt.

Aufruf zum Auslesen mit der .exe-Datei:  
EnergyLogger2CSV.exe Quelldaten.bin Zieldaten.csv

