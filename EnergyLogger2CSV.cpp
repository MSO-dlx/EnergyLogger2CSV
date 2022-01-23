// Logger2CSV.cpp : Definiert den Einsprungpunkt für die Konsolenanwendung.													
// @2012 Christian Enders													
// reworked for Visual Studio 2019 by Volker Frank, service@MSO-dlx.com

// #pragma warning( disable : 4996 )
// #define _CRT_SECURE_NO_WARNINGS
//VF:
// #include "stdafx.h" // #include "stdafx.h" E1696 cannot open source file 
// https://docs.microsoft.com/en-us/answers/questions/357014/erroe-code-e1696-in-line-include-ltstdafxhgt.html
#include <stdio.h>
// VF: nicht benötigt using namespace std; // wenn benötigt, dann vor Ort in Funktion verwenden
#include <stdlib.h>													
#include <time.h>	

int main(int argc, char* argv[])
{
	FILE* infile, * outfile;
	unsigned char* buf;
	unsigned int readlen;
	unsigned int ret = 10;

	if (argc == 3)
	{
		infile = fopen(argv[1], "rb");
		if (infile)
		{
			buf = (unsigned char*)malloc(65536);
			if (buf != 0)
			{
				readlen = fread(buf, 1, 65536, infile);
				if (readlen > 0 && readlen != 102 && readlen < 65536)
				{
					outfile = fopen(argv[2], "a+t");
					if (outfile)
					{
						// column header rows
						// (seconds since 1900 dropped)
						fprintf(outfile, "Datum Zeit, Spannung, Strom, Phi \n");
						
						unsigned int pos = 0;
						float strom, spannung, pf;
						struct tm startzeit, * zeit;
						time_t sekunden = 0;

						while (pos < readlen)
						{
							if (buf[pos] == 0xff && buf[pos + 1] == 0xff && buf[pos + 2] == 0xff && buf[pos + 3] == 0xff)
								break;
							if (buf[pos] == 0xe0 && buf[pos + 1] == 0xc5 && buf[pos + 2] == 0xea)
							{
								// Startcode					
								pos += 3;
								startzeit.tm_mon = buf[pos++] - 1;
								startzeit.tm_mday = buf[pos++];
								startzeit.tm_year = 100 + buf[pos++];
								startzeit.tm_hour = buf[pos++];
								startzeit.tm_min = buf[pos++];
								startzeit.tm_sec = 0;
								startzeit.tm_isdst = 0;
								sekunden = mktime(&startzeit);
							}
							if (sekunden)
							{
								// Daten, wenn Datum gesetzt					
								spannung = (float)(buf[pos] * 256 + buf[pos + 1]) / 10;	// in 0.1V				
								strom = (float)(buf[pos + 2] * 256 + buf[pos + 3]) / 1000;	// in mA				
								pf = (float)buf[pos + 4] / 100;					// in %
								pos += 5;
								zeit = localtime(&sekunden);
								// fprintf(outfile, "%02d.%02d.%d %02d:%02d:00, %d, %.1f, %.3f, %.2f\n", zeit->tm_mday, zeit->tm_mon + 1, 1900 + zeit->tm_year, zeit->tm_hour, zeit->tm_min, sekunden, spannung, strom, pf);
								//VF: casting time_t to int
								//VF: why supply seconds (since 1900)?
								//fprintf(outfile, "%02d.%02d.%d %02d:%02d:00, %d, %.1f, %.3f, %.2f\n", zeit->tm_mday, zeit->tm_mon + 1, 1900 + zeit->tm_year, zeit->tm_hour, zeit->tm_min, static_cast<int>(sekunden), spannung, strom, pf);
								// (seconds since 1900 dropped)
								fprintf(outfile, "%02d.%02d.%d %02d:%02d:00, %.1f, %.3f, %.2f\n", zeit->tm_mday, zeit->tm_mon + 1, 1900 + zeit->tm_year, zeit->tm_hour, zeit->tm_min, spannung, strom, pf);
								sekunden += 60;
							}
							else
							{
								// sonst auf Startcode warten					
								pos++;
							}

						}
						ret = 0;
						fclose(outfile);
					}
					else printf("Kann Datei nicht öffnen: %s\n", argv[2]);
				}
				else printf("BIN-Datei zu gross oder zu klein.\n");

				free(buf);
			}
			else printf("Speichermangel!\n");
			fclose(infile);
		}
		else printf("Kann Datei nicht öffnen: %s\n", argv[1]);
	}
	else
	{
		printf("%s IN.bin OUT.csv\n", argv[0]);
	}
	return ret;
}