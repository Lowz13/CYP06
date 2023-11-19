/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	(c) Ponga su nombre y numero de cuenta aqui.
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.
	
******************************************************************************************************************/
#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#define dep 1
//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario	
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void	Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos)
{
	char compa[200][TAMTOKEN];
	char inter[200];//intermediario de la linea
	char linea[4000];//captura el archivo
	iNumElementos = 0;//numero de palabras en el archivo
	int i = 0, indi, aux, j, k; //acumulador, indice de linea, auxiliar de i
	FILE* fpDicc;//abrir archivo
	if (dep == 1)
		printf("\n%s", szNombre);
	fopen_s(&fpDicc, szNombre, "r");
	if (fpDicc != NULL)
	{
		if (dep == 1)
			printf("\nsi abre\n");
		while (!feof(fpDicc))
		{
			fgets(linea, sizeof(linea), fpDicc);//capturar linea de archivo
			if (dep == 1)
				printf("%s\n", linea);
			_strlwr_s(linea, sizeof(linea));//convertir en minusculas
			if (dep == 1)
				printf("%s\n", linea);
			indi = 0;
			while (linea[i] != '\0')
			{
				aux = i;
				if (linea[i] != ' ' && linea[i] != ',' && linea[i] != '.' && linea[i] != ';' && linea[i] != ':' && linea[i] != '(' && linea[i] != ')')
				{
					inter[indi] = linea[i];
					indi++;
				}
				else
				{
					if (linea[aux + 1] == '\0')
					{
						inter[indi] = '\0';
						strcpy_s(compa[iNumElementos], TAMTOKEN, inter);
						strcpy_s(szPalabras[iNumElementos], TAMTOKEN, inter);
						iNumElementos++;
						if (dep == 1) {}
						printf("%i: %s\n", iNumElementos, inter);
					}
					if (linea[i] == ' ')
					{
						if (linea[aux + 1] == ' ')
						{
							inter[indi] = '\0';
						}
						else
						{
							inter[indi] = '\0';
							strcpy_s(compa[iNumElementos], TAMTOKEN, inter);
							strcpy_s(szPalabras[iNumElementos], TAMTOKEN, inter);
							iEstadisticas[iNumElementos] = 1;
							iNumElementos++;
							if (dep == 1)
								printf("%i: %s\n", iNumElementos, inter);
							indi = 0;
						}
					}
					else
					{
						inter[indi] = '\0';
					}
				}
				i++;
			}

			for (j = 0; j < iNumElementos; j++)
			{
				for (k = 0; k < iNumElementos; k++)
				{
					if (j!=k)
					{
						if (strcmp(szPalabras[k], compa[j]) == 0)
						{
							printf("\nhay coincidencias\n");
							szPalabras[j][0]= '\0';
							iEstadisticas[k]++;
							iEstadisticas[j] = '\0';
						}
					}
				}
			}
			
		}	fclose(fpDicc);
	}
	else 
	{
		if (dep == 1)
		{
			printf("\nno abre\n");
		}
	}
}

/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/
void	ListaCandidatas		(
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
{

	//Sustituya estas lineas por su código
	strcpy(szListaFinal[0], szPalabrasSugeridas[ 0] ); //la palabra candidata
	iPeso[0] = iEstadisticas[0];			// el peso de la palabra candidata
	
	iNumLista = 1;							//Una sola palabra candidata
}

/*****************************************************************************************************************
	ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/
void	ClonaPalabras(
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
{
	//Sustituya estas lineas por su código
	strcpy(szPalabrasSugeridas[0], szPalabraLeida); //lo que sea que se capture, es sugerencia
	iNumSugeridas = 1;							//Una sola palabra sugerida
}
